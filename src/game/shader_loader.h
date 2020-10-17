#pragma once
#include <iostream>
#include <string>
#include <glad/glad.h>

#include "file_operations.h"


class shader_loader
{
	GLuint shader_id_;

	GLuint create_shader(const std::string& shader_filepath, GLenum type);
	void check_shader_status(GLuint shader) const;
	void check_linking_status(GLuint program) const;
	void check_program_status() const;
	
public:

	shader_loader() = default;
	void create_shader_program(const std::string& vertex_shader_filepath, const std::string& fragment_shader_filepath);
	GLuint get_shader_id() const;
	void use_program() const;
};
