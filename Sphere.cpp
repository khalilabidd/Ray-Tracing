/*
 * Sphere.cpp
 *
 *  Created on: 27 d�c. 2017
 *      Author: Ghassen_jlassi&Khalil_abid
 */

#include "Sphere.h"

Sphere::Sphere() {
	matter_ = Material();
	origin_ = Vector3f(0,0,0);
	radius_ = 1;
	}
Sphere::Sphere(Material m, Vector3f origin, float radius) {
		matter_ = m;
		origin_ = origin;
		radius_ = radius;
	}
bool Sphere::is_hit(Ray3f &ray) {
		Vector3f ray_origin = ray.getOrigin();
		double ray_origin_x = ray_origin.getX();
		double ray_origin_y = ray_origin.getY();
		double ray_origin_z = ray_origin.getZ();

		Vector3f ray_direction = ray.getDirection();
		double ray_direction_x = ray_direction.getX();
		double ray_direction_y = ray_direction.getY();
		double ray_direction_z = ray_direction.getZ();

		Vector3f sphere_center = origin_;
		double sphere_center_x = sphere_center.getX();
		double sphere_center_y = sphere_center.getY();
		double sphere_center_z = sphere_center.getZ();

		double b = (2 * (ray_origin_x - sphere_center_x)*ray_direction_x) + (2 * (ray_origin_y - sphere_center_y)*ray_direction_y) + (2 * (ray_origin_z - sphere_center_z)*ray_direction_z);
		double c = pow(ray_origin_x - sphere_center_x, 2) + pow(ray_origin_y - sphere_center_y, 2) + pow(ray_origin_z - sphere_center_z, 2) - (radius_*radius_);

		double delta = b*b - 4 * c;

		if (delta > 0) {
			double root_1 = ((-1 * b - sqrt(delta)) / 2) ;
			if ((ray.getIntersect()==0)||(ray.getIntersect()>root_1)){
				if (root_1 > 0) {
					ray.setIntersect(root_1);
				}
				else {
					double root_2 = ((sqrt(delta) - b) / 2);
					ray.setIntersect(root_2);
				}
				return true;
			}
			else {
				return false;
			}
		}
		else {
			return false;
		}
	}
double Sphere::Intersection(Ray3f ray) {
	Vector3f ray_origin = ray.getOrigin();
	double ray_origin_x = ray_origin.getX();
	double ray_origin_y = ray_origin.getY();
	double ray_origin_z = ray_origin.getZ();

	Vector3f ray_direction = ray.getDirection();
	double ray_direction_x = ray_direction.getX();
	double ray_direction_y = ray_direction.getY();
	double ray_direction_z = ray_direction.getZ();

	Vector3f sphere_center = origin_;
	double sphere_center_x = sphere_center.getX();
	double sphere_center_y = sphere_center.getY();
	double sphere_center_z = sphere_center.getZ();

	double b = (2 * (ray_origin_x - sphere_center_x)*ray_direction_x) + (2 * (ray_origin_y - sphere_center_y)*ray_direction_y) + (2 * (ray_origin_z - sphere_center_z)*ray_direction_z);
	double c = pow(ray_origin_x - sphere_center_x, 2) + pow(ray_origin_y - sphere_center_y, 2) + pow(ray_origin_z - sphere_center_z, 2) - (radius_*radius_);

	double delta = b*b - 4 * c;
	if (delta > 0) {

		double root_1 = ((-1 * b - sqrt(delta)) / 2) ;
			if (root_1 > 0) {
				return root_1;
			}
			else {
				double root_2 = ((sqrt(delta) - b) / 2);
				return root_2;
			}
		}
		else {
			return -1;
		}
	}
Ray3f Sphere::reflect(Ray3f ray) {
	Vector3f I = ray.getDirection();
	Vector3f pos = ray.getOrigin()+ray.getIntersect()*I;
	Vector3f N = getNormal(pos);
	Ray3f res =Ray3f(pos,I-2*I.dot(N)*N);
	return res;
	}
