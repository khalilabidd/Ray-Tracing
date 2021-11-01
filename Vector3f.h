/*
 * Vector3f.h
 *
 *  Created on: 27 déc. 2017
 *      Author: Ghassen_jlassi&Khalil_abid
 */


#ifndef VECTOR3F_H_
#define VECTOR3F_H_
#include <iostream>
#include <cmath>
class Vector3f {
private:
		float x_;
		float y_;
		float z_;
public:
		Vector3f();
	//	Vector3f(float n);
		Vector3f(float x, float y, float z);
		Vector3f(const Vector3f &v);
		float getX() const { return this->x_; }
		float getY() const { return this->y_; }
		float getZ() const { return this->z_; }
		void setX(float x) { this->x_ = x ; }
		void setY(float y) { this->y_ = y; }
		void setZ(float z) { this->z_ = z; }
		float length2() const { return x_ * x_ + y_ * y_ + z_ * z_; }
		float length() const { return sqrt(x_ * x_ + y_ * y_ + z_ * z_); }
		Vector3f normalize() {return Vector3f(x_ / length(), y_ / length(), z_ / length());}
		float dot(const Vector3f &v) const { return x_ * v.getX() + y_ * v.getY() + z_ * v.getZ(); }
		Vector3f crossProduct(Vector3f v) {
					return Vector3f(y_*v.getZ() - z_*v.getY(), z_*v.getX() - x_*v.getZ(), x_*v.getY() - y_*v.getX());
				}
		Vector3f operator + (const Vector3f &v) const {
			return Vector3f(this->x_+v.x_, this->y_+v.y_, this->z_+v.z_);
		}
		Vector3f operator - (const Vector3f &v) const {
			return Vector3f(this->x_-v.x_,this->y_-v.y_,this->z_-v.z_);
		}
		Vector3f operator -()const{
			return Vector3f(-(this->x_),-(this->y_),-(this->z_));
		}
		Vector3f operator * (const Vector3f &v) const {
			return Vector3f(this->x_*v.x_,this->y_*v.y_,this->z_*v.z_);
		}
		Vector3f operator * (float f) const {
			return Vector3f(this->x_*f,this->y_*f,this->z_*f);
		}
		friend Vector3f operator * (float val, const Vector3f &v);
		friend std::ostream & operator<<(std::ostream & std, const Vector3f & v);
};

#endif /* VECTOR3F_H_ */
