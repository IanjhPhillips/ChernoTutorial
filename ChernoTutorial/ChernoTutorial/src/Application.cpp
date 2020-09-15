#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <math.h>
#include <iostream>

int main(void)
{
    GLFWwindow* window;

    const int WIDTH = 640;
    const int HEIGHT = 480;

    //initialize GLFW, the library that creates the window
    if (!glfwInit())
        return -1;

    //create glfw window
    window = glfwCreateWindow(WIDTH, HEIGHT, "Cherno Tutorial Project", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    //make window's context current
    glfwMakeContextCurrent(window);

    if (glewInit() != GLEW_OK) {
        std::cout << "Error with GLEW! Terminating..." << std::endl;
        return -1;
    }
 /*                                                    ____                  _______     ______           __        __ _________  ____
   ////////////////////////////////////////////////// / __ \___  ___ ___    / ___/ /    / __/ /____ _____/ /____   / // / __/ _ \/ __/ /////////////////////////////////////////////////
  ////////////////////////////////////////////////// / /_/ / _ \/ -_) _ \  / (_// /__  _\ \/ __/ _ `/ __/ __(_-<  / _  / _// , _/ _/  /////////////////////////////////////////////////
 //////////////////////////////////////////////////  \____/ .__/\__/_//_/  \___/____/ /___/\__/\_,_/_/  \__/___/ /_//_/___/_/|_/___/ /////////////////////////////////////////////////      
////////////////////////////////////////////////// ----- /_/ ---------------------------------------------------------------------- /////////////////////////////////////////////////
*/

    std::cout << "OpenGL Version " << glGetString(GL_VERSION) << std::endl;
    

    //for growing and shrinking effect
    float angle = 0.0f;
    float scale = 1;

    //Loop until window is closed
    while (!glfwWindowShouldClose(window))
    {
        /*angle += 0.0005f;
        //makes the triangle grow and shrink
        result = 1 + 0.5*sin(angle);*/

        //Render
        glClear(GL_COLOR_BUFFER_BIT);

        glBegin(GL_TRIANGLES);

        glVertex2f(-0.5f * scale, -0.5f * scale);
        glVertex2f(0.5f * scale, -0.5f * scale);
        glVertex2f(0.0f, 0.5 * scale);

        glEnd();

        //Swap front and back buffers
        glfwSwapBuffers(window);

        //Poll and process events
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;

}