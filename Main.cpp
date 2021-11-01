/*
 * Main.cpp
 *
 *  Created on: 31 déc. 2017
 *      Author: Ghassen_jlassi&Khalil_abid
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>
#include <limits>
#include "Ray3f.h"
#include "Camera.h"

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
using namespace std ;
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>
#include <limits>
#include <cstdlib>
#include <cstdio>
#include <ctime>

#include "Cubequad.h"
#include "sphere.h"
#include "scene.h"
/*
@brief This file contains the main functions of our project
*/
int main (int argc,  char *argv[]) {
	cout << "Loading ...." << endl;
	/*
	@brief define Camera position
	*/
	Vector3f campos(0,0,0);
	/*
	@brief define Camera direction
	*/
	Vector3f camdir(1,0,0);
	/*
	 @brief define the scene
	 */
	Camera scene_cam(campos, camdir);
	/*
	 @brief initialize the source
	 */
	Ray3f source(Vector3f(0,8,0),Vector3f(0,0,0));
	/*
     @brief Colors
	 */
	Material yellow(1.28,0.6,0, 0.3);
	Material gray(0.5, 0.5, 0.5, 0.0);
	Material pink(1.99, 0.21, 1.33, 0.2);
	Material white(1, 1, 1, 1);
	/*
     @brief initialize the "sphere"
    */
	Sphere scene_sphere1(yellow,Vector3f(20,1,0),2);
	Sphere scene_sphere2(pink, Vector3f(5,-1,1),1);

	/*
     @brief initialize our 5 planes
	 */
	CubeQuad plane(gray, Vector3f(200,0,3000), Vector3f(0,0,500), Vector3f(0,500,0));
	CubeQuad plane1(white, Vector3f(0,20,0), Vector3f(500,0,0), Vector3f(0,0,500));
	CubeQuad plane2(white, Vector3f(0,-20,0), Vector3f(500,0,0), Vector3f(0,0,500));
	CubeQuad plane3(white, Vector3f(0,0,20), Vector3f(500,0,0), Vector3f(0,500,0));
	CubeQuad plane4(white, Vector3f(0,0,-20), Vector3f(500,0,0), Vector3f(0,500,0));
	/*
     @brief initialize our container of shapes
	*/
	vector<Shape*> scene_objects;
	/*
     @brief add our shapes
	*/
	scene_objects.push_back(dynamic_cast<Shape*>(&scene_sphere1));
	scene_objects.push_back(dynamic_cast<Shape*>(&scene_sphere2));
	scene_objects.push_back(dynamic_cast<Shape*>(&plane));
	scene_objects.push_back(dynamic_cast<Shape*>(&plane1));
	scene_objects.push_back(dynamic_cast<Shape*>(&plane2));
	scene_objects.push_back(dynamic_cast<Shape*>(&plane3));
	scene_objects.push_back(dynamic_cast<Shape*>(&plane4));
	/*
     @brief initialize the size of the image
	*/
	int width = 640;
	int height = 480;
	/*
     @brief image construction
	*/
	Scene scene(scene_cam, scene_objects, source);
	scene.render(width, height, "scene_result.png");
	cout<<"Image prête"<<endl;
}


