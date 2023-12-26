#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

class GameWindow
{
public:
	GameWindow(unsigned int width, unsigned int height);
	bool InitOpenGLWindow(GLFWwindow*& window,
		                  std::string windowTitle);
	bool loadOpenGlFungtionParamete();
	void setWidth(const unsigned int _SCR_WIDTH);
	void setHeight(const unsigned int _SCR_HEIGHT);
	GLuint LoadShaders(const char* vertex_file_path, const char* fragment_file_path);
	
private:
	unsigned int SCR_WIDTH = 800;
	unsigned int SCR_HEIGHT = 600;

};

