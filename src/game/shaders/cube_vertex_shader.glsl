#version 460

in vec3 position;
in vec3 color;
in vec2 texCoords;
    
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
