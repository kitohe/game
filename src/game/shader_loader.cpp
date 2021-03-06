#include "shader_loader.h"


GLuint shader_loader::create_shader(const std::string& shader_filepath, GLenum type)
{
    const auto file_content= file_operations::read_file(shader_filepath);
    const char* shader_code = file_content.c_str();

    const auto shader = glCreateShader(type);
    glShaderSource(shader, 1, &shader_code, nullptr);
    glCompileShader(shader);

    check_shader_status(shader);
    return shader;
}

void shader_loader::create_shader_program(const std::string& vertex_shader_filepath,
                                            const std::string& fragment_shader_filepath)
{
    if (vertex_shader_filepath.empty() || fragment_shader_filepath.empty())
        return;

    const GLuint vertex_shader = create_shader(vertex_shader_filepath, GL_VERTEX_SHADER);
    const GLuint fragment_shader = create_shader(fragment_shader_filepath, GL_FRAGMENT_SHADER);

    const GLuint shader_program = glCreateProgram();

    glAttachShader(shader_program, vertex_shader);
    glAttachShader(shader_program, fragment_shader);

    glLinkProgram(shader_program);

    glDeleteShader(vertex_shader);
    glDeleteShader(fragment_shader);

    check_linking_status(shader_program);

    shader_id_ = shader_program;
}

void shader_loader::check_shader_status(GLuint shader) const
{
    GLint shader_status;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &shader_status);

    if (shader_status != GL_TRUE)
    {
        char buffer[512];
        glGetShaderInfoLog(shader_status, sizeof(buffer), nullptr, buffer);
        std::cerr << buffer << std::endl;
    }
}

void shader_loader::check_linking_status(GLuint program) const
{
    GLint program_status;
    glGetProgramiv(program, GL_LINK_STATUS, &program_status);

    if (program_status != GL_TRUE)
    {
        char buffer[512];
        glGetProgramInfoLog(program_status, sizeof(buffer), nullptr, buffer);
        std::cerr << buffer << std::endl;
    }
}

void shader_loader::check_program_status() const
{
    GLint program_status;
    glValidateProgram(shader_id_);
    glGetProgramiv(shader_id_, GL_VALIDATE_STATUS, &program_status);

    if (program_status != GL_TRUE)
    {
        char buffer[512];
        glGetProgramInfoLog(program_status, sizeof(buffer), nullptr, buffer);
        std::cerr << buffer << std::endl;
    }
}

GLuint shader_loader::get_shader_id() const
{
    return shader_id_;
}

void shader_loader::use_program() const
{
    glUseProgram(shader_id_);
}
