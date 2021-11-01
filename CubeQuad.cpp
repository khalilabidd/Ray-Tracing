/*
 * CubeQuad.cpp
 *
 *  Created on: 27 d�c. 2017
 *      Author: Ghassen_jlassi&Khalil_abid
 */

#include "CubeQuad.h"


   CubeQuad::CubeQuad() {
		matter_ = Material();
		origin_ = Vector3f();
		width_ = Vector3f();
		height_ = Vector3f();
	}


	CubeQuad::CubeQuad(Material m, Vector3f origin, Vector3f width, Vector3f height) {
		matter_ = m;
		origin_ = origin;
		width_ = width;
		height_ = height;
	}

	bool CubeQuad::is_hit(Ray3f &ray) {
		Vector3f ray_origin = ray.getOrigin();
		Vector3f ray_direction = ray.getDirection();

		Vector3f center = origin_;
		Vector3f N =getNormal(origin_);
		double d=0;
		if (ray_direction.dot(N)!=0){
			d=(center-ray_origin).dot(N)/(ray_direction.dot(N));
		}
		if (((ray.getIntersect()==0)||(ray.getIntersect()>d))&&(d>0)){
			ray.setIntersect(d);
			return true;
		}
		else {
			return false;
		}
	}

	double CubeQuad::Intersection(Ray3f ray){
		Vector3f ray_origin = ray.getOrigin();
		Vector3f ray_direction = ray.getDirection();

		Vector3f center = origin_;
		Vector3f N =getNormal(origin_);
		double d=0;
		if (ray_direction.dot(N)!=0){
			d=(center-ray_origin).dot(N)/(ray_direction.dot(N));
		}
		return d;
	}
	Ray3f CubeQuad::reflect(Ray3f ray) {
			Vector3f I = ray.getDirection();
			Vector3f N = getNormal(origin_);
			Vector3f pos = ray.getOrigin()+ray.getIntersect()*I;
			Ray3f res =Ray3f(pos,I-2*I.dot(N)*N);
			return res;
		}
