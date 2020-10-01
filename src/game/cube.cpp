#include "cube.h"

#include "shader_loader.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

void cube::gen()
{
    GLuint vbo;

    GLfloat vertices[] = {
	    -0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f,// 0.0f, 0.0f,
	     0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f,// 1.0f, 0.0f,
	     0.5f,  0.5f, -0.5f, 1.0f, 1.0f, 1.0f,// 1.0f, 1.0f,
	     0.5f,  0.5f, -0.5f, 1.0f, 1.0f, 1.0f,// 1.0f, 1.0f,
	    -0.5f,  0.5f, -0.5f, 1.0f, 1.0f, 1.0f,// 0.0f, 1.0f,
	    -0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f,// 0.0f, 0.0f,
											  //
	    -0.5f, -0.5f,  0.5f, 1.0f, 1.0f, 1.0f,// 0.0f, 0.0f,
	     0.5f, -0.5f,  0.5f, 1.0f, 1.0f, 1.0f,// 1.0f, 0.0f,
	     0.5f,  0.5f,  0.5f, 1.0f, 1.0f, 1.0f,// 1.0f, 1.0f,
	     0.5f,  0.5f,  0.5f, 1.0f, 1.0f, 1.0f,// 1.0f, 1.0f,
	    -0.5f,  0.5f,  0.5f, 1.0f, 1.0f, 1.0f,// 0.0f, 1.0f,
	    -0.5f, -0.5f,  0.5f, 1.0f, 1.0f, 1.0f,// 0.0f, 0.0f,
											  //
	    -0.5f,  0.5f,  0.5f, 1.0f, 1.0f, 1.0f,// 1.0f, 0.0f,
	    -0.5f,  0.5f, -0.5f, 1.0f, 1.0f, 1.0f,// 1.0f, 1.0f,
	    -0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f,// 0.0f, 1.0f,
	    -0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f,// 0.0f, 1.0f,
	    -0.5f, -0.5f,  0.5f, 1.0f, 1.0f, 1.0f,// 0.0f, 0.0f,
	    -0.5f,  0.5f,  0.5f, 1.0f, 1.0f, 1.0f,// 1.0f, 0.0f,
											  //
	     0.5f,  0.5f,  0.5f, 1.0f, 1.0f, 1.0f,// 1.0f, 0.0f,
	     0.5f,  0.5f, -0.5f, 1.0f, 1.0f, 1.0f,// 1.0f, 1.0f,
	     0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f,// 0.0f, 1.0f,
	     0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f,// 0.0f, 1.0f,
	     0.5f, -0.5f,  0.5f, 1.0f, 1.0f, 1.0f,// 0.0f, 0.0f,
	     0.5f,  0.5f,  0.5f, 1.0f, 1.0f, 1.0f,// 1.0f, 0.0f,
											  //
	    -0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f,// 0.0f, 1.0f,
	     0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f,// 1.0f, 1.0f,
	     0.5f, -0.5f,  0.5f, 1.0f, 1.0f, 1.0f,// 1.0f, 0.0f,
	     0.5f, -0.5f,  0.5f, 1.0f, 1.0f, 1.0f,// 1.0f, 0.0f,
	    -0.5f, -0.5f,  0.5f, 1.0f, 1.0f, 1.0f,// 0.0f, 0.0f,
	    -0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f,// 0.0f, 1.0f,
											  //
	    -0.5f,  0.5f, -0.5f, 1.0f, 1.0f, 1.0f,// 0.0f, 1.0f,
	     0.5f,  0.5f, -0.5f, 1.0f, 1.0f, 1.0f,// 1.0f, 1.0f,
	     0.5f,  0.5f,  0.5f, 1.0f, 1.0f, 1.0f,// 1.0f, 0.0f,
	     0.5f,  0.5f,  0.5f, 1.0f, 1.0f, 1.0f,// 1.0f, 0.0f,
	    -0.5f,  0.5f,  0.5f, 1.0f, 1.0f, 1.0f,// 0.0f, 0.0f,
	    -0.5f,  0.5f, -0.5f, 1.0f, 1.0f, 1.0f,// 0.0f, 1.0f,

		-1.0f, -1.0f, -0.5f, 1.0f, 1.0f, 1.0f,// 0.0f, 0.0f,
		1.0f, -1.0f, -0.5f,  1.0f, 1.0f, 1.0f,// 1.0f, 0.0f,
		1.0f,  1.0f, -0.5f,  1.0f, 1.0f, 1.0f,// 1.0f, 1.0f,
		1.0f,  1.0f, -0.5f,  1.0f, 1.0f, 1.0f,// 1.0f, 1.0f,
		-1.0f,  1.0f, -0.5f, 1.0f, 1.0f, 1.0f,// 0.0f, 1.0f,
		-1.0f, -1.0f, -0.5f, 1.0f, 1.0f, 1.0f,// 0.0f, 0.0f
    };


    auto er = glGetError();

    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    er = glGetError();

    GLuint shader_program = shader_loader::create_shader_program(
        R"(C:\Users\dmadr\Documents\Projects\CPP\game\src\game\shaders\cube_vertex_shader.glsl)",
        R"(C:\Users\dmadr\Documents\Projects\CPP\game\src\game\shaders\cube_fragment_shader.glsl)");
    er = glGetError();

    glUseProgram(shader_program);

    er = glGetError();

    GLuint position_att = glGetAttribLocation(shader_program, "position");
    GLuint color_att = glGetAttribLocation(shader_program, "color");

    er = glGetError();

    glEnableVertexAttribArray(position_att);
    glEnableVertexAttribArray(color_att);

    er = glGetError();

    glVertexAttribPointer(position_att, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat),(void*)0);
    glVertexAttribPointer(color_att, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (void*)(3 * sizeof(GLfloat)));

    er = glGetError();

	glm::mat4 model = glm::mat4(1.0f);
	glm::mat4 view = glm::lookAt(
	    glm::vec3(2.5f, 2.5f, 2.5f),
		glm::vec3(0.0f, 0.0f, 0.0f),
		glm::vec3(0.0f, 0.0f, 1.0f));
	glm::mat4 perspective = glm::perspective(glm::radians(45.0f), 1280.0f/720.0f, 1.0f, 10.0f);

    GLuint model_location = glGetUniformLocation(shader_program, "model");
	GLuint view_location = glGetUniformLocation(shader_program, "view");
	GLuint perspective_location = glGetUniformLocation(shader_program, "perspective");

	glUniformMatrix4fv(model_location, 1, GL_FALSE, glm::value_ptr(model));
	glUniformMatrix4fv(view_location, 1, GL_FALSE, glm::value_ptr(view));
	glUniformMatrix4fv(perspective_location, 1, GL_FALSE, glm::value_ptr(perspective));
}

void cube::draw()
{
	glDrawArrays(GL_TRIANGLES, 0, 36);
}
