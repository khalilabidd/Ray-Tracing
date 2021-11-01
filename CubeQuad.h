/*
 * CubeQuad.h
 *
 *  Created on: 27 d�c. 2017
 *      Author: Ghassen_jlassi&Khalil_abid
 */
#ifndef CUBEQUAD_H_
#define CUBEQUAD_H_
#include "Shape.h"
#include "Vector3f.h"

class CubeQuad : public Shape{ // @suppress("Class has a virtual method and non-virtual destructor")
	public:
		CubeQuad();
		   /**
			* @return CubeQuad : New instance of CubeQuad
			*/
		CubeQuad(Material m, Vector3f origin, Vector3f width, Vector3f height);

	private:

		Vector3f origin_;
		Vector3f width_;
		Vector3f height_;
	public:
	   /**
		* @return Vector3f  : The origin of the cube quad
		*/
		Vector3f getOrigin() const { return origin_; }
		/**
		 * @return Vector3f : The Width of the Cube quad intercepted
		 */
		Vector3f getWidth() const { return width_; }
		/**
   	     * @return Vector3f : The Height of the Cube quad intercepted
		 */
		Vector3f getHeight() const { return height_; }

	public:
		/**
	    * @brief If the ray is hiting
	    * @param ray Ray3f
	    * @return the boolean which test if the ray is hiting or not
	    */
		virtual bool is_hit(Ray3f &ray);
		/**
	    * @brief Find the ray reflecting on the object
		* @details it manages vector to get the direction, the normal vector and the vector position to find
		* out the ray
		* @param ray Ray3f
		* @return \e the reflect ray
		*/
		virtual Ray3f reflect(Ray3f ray);
		/**
	    * @brief Find the intersection between an object and a ray
		* @details if the ray intersects an object in the scene, it will not be infinite in that direction
		* it's going to stop and terminate at the intersection point
		* @param ray Ray3f
		* @return \e double the distance from our ray origin to the point of intersection
		*/
		virtual double Intersection(Ray3f ray);
		virtual Vector3f getNormal(Vector3f position){
			Vector3f N =(width_.crossProduct(height_)).normalize();
			return N;
		}
};


#endif /* CUBEQUAD_H_ */
