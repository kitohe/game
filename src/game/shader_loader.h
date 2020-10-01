#pragma once
#include <glad/glad.h>
#include <string>


class shader_loader
{
	static GLuint create_shader(const std::string& shader_filepath, GLenum type);
	static void check_shader_status(GLuint shader);
	static void check_program_status(GLuint program);
	
public:
	static GLuint create_shader_program(const std::string& vertex_shader_filepath, const std::string& fragment_shader_filepath);
	
};
