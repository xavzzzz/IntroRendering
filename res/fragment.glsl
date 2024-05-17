#version 410

out vec4 out_color;

uniform vec2 _uniforme; // Vous pouvez mettre le type que vous voulez, et le nom que vous voulez
uniform float _trans;

void main()
{
    out_color = vec4(vec3(1f,1f,0f), 1f);
}