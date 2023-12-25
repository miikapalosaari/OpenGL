#include "/OpenGL/common/include/GameWindow.h"
#include <iostream>

//void framebuffer_size_callback(GLFWwindow* window, int width, int height);

GameWindow::GameWindow(unsigned int width, unsigned int height)
{
    setWidth(width);
    setHeight(height);
}

bool GameWindow::InitOpenGLWindow(GLFWwindow*& window)
{
    bool retFlag = true;
    // glfw: initialize and configure
    // ------------------------------
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    // glfw window creation
    // --------------------
    window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    retFlag = false;
    return retFlag;
}

bool GameWindow::loadOpenGlFungtionParamete()
{
    bool retFlag = true;
    // glad: load all OpenGL function pointers
    // ---------------------------------------
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }
    retFlag = false;
    return {};
}

void GameWindow::setWidth(const unsigned int _SCR_WIDTH)
{
    SCR_WIDTH = _SCR_WIDTH;
}

void GameWindow::setHeight(const unsigned int _SCR_HEIGHT)
{
    SCR_HEIGHT = _SCR_HEIGHT;
}


