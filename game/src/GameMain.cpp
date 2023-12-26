#include "/OpenGL/game/include/Game.h"
#include <iostream>
#include "/OpenGL/common/include/VertexBufferData.h"
#include "/OpenGL/common/include/Backround.h"
#include "/OpenGL/common/include/Common.h"
int main();

void createAndSeyVertexArrayObj(GLuint& VertexArrayID);
void processInput(GLFWwindow* window);
void display(GLFWwindow* window, double currentTime);




// settings


int main()
{
    GLFWwindow* window = NULL;
    GameWindow w(SCR_WIDTH,SCR_HEIGHT);
    if (!w.InitOpenGLWindow(window,"Game") &&
        window != NULL &&
        !w.loadOpenGlFungtionParamete())
    {
        glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
	    //https://www.opengl-tutorial.org/beginners-tutorials/tutorial-2-the-first-triangle/
        GLuint VertexArrayID;
        createAndSeyVertexArrayObj(VertexArrayID);

        // An array of 3 vectors which represents 3 vertices'
        //ckround a;
        

        // This will identify our vertex buffer
        GLuint vertexbuffer;
        InitalVertexBuffer(vertexbuffer, w);

        GLuint programID = w.LoadShaders("SimpleVertexShader.vertexshader", "SimpleFragmentShader.fragmentshader");
        // render loop
        // -----------
        while (!glfwWindowShouldClose(window))
        {
            // input
            // -----
            
            processInput(window);

            // render
            // ------
            display(window, glfwGetTime());
            

            // 1st attribute buffer : vertices
            glEnableVertexAttribArray(0);
            glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
            glVertexAttribPointer(
                0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
                3,                  // size
                GL_FLOAT,           // type
                GL_FALSE,           // normalized?
                0,                  // stride
                (void*)0            // array buffer offset
            );
            // Draw the triangle !
            glDrawArrays(GL_TRIANGLES, 0, 3); // Starting from vertex 0; 3 vertices total -> 1 triangle
            checkOpenGLError();
            //glDrawArrays(GL_POINTS, 0, 1);
            glDisableVertexAttribArray(0);


            // glfw:which paints the screen 
            // -------------------------------------------------------------------------------
            glfwSwapBuffers(window);
            // glfw:poll IO events (keys pressed/released, mouse moved etc.)
            // -------------------------------------------------------------------------------
            glfwPollEvents();
        }

        // glfw: terminate, clearing all previously allocated GLFW resources.
        // ------------------------------------------------------------------
        glfwTerminate();
    }
    return 0;

}


void createAndSeyVertexArrayObj(GLuint& VertexArrayID)
{
    glGenVertexArrays(1, &VertexArrayID);
    glBindVertexArray(VertexArrayID);
}


// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
// ---------------------------------------------------------------------------------------------------------
void processInput(GLFWwindow* window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

void display(GLFWwindow* window, double currentTime) 
{
    /*
    The parameter references a "GLbitfield" called "GL_COLOR_BUFFER_BIT". 
    OpenGL has many predefined constants (some of them are called enums);
    this one references the color buffer that contains the pixels as they are rendered. 
    OpenGL has several color buffers, and this command clears all of them—that is, 
    it fills them with a predefined color called the "clear color." 
    Note that "clear" in this context doesn't mean "a color that is clear"; rather, 
    it refers to the color that is applied when a color buffer is reset (cleared).
    */
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    /*Immediately before the call to glClear() is a call to glClearColor().
    This allows us to specify the value placed in the elements of 
    a color buffer when it is cleared.*/
    glClear(GL_COLOR_BUFFER_BIT);
}
