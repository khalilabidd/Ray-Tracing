/*
 * Material.h
 *
 *  Created on: 27 d�c. 2017
 *      Author: Ghassen_jlassi&Khalil_abid
 */
#ifndef MATERIAL_H_
#define MATERIAL_H_
class Material {


	private:
		float r_, g_,b_, shininess_;

	public:
		Material();
		/*
	     @brief Material Constructor
	     @params red quantity , green quantity , blue quantity , shininess value
		*/
		Material(float r, float g, float b, float s);
		/*
		@brief getter of our class
		*/
		float getRed() const { return this->r_; }
		float getGreen() const { return this->g_; }
		float getBlue() const { return this->b_; }
		float getShininess() const { return this->shininess_; }
		/*
		@brief setter of our class
	    */
		void setRed(double RValue) { r_ = RValue; }
		void setGreen(double GValue) { g_ = GValue; }
		void setBlue(double BValue) { b_ = BValue; }
		void setShininess(double SValue) { shininess_ = SValue; }
	public:
		/*
	     @brief multiply the color by a given value
		 @params double scalar
		*/
		Material colorScalar(double scalar) {
			return Material(r_*scalar, g_*scalar, b_*scalar, shininess_);
		}
		/*
		 @brief addition of two color
		 @params Material color
		*/
		Material colorAdd(Material color) {
			return Material(r_ + color.getRed(), g_ + color.getGreen(), b_ + color.getBlue(), shininess_);
		}
		/*
		 @brief adjust the color of the light
		 @return the adjusted material
		 */
		Material clip() {
			double alllight = r_ + g_ + b_;
			double excesslight = alllight - 3;
			if (excesslight > 0) {
				r_ = r_ + excesslight*(r_ / alllight);
				g_ = g_ + excesslight*(g_ / alllight);
				b_ = b_ + excesslight*(b_ / alllight);
			}
			if (r_ > 1) { r_ = 1; }
			if (g_ > 1) { g_ = 1; }
			if (b_ > 1) { b_ = 1; }
			if (r_ < 0) { r_ = 0; }
			if (g_ < 0) { g_ = 0; }
			if (b_ < 0) { b_ = 0; }

			return Material(r_, g_, b_, shininess_);
		}
};

#endif /* MATERIAL_H_ */
