/*
 * Scene.cpp
 *
 *  Created on: 27 d�c. 2017
 *      Author: Ghassen_jlassi&Khalil_abid
 */

#include "Scene.h"
	Scene::Scene(Camera c, vector<Shape*> shapes, Ray3f source) {
		camera_ = c;
		shapes_ = shapes;
		source_ = source;
	}

void Scene::save(const char *filename, int w, int h, int dpi, Material *couleur) {
	FILE *f;
	int k = h*w;
	int s = 4*k;
	int taille_fichier = 54 + s;
	double factor = 39.375;
	int m = static_cast<int>(factor);

	int ppm = dpi*m;
	unsigned char bmpfileheader [14] = {'B','M'};
	unsigned char bmpinfoheader [40] = {40,0,0,0, 0,0,0,0, 0,0,0,0, 1,0,24,0};

	bmpfileheader[2] = (unsigned char)(taille_fichier);
	bmpfileheader[3] = (unsigned char)(taille_fichier>>8);
	bmpfileheader[4] = (unsigned char)(taille_fichier>>16);
	bmpfileheader[5] = (unsigned char)(taille_fichier>>24);

	bmpinfoheader[4] = (unsigned char)(w);
	bmpinfoheader[5] = (unsigned char)(w>>8);
	bmpinfoheader[6] = (unsigned char)(w>>16);
	bmpinfoheader[7] = (unsigned char)(w>>24);
	bmpinfoheader[8] = (unsigned char)(h);
	bmpinfoheader[9] = (unsigned char)(h>>8);
	bmpinfoheader[10]= (unsigned char)(h>>16);
	bmpinfoheader[11]= (unsigned char)(h>>24);

	bmpinfoheader[21]= (unsigned char)(s);
	bmpinfoheader[22]= (unsigned char)(s>>8);
	bmpinfoheader[23]= (unsigned char)(s>>16);
	bmpinfoheader[24]= (unsigned char)(s>>24);

	bmpinfoheader[25]= (unsigned char)(ppm);
	bmpinfoheader[26]= (unsigned char)(ppm>>8);
	bmpinfoheader[27]= (unsigned char)(ppm>>16);
	bmpinfoheader[28]= (unsigned char)(ppm>>24);

	bmpinfoheader[29]= (unsigned char)(ppm);
	bmpinfoheader[30]= (unsigned char)(ppm>>8);
	bmpinfoheader[31]= (unsigned char)(ppm>>16);
	bmpinfoheader[32]= (unsigned char)(ppm>>24);

	f = fopen(filename,"wb");

	fwrite(bmpfileheader,1,14,f);
	fwrite(bmpinfoheader,1,40,f);

	for (int i = 0; i < k; i++){
		Material rgb = couleur[i];
		double red = (couleur[i].getRed())*255;
		double green = (couleur[i].getGreen())*255;
		double blue = (couleur[i].getBlue())*255;

		unsigned char color[3] = {(int)floor(blue),(int)floor(green),(int)floor(red)};
		fwrite(color,1,3,f);
	}
	fclose(f);
}

Scene::~Scene()
	{
		shapes_.clear();
	}

