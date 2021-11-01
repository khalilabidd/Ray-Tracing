/*
 * Camera.cpp
 *
 *  Created on: 27 déc. 2017
 *      Author: Ghassen_jlassi&Khalil_abid
 */



#include "Camera.h"

Camera::Camera(){
	this->position_=Vector3f();
	this->direction_=Vector3f(0,0,1);
}
Camera::Camera(Vector3f p, Vector3f d){
	this->position_= p;
	this->direction_= d;
}

