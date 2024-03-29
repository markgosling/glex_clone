#version 130

in vec3 position;

out vec3 frag_color;

uniform mat4 projection_matrix;
uniform mat4 translate_matrix;
uniform mat4 view_matrix;

void main() {

      gl_Position = projection_matrix
                      * view_matrix
                      * translate_matrix
                      * vec4(position, 1.0);
}