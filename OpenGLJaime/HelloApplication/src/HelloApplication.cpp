#include "GLFW/glfw3.h"
#include "Application.h"

Application application;


void checkKeyboard(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
    {
        //Activar el flag de salida del programa.

        glfwSetWindowShouldClose(window, 1);
    }
}

int main(void)
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(1080, 720, "Hello Application", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }
    application.Setup();
    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    glfwSetKeyCallback(window, checkKeyboard);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        //glClear(GL_COLOR_BUFFER_BIT);
        application.Update();
        application.Draw();

        /* Swap front and back buffers */
        //glfwSwapBuffers(window);

        /* Poll for and process events */
        //glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}