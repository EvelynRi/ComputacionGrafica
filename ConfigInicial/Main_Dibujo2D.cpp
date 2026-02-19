//Practica 2										Perez Rivas Evelyn Samantha 
//Fecha 19-02-2026                                  320258187

#include<iostream>

//#define GLEW_STATIC

#include <GL/glew.h>

#include <GLFW/glfw3.h>

// Shaders
#include "Shader.h"

void resize(GLFWwindow* window, int width, int height);

const GLint WIDTH = 800, HEIGHT = 600;


int main() {
	glfwInit();
	//Verificaci�n de compatibilidad 
	/*glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);*/

	GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "Dibujo de Primitivas en 2D Perez Rivas Evelyn Samantha", NULL, NULL);
	glfwSetFramebufferSizeCallback(window, resize);

	//Verificaci�n de errores de creacion  ventana
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();

		return EXIT_FAILURE;
	}

	glfwMakeContextCurrent(window);
	glewExperimental = GL_TRUE;

	//Verificaci�n de errores de inicializaci�n de glew

	if (GLEW_OK != glewInit()) {
		std::cout << "Failed to initialise GLEW" << std::endl;
		return EXIT_FAILURE;
	}

	// Imprimimos informacin de OpenGL del sistema
	std::cout << "> Version: " << glGetString(GL_VERSION) << std::endl;
	std::cout << "> Vendor: " << glGetString(GL_VENDOR) << std::endl;
	std::cout << "> Renderer: " << glGetString(GL_RENDERER) << std::endl;
	std::cout << "> SL Version: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;


	// Define las dimensiones del viewport
	//glViewport(0, 0, screenWidth, screenHeight);

	Shader ourShader("Shader/core.vs", "Shader/core.frag");

	// Set up vertex data (and buffer(s)) and attribute pointers
	float vertices[] = { 

	// Ala superior izquierda 
	-0.74f,  0.25f, 0.0f,    0.65f, 0.0f, 0.9f,  // C
	-0.68f,  0.43f, 0.0f,    0.55f, 0.0f, 0.8f,  // D
	-0.68f,  0.28f, 0.0f,    0.75f, 0.0f, 0.9f,  // E

	-0.68f,  0.43f, 0.0f,    0.55f, 0.0f, 0.8f,  // D
	-0.68f,  0.28f, 0.0f,    0.75f, 0.0f, 0.9f,  // E
	-0.40f,  0.40f, 0.0f,    0.90f, 0.0f, 1.0f,  // F

	-0.68f,  0.28f, 0.0f,    0.75f, 0.0f, 0.9f,  // E
	-0.40f,  0.40f, 0.0f,    0.90f, 0.0f, 1.0f,  // F
	-0.63f,  0.14f, 0.0f,    1.00f, 0.0f, 0.9f,  // G 

	-0.74f,  0.25f, 0.0f,    0.65f, 0.0f, 0.9f,  // C
	-0.68f,  0.28f, 0.0f,    0.75f, 0.0f, 0.9f,  // E
	-0.63f,  0.14f, 0.0f,    1.00f, 0.0f, 0.9f,  // G

	-0.40f,  0.40f, 0.0f,    0.90f, 0.0f, 1.0f,  // F
	-0.63f,  0.14f, 0.0f,    1.00f, 0.0f, 0.9f,  // G
	-0.48f,  0.14f, 0.0f,    1.00f, 0.0f, 0.85f, // H 

	-0.63f,  0.14f, 0.0f,    1.00f, 0.0f, 0.9f,  // G
	-0.48f,  0.14f, 0.0f,    1.00f, 0.0f, 0.85f, // H
	-0.57f, -0.11f, 0.0f,    0.80f, 0.0f, 0.95f, // I

	-0.48f,  0.14f, 0.0f,    1.00f, 0.0f, 0.85f, // H
	-0.57f, -0.11f, 0.0f,    0.80f, 0.0f, 0.95f, // I
	-0.36f, -0.09f, 0.0f,    0.70f, 0.1f, 1.0f,  // J 

	-0.48f,  0.14f, 0.0f,    1.00f, 0.0f, 0.85f, // H
	-0.36f, -0.09f, 0.0f,    0.70f, 0.1f, 1.0f,  // J
	-0.06f,  0.11f, 0.0f,    1.00f, 0.0f, 0.8f,  // K

	-0.40f,  0.40f, 0.0f,    0.90f, 0.0f, 1.0f,  // F
	-0.48f,  0.14f, 0.0f,    1.00f, 0.0f, 0.85f, // H
	-0.06f,  0.11f, 0.0f,    1.00f, 0.0f, 0.8f,  // K

	// Ala inferior izquierda 
	-0.36f, -0.09f, 0.0f,    0.60f, 0.1f, 1.0f,  // J
	-0.50f, -0.31f, 0.0f,    0.00f, 0.6f, 1.0f,  // L 
	-0.37f, -0.28f, 0.0f,    0.00f, 0.8f, 1.0f,  // M

	-0.36f, -0.09f, 0.0f,    0.60f, 0.1f, 1.0f,  // J
	-0.37f, -0.28f, 0.0f,    0.00f, 0.8f, 1.0f,  // M
	-0.04f, -0.24f, 0.0f,    0.00f, 0.9f, 1.0f,  // N

	-0.37f, -0.28f, 0.0f,    0.00f, 0.8f, 1.0f,  // M
	-0.04f, -0.24f, 0.0f,    0.00f, 0.9f, 1.0f,  // N
	-0.37f, -0.41f, 0.0f,    0.00f, 0.9f, 1.0f,  // O

	-0.50f, -0.31f, 0.0f,    0.00f, 0.6f, 1.0f,  // L
	-0.37f, -0.28f, 0.0f,    0.00f, 0.8f, 1.0f,  // M
	-0.37f, -0.41f, 0.0f,    0.00f, 0.9f, 1.0f,  // O

	-0.04f, -0.24f, 0.0f,    0.00f, 0.9f, 1.0f,  // N
	-0.37f, -0.41f, 0.0f,    0.00f, 0.9f, 1.0f,  // O
	-0.29f, -0.49f, 0.0f,    0.10f, 1.0f, 1.0f,  // P

	-0.50f, -0.31f, 0.0f,    0.00f, 0.6f, 1.0f,  // L
	-0.37f, -0.41f, 0.0f,    0.00f, 0.9f, 1.0f,  // O
	-0.40f, -0.53f, 0.0f,    0.20f, 1.0f, 1.0f,  // Q

	-0.37f, -0.41f, 0.0f,    0.00f, 0.9f, 1.0f,  // O
	-0.29f, -0.49f, 0.0f,    0.10f, 1.0f, 1.0f,  // P
	-0.40f, -0.53f, 0.0f,    0.20f, 1.0f, 1.0f,  // Q

	-0.29f, -0.49f, 0.0f,    0.10f, 1.0f, 1.0f,  // P
	-0.40f, -0.53f, 0.0f,    0.20f, 1.0f, 1.0f,  // Q
	-0.16f, -0.62f, 0.0f,    0.00f, 1.0f, 1.0f,  // R

	-0.04f, -0.24f, 0.0f,    0.00f, 0.9f, 1.0f,  // N
	-0.29f, -0.49f, 0.0f,    0.10f, 1.0f, 1.0f,  // P
	-0.02f, -0.35f, 0.0f,    0.00f, 0.95f, 1.0f, // S

	-0.29f, -0.49f, 0.0f,    0.10f, 1.0f, 1.0f,  // P
	-0.02f, -0.35f, 0.0f,    0.00f, 0.95f, 1.0f, // S
	-0.16f, -0.62f, 0.0f,    0.00f, 1.0f, 1.0f,  // R

	-0.36f, -0.09f, 0.0f,    0.60f, 0.1f, 1.0f,  // J
	-0.06f,  0.11f, 0.0f,    1.00f, 0.0f, 0.8f,  // K
	-0.04f, -0.24f, 0.0f,    0.00f, 0.9f, 1.0f,  // N

	//Ala superior derecha 
	0.08f,  0.11f, 0.0f,     1.00f, 0.0f, 0.8f,  // T 
	0.43f,  0.38f, 0.0f,     0.90f, 0.0f, 1.0f,  // U
	0.50f,  0.15f, 0.0f,     1.00f, 0.0f, 0.9f,  // V

	0.43f,  0.38f, 0.0f,     0.90f, 0.0f, 1.0f,  // U
	0.50f,  0.15f, 0.0f,     1.00f, 0.0f, 0.9f,  // V
	0.64f,  0.14f, 0.0f,     1.00f, 0.0f, 0.9f,  // W

	0.43f,  0.38f, 0.0f,     0.90f, 0.0f, 1.0f,  // U
	0.64f,  0.14f, 0.0f,     1.00f, 0.0f, 0.9f,  // W
	0.70f,  0.27f, 0.0f,     0.75f, 0.0f, 0.9f,  // Z

	0.43f,  0.38f, 0.0f,     0.90f, 0.0f, 1.0f,  // U
	0.70f,  0.27f, 0.0f,     0.75f, 0.0f, 0.9f,  // Z
	0.70f,  0.43f, 0.0f,     0.55f, 0.0f, 0.8f,  // A1

	0.70f,  0.27f, 0.0f,     0.75f, 0.0f, 0.9f,  // Z
	0.70f,  0.43f, 0.0f,     0.55f, 0.0f, 0.8f,  // A1
	0.75f,  0.25f, 0.0f,     0.65f, 0.0f, 0.9f,  // B1

	0.64f,  0.14f, 0.0f,     1.00f, 0.0f, 0.9f,  // W
	0.70f,  0.27f, 0.0f,     0.75f, 0.0f, 0.9f,  // Z
	0.75f,  0.25f, 0.0f,     0.65f, 0.0f, 0.9f,  // B1

	0.50f,  0.15f, 0.0f,     1.00f, 0.0f, 0.9f,  // V
	0.64f,  0.14f, 0.0f,     1.00f, 0.0f, 0.9f,  // W
	0.58f, -0.10f, 0.0f,     0.80f, 0.0f, 0.95f, // C1

	0.50f,  0.15f, 0.0f,     1.00f, 0.0f, 0.9f,  // V
	0.58f, -0.10f, 0.0f,     0.80f, 0.0f, 0.95f, // C1
	0.37f, -0.09f, 0.0f,     0.70f, 0.1f, 1.0f,  // D1

	0.08f,  0.11f, 0.0f,     1.00f, 0.0f, 0.8f,  // T 
	0.50f,  0.15f, 0.0f,     1.00f, 0.0f, 0.9f,  // V
	0.37f, -0.09f, 0.0f,     0.70f, 0.1f, 1.0f,  // D1

	0.08f,  0.11f, 0.0f,     1.00f, 0.0f, 0.8f,  // T 
	0.37f, -0.09f, 0.0f,     0.70f, 0.1f, 1.0f,  // D1
	0.05f, -0.24f, 0.0f,     0.00f, 0.9f, 1.0f,  // E1 

	//Ala derecha inferior
	0.05f, -0.24f, 0.0f,     0.00f, 0.9f, 1.0f,  // E1
	0.37f, -0.09f, 0.0f,     0.60f, 0.1f, 1.0f,  // D1
	0.39f, -0.29f, 0.0f,     0.00f, 0.8f, 1.0f,  // F1

	0.37f, -0.09f, 0.0f,     0.60f, 0.1f, 1.0f,  // D1
	0.39f, -0.29f, 0.0f,     0.00f, 0.8f, 1.0f,  // F1
	0.53f, -0.31f, 0.0f,     0.00f, 0.6f, 1.0f,  // G1 

	0.39f, -0.29f, 0.0f,     0.00f, 0.8f, 1.0f,  // F1
	0.53f, -0.31f, 0.0f,     0.00f, 0.6f, 1.0f,  // G1 
	0.40f, -0.40f, 0.0f,     0.00f, 0.9f, 1.0f,  // H1 

	0.53f, -0.31f, 0.0f,     0.00f, 0.6f, 1.0f,  // G1 
	0.40f, -0.40f, 0.0f,     0.00f, 0.9f, 1.0f,  // H1
	0.42f, -0.54f, 0.0f,     0.20f, 1.0f, 1.0f,  // I1

	0.40f, -0.40f, 0.0f,     0.00f, 0.9f, 1.0f,  // H1
	0.42f, -0.54f, 0.0f,     0.20f, 1.0f, 1.0f,  // I1
	0.31f, -0.49f, 0.0f,     0.10f, 1.0f, 1.0f,  // J1

	0.42f, -0.54f, 0.0f,     0.20f, 1.0f, 1.0f,  // I1
	0.31f, -0.49f, 0.0f,     0.10f, 1.0f, 1.0f,  // J1
	0.17f, -0.62f, 0.0f,     0.00f, 1.0f, 1.0f,  // K1

	0.40f, -0.40f, 0.0f,     0.00f, 0.9f, 1.0f,  // H1
	0.31f, -0.49f, 0.0f,     0.10f, 1.0f, 1.0f,  // J1
	0.05f, -0.24f, 0.0f,     0.00f, 0.9f, 1.0f,  // E1

	0.05f, -0.24f, 0.0f,     0.00f, 0.9f, 1.0f,  // E1
	0.39f, -0.29f, 0.0f,     0.00f, 0.8f, 1.0f,  // F1
	0.40f, -0.40f, 0.0f,     0.00f, 0.9f, 1.0f,  // H1

	0.31f, -0.49f, 0.0f,     0.10f, 1.0f, 1.0f,  // J1
	0.17f, -0.62f, 0.0f,     0.00f, 1.0f, 1.0f,  // K1
	0.04f, -0.35f, 0.0f,     0.00f, 0.95f, 1.0f, // M1

	0.31f, -0.49f, 0.0f,     0.10f, 1.0f, 1.0f,  // J1
	0.05f, -0.24f, 0.0f,     0.00f, 0.9f, 1.0f,  // E1
	0.04f, -0.35f, 0.0f,     0.00f, 0.95f, 1.0f, // M1 

	//Antenas
	-0.08f,  0.30f, 0.0f,    0.9f, 0.85f, 0.5f,  // N1
	-0.05f,  0.34f, 0.0f,    0.8f, 0.75f, 0.4f,  // O1
	-0.010f, 0.17f, 0.0f,    0.1f, 0.1f, 0.1f,   // P1

	 0.07f,  0.33f, 0.0f,    0.8f, 0.75f, 0.4f,  // Q1
	 0.10f,  0.30f, 0.0f,    0.9f, 0.85f, 0.5f,  // R1
	 0.03f,  0.17f, 0.f,     0.1f, 0.1f, 0.1f,   // S1 

	// Cara 
	-0.010f, 0.17f, 0.0f, 0.85f, 0.65f, 0.00f,   // P1 
	0.03f, 0.17f, 0.0f, 0.85f, 0.65f, 0.00f,   // S1
	0.01f, 0.11f, 0.0f, 1.00f, 0.90f, 0.10f,   // V1 

	0.03f, 0.17f, 0.0f, 0.85f, 0.65f, 0.00f,   // S1
	0.01f, 0.11f, 0.0f, 1.00f, 0.90f, 0.10f,   // V1
	0.08f, 0.11f, 0.0f, 0.75f, 0.55f, 0.00f,   // T 

	0.01f, 0.11f, 0.0f, 1.00f, 0.90f, 0.10f,   // V1
	0.08f, 0.11f, 0.0f, 0.75f, 0.55f, 0.00f,   // T
	0.04f, 0.05f, 0.0f, 0.90f, 0.75f, 0.05f,   // U1

	0.01f, 0.11f, 0.0f, 1.00f, 0.90f, 0.10f,   // V1
	0.04f, 0.05f, 0.0f, 0.90f, 0.75f, 0.05f,   // U1
	-0.02f, 0.05f, 0.0f, 0.90f, 0.75f, 0.05f,   // T1

	0.01f, 0.11f, 0.0f, 1.00f, 0.90f, 0.10f,   // V1
	-0.02f, 0.05f, 0.0f, 0.90f, 0.75f, 0.05f,   // T1
	-0.06f, 0.11f, 0.0f, 0.75f, 0.55f, 0.00f,   // K  

	-0.010f, 0.17f, 0.0f, 0.85f, 0.65f, 0.00f,   // P1
	0.01f, 0.11f, 0.0f, 1.00f, 0.90f, 0.10f,   // V1
	-0.06f, 0.11f, 0.0f, 0.75f, 0.55f, 0.00f,   // K

	// Cuerpo 

	0.01f, 0.05f, 0.0f, 0.90f, 0.70f, 0.00f, // W1 
	0.05f, -0.24f, 0.0f, 1.00f, 0.85f, 0.10f, // E1 
	-0.04f, -0.24f, 0.0f, 1.00f, 0.85f, 0.10f, // N

	0.05f, -0.24f, 0.0f, 1.00f, 0.85f, 0.10f, // E1
	-0.04f, -0.24f, 0.0f, 1.00f, 0.85f, 0.10f, // N
	0.01f, -0.29f, 0.0f, 0.80f, 0.60f, 0.00f, // Z1 

	0.05f, -0.24f, 0.0f, 1.00f, 0.85f, 0.10f, // E1
	0.01f, -0.29f, 0.0f, 0.80f, 0.60f, 0.00f, // Z1
	0.04f, -0.35f, 0.0f, 1.00f, 0.90f, 0.20f, // M1 

	-0.04f, -0.24f, 0.0f, 1.00f, 0.85f, 0.10f, // N
	0.01f, -0.29f, 0.0f, 0.80f, 0.60f, 0.00f, // Z1
	-0.02f, -0.35f, 0.0f, 1.00f, 0.90f, 0.20f, // S

	0.04f, -0.35f, 0.0f, 1.00f, 0.90f, 0.20f, // M1
	0.01f, -0.29f, 0.0f, 0.80f, 0.60f, 0.00f, // Z1
	-0.02f, -0.35f, 0.0f, 1.00f, 0.90f, 0.20f, // S

	0.04f, -0.35f, 0.0f, 1.00f, 0.90f, 0.20f, // M1
	-0.02f, -0.35f, 0.0f, 1.00f, 0.90f, 0.20f, // S
	0.01f, -0.38f, 0.0f, 0.70f, 0.50f, 0.00f  // A2 
	};
	unsigned int indices[] = {  // note that we start from 0!
		3,2,1,// second Triangle
		0,1,3,

	};



	GLuint VBO, VAO, EBO;
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);

	// Enlazar  Vertex Array Object
	glBindVertexArray(VAO);

	//2.- Copiamos nuestros arreglo de vertices en un buffer de vertices para que OpenGL lo use
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	// 3.Copiamos nuestro arreglo de indices en  un elemento del buffer para que OpenGL lo use
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	// 4. Despues colocamos las caracteristicas de los vertices

	//Posicion
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);

	//Color
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);

	glBindBuffer(GL_ARRAY_BUFFER, 0);


	glBindVertexArray(0); // Unbind VAO (it's always a good thing to unbind any buffer/array to prevent strange bugs)



	while (!glfwWindowShouldClose(window))
	{
		// Check if any events have been activiated (key pressed, mouse moved etc.) and call corresponding response functions
		glfwPollEvents();

		// Render
		// Clear the colorbuffer
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);


		// Draw our first triangle
		ourShader.Use();
		glBindVertexArray(VAO);


		//glPointSize(1);
		//glDrawArrays(GL_POINTS, 0, 1);

		//glDrawArrays(GL_LINES,0,168);
		//glDrawArrays(GL_LINE_LOOP,0,4);

		glDrawArrays(GL_TRIANGLES,0,168);
		//glDrawElements(GL_TRIANGLES, 3,GL_UNSIGNED_INT,0);



		glBindVertexArray(0);

		// Swap the screen buffers
		glfwSwapBuffers(window);
	}



	glfwTerminate();
	return EXIT_SUCCESS;
}

void resize(GLFWwindow* window, int width, int height)
{
	// Set the Viewport to the size of the created window
	glViewport(0, 0, width, height);
	//glViewport(0, 0, screenWidth, screenHeight);
}