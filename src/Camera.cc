#include "Camera.h"
#include <glm/ext.hpp>
#include <iostream>

/*
 * Camera.cc
 *
 *  Created on: 8 Dec 2015
 *      Author: mark
 */


Camera::Camera(){
	  camera_x_position = -3.0f;
	  camera_y_position = 1.5f;
	  camera_z_position = 0.0f;

	  horizontal_angle = 0;
	  vertical_angle = 0;

}

glm::mat4 Camera::UpdateCameraPosition(InputDirection inputDirection, int mouse_x, int mouse_y){

	if(inputDirection == UP){
		  camera_z_position += 0.1;
		 // cout << "up " << player_z_position << endl;
	  }else if(inputDirection == DOWN){
		  camera_z_position -= 0.1;
		  //cout << "down " << player_z_position << endl;
	  }else if(inputDirection == LEFT){
		  camera_x_position += 0.1;
		  //cout << "left " << player_x_position << endl;
	  }else if(inputDirection == RIGHT){
		  camera_x_position -= 0.1;
		  //cout << "right " << player_x_position << endl;
	  }

	  //http://www.opengl-tutorial.org/beginners-tutorials/tutorial-3-matrices/
	  //http://www.opengl-tutorial.org/beginners-tutorials/tutorial-6-keyboard-and-mouse/

	 // horizontal_angle += 0.1 * 0.1 * float(640/2 - mouse_x);
	 // vertical_angle += 0.1 * 0.1 * float(480/2 - mouse_y);

	  std::cout << "Hoz: " << horizontal_angle << std::endl;
	  std::cout << "Vert: " << vertical_angle << std::endl;

	  return glm::lookAt(glm::vec3(camera_x_position, camera_y_position, camera_z_position),
			                    glm::vec3(camera_x_position + (cos(vertical_angle) * sin(horizontal_angle)), camera_y_position + (sin(vertical_angle)), camera_z_position + (cos(vertical_angle) * cos(horizontal_angle))),
								glm::vec3(0.0f, 1.0f, 0.0f));
}


