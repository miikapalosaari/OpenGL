#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
class GameWindow
{
public:
	GameWindow(unsigned int width, unsigned int height);
	bool InitOpenGLWindow(GLFWwindow*& window);
	bool loadOpenGlFungtionParamete();
	void setWidth(const unsigned int _SCR_WIDTH);
	void setHeight(const unsigned int _SCR_HEIGHT);
	
private:
	unsigned int SCR_WIDTH = 800;
	unsigned int SCR_HEIGHT = 600;

};

