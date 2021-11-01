/*
 * Camera.h
 *
 *  Created on: 27 déc. 2017
 *      Author: Ghassen_jlassi&Khalil_abid
 */

#ifndef CAMERA_H_
#define CAMERA_H_
#include "Vector3f.h"

class Camera {
private:
		Vector3f position_;
		Vector3f direction_;
public:
		Camera();
	    /**
		* @return Camera : New instance of Camera
		*/
		Camera(Vector3f position , Vector3f direction);
		/**
		* @return Vector3f : the position of the camera
		*/
		Vector3f getPosition() const { return position_; }
		/**
		* @return Vector3f : the direction of the camera
		*/
		Vector3f getDirection() const { return direction_; }
};

#endif /* CAMERA_H_ */
