/*
 * Ray3f.cpp
 *
 *  Created on: 27 d�c. 2017
 *      Author: Ghassen_jlassi&Khalil_abid
 */

#include "Ray3f.h"
Ray3f::Ray3f(){
	this->direction_ = Vector3f();
	this->origin_ = Vector3f(1,0,0);
	this->intersect_= 0;
}
Ray3f::Ray3f(Vector3f o, Vector3f d){
	this->origin_ = o;
	this->direction_ = d;
	this->intersect_= 0;
}
