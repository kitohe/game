#version 460

in vec3 position;
in vec3 color;
    
out vec3 Color;
    
uniform mat4 model;
uniform mat4 view;
uniform mat4 perspective;

void main()
{
    Color = color;
    gl_Position = perspective * view * model * vec4(position, 1.0);
}
