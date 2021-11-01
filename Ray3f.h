/*
 * Ray3f.h
 *
 *  Created on: 27 d�c. 2017
 *      Author: Ghassen_jlassi&Khalil_abid
 */

#ifndef RAY3F_H_
#define RAY3F_H_
#include "Vector3f.h"

class Ray3f {
private :
	Vector3f origin_;
	Vector3f direction_;
	double intersect_;

public:
	Ray3f();
	/*
	@brief Ray3f Constructor
	 */
	Ray3f(Vector3f o, Vector3f d);
	/*
	@return the vector3f of the origin of the ray
	*/
	Vector3f getOrigin() const{ return this->origin_;}
	/*
	@return the vector3f of the direction of the ray
	*/
	Vector3f getDirection() const{ return this->direction_;}
	/*
	@return the intersection double
	*/
	double getIntersect() const{ return this->intersect_;}
	/*
	@brief Ray3f setter
	*/
	void setOrigin(Vector3f o) { this->origin_ = o ; }
	void setDirection(Vector3f d) { this->direction_ = d ; }
	void setIntersect(double i) { this->intersect_= i;}

};

#endif /* RAY3F_H_ */
