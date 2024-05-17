#version 410

layout(location = 0) in vec2 in_position;

uniform float _aspectRatio;
uniform float _time;

void main()
{
    vec2 pos = in_position;
    pos.x = (pos.x/_aspectRatio)+cos(_time);
    pos.y = pos.y+sin(_time);
    gl_Position = vec4(pos, 0., 1.);
}