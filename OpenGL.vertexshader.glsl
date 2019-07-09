#version 330 core

layout (location = 0) in vec3 a_Position;

uniform vec2 u_Dimentions;
uniform vec3 u_Color;
out vec3 v_Color;

void main(){
	gl_Position.x = a_Position.x / u_Dimentions.x;
	gl_Position.y = a_Position.y / u_Dimentions.y;
	gl_Position.z = 0;
	gl_Position.w = 1.0;
	v_Color = u_Color;

	gl_Position.xy = gl_Position.xy * 2;
	gl_Position.xy += vec2(-1.0, -1.0);
}
