#include "/OpenGL/game/include/Game.h"
#include <iostream>

int main();
void processInput(GLFWwindow* window);

// settings


int main()
{
    GLFWwindow* window = NULL;
    GameWindow w(SCR_WIDTH,SCR_HEIGHT);
    if (!w.InitOpenGLWindow(window) &&
        window != NULL &&
        !w.loadOpenGlFungtionParamete())
    {
        glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
        // render loop
        // -----------
        while (!glfwWindowShouldClose(window))
        {
            // input
            // -----
            processInput(window);

            // render
            // ------
                glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT);

            // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
            // -------------------------------------------------------------------------------
            glfwSwapBuffers(window);
            glfwPollEvents();
        }

        // glfw: terminate, clearing all previously allocated GLFW resources.
        // ------------------------------------------------------------------
        glfwTerminate();
    }
    return 0;

}


// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
// ---------------------------------------------------------------------------------------------------------
void processInput(GLFWwindow* window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}
