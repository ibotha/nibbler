#version 330 core

layout (location = 0) in vec3 a_Position;

uniform vec2 u_Coord;
uniform vec2 u_Dimentions;

void main(){
	gl_Position = vec4((a_Position.x + u_Coord.x) / u_Dimentions.x, (a_Position.y + u_Coord.y) / u_Dimentions.y, 0, 1.0);

	gl_Position.xy = gl_Position.xy * 2;
	gl_Position.xy += vec2(-1.0, -1.0);
}
