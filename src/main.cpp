#include <stdio.h>
#include <GLFW/glfw3.h>

int main()
{
    // glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    // glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow *window;

    if (!glfwInit())
    {
        printf("Failed to initialize GLFW\n");
        return 1;
    }

    window = glfwCreateWindow(640, 480, "AVP alpha", NULL, NULL);
    if (!window)
    {
        printf("could not open windows");
        return 1;
    }

    unsigned char *data = new unsigned char[100 * 100 * 3];
    for (int y = 0; y < 100; y++)
    {
        for (int x = 0; x < 100; x++)
        {
            data[y * 100 * 3 + x * 3] = 0x00;
            data[y * 100 * 3 + x * 3 + 1] = 0xFF;
            data[y * 100 * 3 + x * 3 + 2] = 0x00;
        }
    }

    glfwMakeContextCurrent(window);

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glDrawPixels(100, 100, GL_RGB, GL_UNSIGNED_BYTE, data);
    glfwSwapBuffers(window);

    while (!glfwWindowShouldClose(window))
    {
        glfwWaitEvents();
    }

    return 0;
}