//
//  main.cpp
//  3DToolViz
//
//  Created by Mahesh Manni on 12/03/22.
//

#include <iostream>
#include "GL/glew.h"
#include "imgui.h"
#include "GLFW/glfw3.h"
#include "shader.h"

using namespace std;

GLuint vbo;
GLuint vao;
Shader* pShader = nullptr;
void init(GLFWwindow* window) {
    
   // Shader obj("../../../../../../../../Documents/Learning/3DToolViz/shaders/shader.vert",
     //          "../../../../../../../../Documents/Learning/3DToolViz/shaders/shader.frag");
    float vertices[] = {
        -0.5f, -0.5f, 0.0f,
         0.5f, -0.5f, 0.0f,
         0.0f,  0.5f, 0.0f
    };
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
}

void display(GLFWwindow* window, double currentTime) {
   glClearColor(1.0, 0.0, 0.0, 1.0);
   glClear(GL_COLOR_BUFFER_BIT);
    if(!pShader)
    {
        pShader = new Shader("../../../../../../../../Documents/Learning/3DToolViz/shaders/shader.vert",
                             "../../../../../../../../Documents/Learning/3DToolViz/shaders/shader.frag");
    }
    pShader->use();
    glBindVertexArray(vao);
    glDrawArrays(GL_TRIANGLES, 0, 3);
}

void error_callback(int error, const char* msg) {
    std::string s;
    s = " [" + std::to_string(error) + "] " + msg + '\n';
    std::cerr << s << std::endl;
    
    
}

bool checkOpenGLError() {
  bool foundError = false;
  int glErr = glGetError();
  while (glErr != GL_NO_ERROR) {
      cout << "glError: " << glErr << endl;
      foundError = true;
      glErr = glGetError();
  }
  return foundError;
}

int main(void) {
    if (!glfwInit()) { exit(EXIT_FAILURE); }
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
    glfwSetErrorCallback(error_callback);
    
    GLFWwindow* window = glfwCreateWindow(600, 600, "3DToolViz", NULL, NULL);
    glfwMakeContextCurrent(window);
    if (glewInit() != GLEW_OK) { exit(EXIT_FAILURE); }
    glfwSwapInterval(1);

    init(window);

    
    while (!glfwWindowShouldClose(window)) {
        display(window, glfwGetTime());
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    exit(EXIT_SUCCESS);
}
