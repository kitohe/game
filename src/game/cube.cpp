#include "cube.h"

#include "shader_loader.h"


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

    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glUseProgram(shader_program);

    

    GLuint position_att = glGetAttribLocation(shader_program, "position");
    GLuint color_att = glGetAttribLocation(shader_program, "color");

    

    glEnableVertexAttribArray(position_att);
    glEnableVertexAttribArray(color_att);

    

    glVertexAttribPointer(position_att, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat),(void*)0);
    glVertexAttribPointer(color_att, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (void*)(3 * sizeof(GLfloat)));



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

	auto er = glGetError();
}

void cube::draw()
{
	glDrawArrays(GL_TRIANGLES, 0, 36);
}
