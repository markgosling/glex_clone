#include "CubeAsset.h"

using namespace std;

/**
 * Constructor which sets the position of each
 * of the vertices required to create the cube,
 * stores them in a buffer then transfers them
 * to the GPU.
 */
CubeAsset::CubeAsset() {

  //Model coordinates with origin at centre.
  GLfloat vertex_buffer_data [] {

	//Position of vertices for the front of the cube.
	-0.5, -0.5, 0.5,   //0
	-0.5,  0.5, 0.5,   //1
	0.5, -0.5, 0.5,    //2
	0.5,  0.5, 0.5,    //3

	//Position of vertices for the back of the cube.
	-0.5, -0.5, -0.5,  //4
    -0.5,  0.5, -0.5,  //5
    0.5, -0.5, -0.5,   //6
    0.5,  0.5, -0.5,   //7

  };

  element_buffer_length = 36;
  GLuint element_buffer []  {

    //Put cube front vertices in element buffer.
	0, 1, 2, //Triangle 1.
    1, 3, 2, //Triangle 2.

	//Put cube back vertices in element buffer.
	4, 5, 6,
	5, 7, 6,

	//Put cube top vertices in element buffer.
	1, 3, 5,
	3, 7, 5,

	//Put cube bottom vertices in element buffer.
	0, 2, 4,
	2, 6, 4,

	//Put cube left side vertices in element buffer.
	1, 0, 5,
	0, 4, 5,

	//Put cube right side vertices in element buffer.
	3, 2, 7,
	2, 7, 6

  };

  //Transfer buffers to the GPU.

  //Create buffer.
  glGenBuffers(1, &vertex_buffer_token);

  //Immediately bind the buffer and transfer the data.
  glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer_token);
  glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * 24, vertex_buffer_data, GL_STATIC_DRAW);

  glGenBuffers(1, &element_buffer_token);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, element_buffer_token);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLuint) * element_buffer_length, element_buffer, GL_STATIC_DRAW);

  ///Set the asset type. This is required to determine the object type
  //when deciding which shader program to use to colour the object.
  assetType = CUBE;

}

/**
 * Unused destructor.
 */
CubeAsset::~CubeAsset() {
}









