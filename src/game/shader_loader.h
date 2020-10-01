#pragma once
#include <glad/glad.h>
#include <string>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>


class shader_loader
{
	GLuint shader_id_;

	GLuint create_shader(const std::string& shader_filepath, GLenum type);
	void check_shader_status(GLuint shader);
	void check_program_status(GLuint program);
	
public:

	shader_loader() = default;

	void create_shader_program(const std::string& vertex_shader_filepath, const std::string& fragment_shader_filepath);
	GLuint get_shader_id() const;

	void set_float(const GLchar* name, GLfloat value) const;
	void set_matrix4(const GLchar* name, glm::mat4 matrix) const;

	void set_vertex_attrib_pointer(const GLchar* name, int size, GLsizei stride, int offset) const;

	void use_program() const;
};
