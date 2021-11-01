/*
 * Vector3f.cpp
 *
 *  Created on: 27 déc. 2017
 *      Author: Ghassen_jlassi&Khalil_abid
 */

#include "Vector3f.h"

Vector3f::Vector3f() {
	x_ = 0;
	y_ = 0;
	z_ = 0;
}
Vector3f::Vector3f(float x, float y, float z) {
	x_ = x;
	y_ = y;
	z_ = z;
}
Vector3f::Vector3f(const Vector3f &v) {
	this->x_ = v.x_;
	this->y_ = v.y_;
	this->z_ = v.z_;
}
Vector3f operator * (float f, const Vector3f &v) {
	return Vector3f(v.getX()*f,v.getY()*f,v.getZ() *f);
}
std::ostream & operator<<(std::ostream & std,const Vector3f & v)
	{
		return std << "x= " << v.getX() << ", y: " << v.getY() << ", z: " << v.getZ() ;

	}

