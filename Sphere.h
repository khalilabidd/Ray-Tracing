/*
 * Sphere.h
 *
 *  Created on: 27 d�c. 2017
 *      Author: Ghassen_jlassi&Khalil_abid
 */

#ifndef SPHERE_H_
#define SPHERE_H_
#include "Shape.h"
#include "Vector3f.h"
class Sphere : public Shape { // @suppress("Class has a virtual method and non-virtual destructor")
public:
	Sphere();
	Sphere(Material m, Vector3f origin, float radius);

private:
	Vector3f origin_;
	float radius_;

public:
	Vector3f getOrigin() const { return origin_; }
	float getRadius() const { return radius_; }

	virtual bool is_hit(Ray3f &ray);
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
		Vector3f N = (position - origin_).normalize();
		return N;
	}
};

#endif /* SPHERE_H_ */
