/*
 * Shape.h
 *
 *  Created on: 27 d�c. 2017
 *      Author: Ghassen_jlassi&Khalil_abid
 */

#ifndef SHAPE_H_
#define SHAPE_H_

#include "Material.h"
#include "Ray3f.h"
class Shape { // @suppress("Class has a virtual method and non-virtual destructor")
protected:
		Material matter_;
public :
		virtual Material getMaterial() const{ return matter_; }
		/**
		* @brief Find if there's an intersection between an object and a ray
		*
		* @details Find if there's an intersection between an object and a ray and
		* give intersect of ray3f: the value of the  distance from ray's origin to the point of intersection
		* @param ray Ray3f
		* @return \e bool true if we have intersection
		*/
		virtual bool is_hit(Ray3f &ray) = 0;
		/**
		* @brief Give the reflection ray of another ray that hit an object
		* @details Give the reflection ray from the intersection position
		* @param ray Ray3f
		* @return \e Ray3f : the reflected ray
		*/
		virtual Ray3f reflect(Ray3f ray) = 0;
		/**
		* @brief Find the normal vector of an object
		* @details give the normal vector from a position
		* @param ray Vector3f
		* @return \e Vector3f: the normal vector
		*/
		virtual Vector3f getNormal(Vector3f position)=0;
		/**
		* @brief Find the intersection position between an object and a ray
		* @details give the intersection position if there's an intersection
		* return -1 if there's no intersection
		* @param ray Ray3f
		* @return \e double the distance from our ray origin to the point of intersection
		*  return -1 if there's no intersection
		*/
		virtual double Intersection(Ray3f ray)=0;
};

#endif /* SHAPE_H_ */