Material Scene::getColor(Ray3f ray,	int object_index)
{
		Vector3f intersection_position = ((ray.getIntersect()*ray.getDirection())+ray.getOrigin());
		Vector3f intersecting_ray_direction=ray.getDirection();
		double ambientlight = 0.2;
		Material object_color = shapes_.at(object_index)->getMaterial();
		Vector3f object_normal = shapes_.at(object_index)->getNormal(intersection_position);
		Material final_color = object_color.colorScalar(ambientlight);
		Vector3f light_direction = (source_.getOrigin() + (-intersection_position)).normalize();
		double cosine_angle = object_normal.dot(light_direction);
		if (cosine_angle > 0) {
			bool shadowed = false;
			Vector3f distance_to_light = (source_.getOrigin()+ (-intersection_position)).normalize();
			float distance_to_light_magnitude = distance_to_light.length2();

			Ray3f shadow_ray(intersection_position, (source_.getOrigin() + (-intersection_position)).normalize());
			vector<double> secondary_intersections;

			for (int index = 0; index < shapes_.size() && shadowed == false; index++) {
				secondary_intersections.push_back(shapes_.at(index)->Intersection(shadow_ray));
			}
			for (int c = 0; c < secondary_intersections.size(); c++) {
					if (secondary_intersections.at(c) >= distance_to_light_magnitude) {
						shadowed = true;
					}
				break;
			}
			if (shadowed == false) {
				final_color = final_color.colorAdd(object_color.colorScalar(cosine_angle));
				if (object_color.getShininess() > 0 && object_color.getShininess() <= 1) {
					double dot1 = object_normal.dot(-intersecting_ray_direction);
					Vector3f scalar1 = object_normal * dot1;
					Vector3f add1 = scalar1 + intersecting_ray_direction;
					Vector3f scalar2 = add1* 2;
					Vector3f add2 = (-intersecting_ray_direction) + scalar2;
					Vector3f reflection_direction = add2.normalize();

					double specular = reflection_direction.dot(light_direction);
					if (specular > 0) {
						specular = pow(specular, 10);
						final_color = final_color.colorAdd(Material(1,1,1,1).colorScalar(specular*object_color.getShininess()));
					}
				}

			}

		}

		return final_color.clip();
	}
	void Scene::render(int width, int height, char * filename)
		{
			int currentpixel;
			double aspectratio = (double)width / (double)height;
			int total = width * height;
			Material* pixels = new Material[total];

			double xamnt, yamnt;

			for (int x = 0; x < width; x++) {
				for (int y = 0; y < height; y++) {
					currentpixel = x + y * width;
					if (width > height) {
						// the image is wider than it is tall
						xamnt = ((x + 0.5) / width)*aspectratio - (((width - height) / (double)height) / 2);
						yamnt = ((height - y) + 0.5) / height;
					}
					else if (height > width) {
						// the image is taller than it is wide
						xamnt = (x + 0.5) / width;
						yamnt = (((height - y) + 0.5) / height) / aspectratio - (((height - width) / (double)width) / 2);
					}
					else {
						// the image is square
						xamnt = (x + 0.5) / width;
						yamnt = ((height - y) + 0.5) / height;
					}

					Vector3f cam_ray_origin = camera_.getPosition();
					Vector3f camright = Vector3f(0,1,0).crossProduct(camera_.getDirection()).normalize();
					Vector3f camdown = camright.crossProduct(camera_.getDirection());
					Vector3f cam_ray_direction = (camera_.getDirection() + ((camright * (xamnt - 0.5)) + (camdown * (yamnt - 0.5)))).normalize();
					Ray3f cam_ray(cam_ray_origin, cam_ray_direction);

					int object_index = -1;
					for (int index = 0; index < shapes_.size(); index++) {
						if (shapes_.at(index)->is_hit(cam_ray)){
							object_index=index;
						}
					}

					// determine which object is closer to the camera
					// return -1 or 0 or 1
					//The ray in this pixel either misses everything in the scene
					// or intersects with the first object in the scene
					// or it can intersect with the second object in the scene


					if (object_index == -1) {
						pixels[currentpixel].setRed(0);
						pixels[currentpixel].setGreen(0);
						pixels[currentpixel].setBlue(0);
					}
					else
					{
						/* Get the color at the specific XYZ coordinates of the intersection so instead of
						getting the color of the object and setting that color in the pixel  we are going to
						have to actually get the color of the intersection*/
							Material intersection_color = getColor(cam_ray, object_index);
							pixels[currentpixel].setRed(intersection_color.getRed());
							pixels[currentpixel].setGreen(intersection_color.getGreen());
							pixels[currentpixel].setBlue(intersection_color.getBlue());
					}

				}
			}
			int dpi=20;
			save(filename, width, height,dpi,pixels);
		}

