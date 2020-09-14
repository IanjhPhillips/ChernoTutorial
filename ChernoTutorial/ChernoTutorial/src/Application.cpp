#include <GLFW/glfw3.h>
#include <math.h>

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

    float angle = 0.0f;
    float result;

    //Loop until window is closed
    while (!glfwWindowShouldClose(window))
    {
        angle += 0.0005f;

        result = 1 + 0.5*sin(angle);

        //Render
        glClear(GL_COLOR_BUFFER_BIT);

        glBegin(GL_TRIANGLES);

        glVertex2f(-0.5f*result, -0.5f*result);
        glVertex2f(0.5f*result, -0.5f*result);
        glVertex2f(0.0f, 0.5 * result);

        glEnd();

        //Swap front and back buffers
        glfwSwapBuffers(window);

        //Poll and process events
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;

    //GLFWwindow* window;

    ///* Initialize the library */
    //if (!glfwInit())
    //    return -1;

    ///* Create a windowed mode window and its OpenGL context */
    //window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    //if (!window)
    //{
    //    glfwTerminate();
    //    return -1;
    //}

    ///* Make the window's context current */
    //glfwMakeContextCurrent(window);

    //float angle=0;
    //float result;

    ///* Loop until the user closes the window */
    //while (!glfwWindowShouldClose(window))
    //{
    //    angle += 0.0005;
    //    result = 1 + sin(angle);

    //    /* Render here */
    //    glClear(GL_COLOR_BUFFER_BIT);

    //    glBegin(GL_TRIANGLES);

    //    //glVertex2f(2.0f, 0.5f);
    //    glVertex2f(-0.5*result, -0.5*result);
    //    glVertex2f(0.5*result, -0.5*result);
    //    glVertex2f(0.0*result, 0.5*result);
    //    
    //    glEnd();

    //    /* Swap front and back buffers */
    //    glfwSwapBuffers(window);

    //    /* Poll for and process events */
    //    glfwPollEvents();
    //}

    //glfwTerminate();
    //return 0;
}