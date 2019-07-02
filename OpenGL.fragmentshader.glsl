#version 330 core

out vec3 color;
in vec3 v_Color;

void main(){
  color = v_Color;
}