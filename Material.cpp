/*
 * Material.cpp
 *
 *  Created on: 27 déc. 2017
 *      Author: Ghassen_jlassi&Khalil_abid
 */

#include "Material.h"

Material::Material(){
	this->r_ = 0.0;
	this->g_ = 0.0;
	this->b_ = 0.0;
	this->shininess_ = 0.0;
}
Material::Material(float r, float g, float b, float s){
	this->r_ = r;
	this->g_ = g;
	this->b_ = b;
	this->shininess_ = s;
}
