#version 460

layout(location = 0) in vec3 position;
layout(location = 1) in vec3 color;
layout(location = 2) in vec2 texCoords;
    
out vec3 Color;
out vec2 TexCoords;
    
uniform mat4 model;
uniform mat4 view;
uniform mat4 perspective;

void main()
{
    Color = color;
    TexCoords = texCoords;
    gl_Position = perspective * view * model * vec4(position, 1.0);
}
