#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <math.h>
#include <iostream>

using namespace std;

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
        cout << "Error with GLFW! Terminating..." << endl;
        glfwTerminate();
        return -1;
    }

    //make window's context current
    glfwMakeContextCurrent(window);

    if (glewInit() != GLEW_OK) {
        cout << "Error with GLEW! Terminating..." << endl;
        return -1;
    }
 /*                                                    ____                  _______     ______           __        __ _________  ____
   ////////////////////////////////////////////////// / __ \___  ___ ___    / ___/ /    / __/ /____ _____/ /____   / // / __/ _ \/ __/ /////////////////////////////////////////////////
  ////////////////////////////////////////////////// / /_/ / _ \/ -_) _ \  / (_// /__  _\ \/ __/ _ `/ __/ __(_-<  / _  / _// , _/ _/  /////////////////////////////////////////////////
 //////////////////////////////////////////////////  \____/ .__/\__/_//_/  \___/____/ /___/\__/\_,_/_/  \__/___/ /_//_/___/_/|_/___/ /////////////////////////////////////////////////      
////////////////////////////////////////////////// ----- /_/ ---------------------------------------------------------------------- /////////////////////////////////////////////////
*/

    cout << "OpenGL Version " << glGetString(GL_VERSION) << endl;

    //create and bind vertex buffer
    unsigned int buffer;
    glGenBuffers(1, &buffer);
    glBindBuffer(GL_ARRAY_BUFFER, buffer);

    //vertex positions of triangle
    float trianglePositions[6] = {-0.5f, -0.5f,
                                   0.5f, -0.5f,
                                   0.0f,  0.5f};

    glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(float), trianglePositions, GL_STATIC_DRAW);

    //Loop until window is closed
    while (!glfwWindowShouldClose(window))
    {
        
        glClear(GL_COLOR_BUFFER_BIT);

        glBegin(GL_TRIANGLES);

        glVertex2f(-0.5f , -0.5f);
        glVertex2f(0.5f, -0.5f);
        glVertex2f(0.0f, 0.5);

        glEnd();

        glDrawArrays(GL_TRIANGLES, 0, 3);

        //Swap front and back buffers
        glfwSwapBuffers(window);

        //Poll and process events
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;

}