/* ===================================================================================
	Departamento Eng. Informatica - FCTUC
	Computacao Grafica - 2021/22
	......................... João Carlos Silva.......................
======================================================================================= */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <GL/Glut.h>
#include <windows.h>

#include "RgbImage.h"

//-------------- Some Colors-------------------
#define BLUE     0.0, 0.0, 1.0, 1.0
#define RED		 1.0, 0.0, 0.0, 1.0
#define YELLOW	 1.0, 1.0, 0.0, 1.0
#define GREEN    0.0, 1.0, 0.0, 1.0
#define WHITE    1.0, 1.0, 1.0, 1.0
#define BLACK    0.0, 0.0, 0.0, 1.0
#define BLUUUUE  113/256.f, 134/256.f, 238/256.f, 1.0
#define PI		 3.14159

//=====================Variables e constants======================================

GLfloat tam = 1.25;
static GLfloat vertices[] = {
	//Left1
		-(tam * 1.75),  -tam * 0.5,  tam * 0.8,	// 0 
		-(tam * 1.75),   tam * 0.5,  tam * 0.8,	// 1 
		-(tam * 1.75),   tam * 0.5, -tam * 0.8,	// 2 
		-(tam * 1.75),  -tam * 0.5, -tam * 0.8,	// 3 

	//Right1
		 (tam * 1.75),  -tam * 0.5,  tam * 0.8,	// 4 
		 (tam * 1.75),   tam * 0.5,  tam * 0.8,	// 5 
		 (tam * 1.75),   tam * 0.5, -tam * 0.8,	// 6 
		 (tam * 1.75),  -tam * 0.5, -tam * 0.8,	// 7 
	
	//Up
		-(tam * 1.75),  tam * 0.5,  tam * 0.8,	// 8 
		-(tam * 1.75),  tam * 0.5, -tam * 0.8,	// 9 
		 (tam * 1.75),  tam * 0.5, -tam * 0.8,	// 10 
		 (tam * 1.75),  tam * 0.5,  tam * 0.8,	// 11 

	//Down
		-(tam * 1.75),  -tam * 0.5,  tam * 0.8,	// 12
		-(tam * 1.75),  -tam * 0.5, -tam * 0.8,	// 13 
		 (tam * 1.75),  -tam * 0.5, -tam * 0.8,	// 14 
		 (tam * 1.75),  -tam * 0.5,  tam * 0.8,	// 15 

	//Right2
		-(tam * 1.75),  -tam * 0.5,  tam * 0.8,	// 16 
		-(tam * 1.75),   tam * 0.5,  tam * 0.8,	// 17 
		 (tam * 1.75),   tam * 0.5,  tam * 0.8,	// 18 
		 (tam * 1.75),  -tam * 0.5,  tam * 0.8,	// 19 

	//Left2
		-(tam * 1.75),  -tam * 0.5, -tam * 0.8,	// 20 
		-(tam * 1.75),   tam * 0.5, -tam * 0.8,	// 21 
		 (tam * 1.75),   tam * 0.5, -tam * 0.8,	// 22 
		 (tam * 1.75),  -tam * 0.5, -tam * 0.8,	// 23 
};

GLfloat tam2 = 0.22;

static GLfloat vertices2[]{
	//Up
		-tam2,  tam * 0.15 / 1.25,  tam2,	// 0 
		-tam2,  tam * 0.15 / 1.25, -tam2,	// 1 
		 tam2,  tam * 0.15 / 1.25, -tam2,	// 2 
		 tam2,  tam * 0.15 / 1.25,  tam2,	// 3 
		 0,  tam * 0.15 / 1.25,  tam2 * 2,  // 4

	//Down
		-tam2,  -tam * 0.15 / 1.25,  tam2,	// 5
		-tam2,  -tam * 0.15 / 1.25, -tam2,	// 6 
		 tam2,  -tam * 0.15 / 1.25, -tam2,	// 7 
		 tam2,  -tam * 0.15 / 1.25,  tam2,	// 8 
		 0, - tam * 0.15 / 1.25,  tam2 * 2, // 9

	//Left diagonal
		0,  tam * 0.15 / 1.25,  tam2 * 2,   // 10
		0,  -tam * 0.15 / 1.25,  tam2 * 2,  // 11
		tam2,  -tam * 0.15 / 1.25,  tam2,	// 12
		tam2,  tam * 0.15 / 1.25,  tam2,	// 13

	//Left
		 tam2,  tam * 0.15 / 1.25,  tam2,	// 14
		 tam2,  -tam * 0.15 / 1.25,  tam2,	// 15
		 tam2,  -tam * 0.15 / 1.25, -tam2,	// 16 
		 tam2,  tam * 0.15 / 1.25, -tam2,	// 17

	//Back
		 tam2,  tam * 0.15 / 1.25, -tam2,	// 18
		 tam2,  -tam * 0.15 / 1.25,  -tam2,	// 19 
		 -tam2, -tam * 0.15 / 1.25, -tam2,	// 20 
		 -tam2,  tam * 0.15 / 1.25, -tam2,	// 21 

	//Right
		-tam2,  tam * 0.15 / 1.25, -tam2,	// 22 
		-tam2,  -tam * 0.15 / 1.25, -tam2,	// 23 
		-tam2,  -tam * 0.15 / 1.25, tam2,	// 24 
		-tam2,  tam * 0.15 / 1.25, tam2,	// 25 

	//Right diagonal
		-tam2,  tam * 0.15 / 1.25, tam2,	// 26 
		-tam2,  -tam * 0.15 / 1.25, tam2,	// 27 
		0, -tam * 0.15 / 1.25,  tam2 * 2,	// 28 
		0, tam * 0.15 / 1.25,  tam2 * 2,	// 29

};

static GLfloat normais[] = {
	  //Left
	  -1.0,  0.0,  0.0,
	  -1.0,  0.0,  0.0,
	  -1.0,  0.0,  0.0,
	  -1.0,  0.0,  0.0,

	  //Right
	   1.0,  0.0,  0.0,
	   1.0,  0.0,  0.0,
	   1.0,  0.0,  0.0,
	   1.0,  0.0,  0.0,

	  //Up
	   0.0,  1.0,  0.0,
	   0.0,  1.0,  0.0,
	   0.0,  1.0,  0.0,
	   0.0,  1.0,  0.0,

	  //Down
	   0.0,  -1.0,  0.0,
	   0.0,  -1.0,  0.0,
	   0.0,  -1.0,  0.0,
	   0.0,  -1.0,  0.0,

	   //Front
	   0.0,  0.0,  1.0,
	   0.0,  0.0,  1.0,
	   0.0,  0.0,  1.0,
	   0.0,  0.0,  1.0,

	   //Back
	  0.0,  0.0,  -1.0,
	  0.0,  0.0,  -1.0,
	  0.0,  0.0,  -1.0,
	  0.0,  0.0,  -1.0,
};
//------------------------------------------------------------ Colors
static GLfloat cor[] = {
		0.8, 0.8, 0.8,
		0.8, 0.8, 0.8,
		0.8, 0.8, 0.8,
		0.8, 0.8, 0.8,

		0.8, 0.8, 0.8,
		0.8, 0.8, 0.8,
		0.8, 0.8, 0.8,
		0.8, 0.8, 0.8,

		0.8, 0.8, 0.8,
		0.8, 0.8, 0.8,
		0.8, 0.8, 0.8,
		0.8, 0.8, 0.8,

		0.8, 0.8, 0.8,
		0.8, 0.8, 0.8,
		0.8, 0.8, 0.8,
		0.8, 0.8, 0.8,

		0.8, 0.8, 0.8,
		0.8, 0.8, 0.8,
		0.8, 0.8, 0.8,
		0.8, 0.8, 0.8,

		0.8, 0.8, 0.8,
		0.8, 0.8, 0.8,
		0.8, 0.8, 0.8,
		0.8, 0.8, 0.8,
};

static GLfloat cor2[] = {
		96 / 255.f, 96 / 255.f, 96 / 255.f,
		96 / 255.f, 96 / 255.f, 96 / 255.f,
		96 / 255.f, 96 / 255.f, 96 / 255.f,
		96 / 255.f, 96 / 255.f, 96 / 255.f,
		96 / 255.f, 96 / 255.f, 96 / 255.f,

		96 / 255.f, 96 / 255.f, 96 / 255.f,
		96 / 255.f, 96 / 255.f, 96 / 255.f,
		96 / 255.f, 96 / 255.f, 96 / 255.f,
		96 / 255.f, 96 / 255.f, 96 / 255.f,
		96 / 255.f, 96 / 255.f, 96 / 255.f,

		96 / 255.f, 96 / 255.f, 96 / 255.f,
		96 / 255.f, 96 / 255.f, 96 / 255.f,
		96 / 255.f, 96 / 255.f, 96 / 255.f,
		96 / 255.f, 96 / 255.f, 96 / 255.f,

		96 / 255.f, 96 / 255.f, 96 / 255.f,
		96 / 255.f, 96 / 255.f, 96 / 255.f,
		96 / 255.f, 96 / 255.f, 96 / 255.f,
		96 / 255.f, 96 / 255.f, 96 / 255.f,

		96 / 255.f, 96 / 255.f, 96 / 255.f,
		96 / 255.f, 96 / 255.f, 96 / 255.f,
		96 / 255.f, 96 / 255.f, 96 / 255.f,
		96 / 255.f, 96 / 255.f, 96 / 255.f,

		96 / 255.f, 96 / 255.f, 96 / 255.f,
		96 / 255.f, 96 / 255.f, 96 / 255.f,
		96 / 255.f, 96 / 255.f, 96 / 255.f,
		96 / 255.f, 96 / 255.f, 96 / 255.f,

		96 / 255.f, 96 / 255.f, 96 / 255.f,
		96 / 255.f, 96 / 255.f, 96 / 255.f,
		96 / 255.f, 96 / 255.f, 96 / 255.f,
		96 / 255.f, 96 / 255.f, 96 / 255.f,
};


static GLuint faces[6][4] = {
	{0, 3, 2, 1 },		 //left 
	{4, 7, 6, 5 },		 //right 
	{8, 11, 10, 9},		 //up
	{12, 15, 14, 13},	 //down
	{16, 19, 18, 17},	 //front 
	{20, 23, 22, 21}	 //back
};

static GLuint faces2top[2][5] = {
	{0, 4, 3, 2, 1},   //up 
	{5, 9, 8, 7, 6}    //down
};

static GLint faces2lat[5][4] = {
	{10,13,12,11},
	{14,17,16,15},
	{18,21,20,19},
	{22,25,24,23},
	{26,29,28,27}
};


//------------------------------------------------------------ Objects (coordinate system)
GLint		wScreen = 800, hScreen = 600;			//.. window (pixels)
GLfloat		xC = 10.0, yC = 10.0, zC = 10.0;		//.. world  (wolrd units)

//------------------------------------------------------------ Observer
GLfloat R, R2;
GLfloat  rVisao = 10, aVisao = (GLfloat)2 * R * PI / 180.f + 0.5 * PI, aVisao2 = (GLfloat)2 * R2 * PI / 180.f + 0.5 * PI;
GLfloat  obsP[2][3] = { { rVisao * cos(aVisao), 3.0, rVisao * sin(aVisao) },{ rVisao * cos(aVisao2), 3.0, rVisao * sin(aVisao2) } };
GLfloat  angZoom = 45;

GLfloat msec = 10;

GLfloat angJoystick[2][2] = { {0,0},{0,0} };
GLfloat incAngJoystick = 3;


GLfloat pos[9] = { 0.86, 0.86, 0.86, 0.86, 0.86, 0.86, 0.86, 0.86, 0.625 };
GLboolean flags[9] = { false, false, false, false, false, false, false, false, false }; 
GLboolean views[4] = { false, false, false, false };

GLfloat verticesCil[240*3];
GLfloat normaisCil[240*3];
static GLuint facesCillat[120][4];
static GLuint facesCiltop[2][120];
static GLfloat corCil[120 * 3];

GLint on_off_botoes=-1;

//texturas
RgbImage imag;
GLuint   texture[7];

//materiais
GLfloat luzGlobalCorAmb[4] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat ks = 64;
GLfloat intensidade = 0.5;
GLfloat luzR = 1;
GLfloat luzG = 1;
GLfloat luzB = 1;
GLint   malha = 0;
GLfloat alpha = 1;

GLint   dim = 64;   //grill
GLint   foco = 0;


void changeMaterial(GLint n) {
	if (n == 1) {
		float mat_ambient[] = { 0.05375f, 0.05f, 0.06625f, 0.82f };
		float mat_diffuse[] = { 0.18275f, 0.17f, 0.22525f, 0.82f };
		float mat_specular[] = { 0.332741f, 0.328634f, 0.346435f, 0.82f };
		float shine = ks;

		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_ambient);
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_diffuse);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_specular);
		glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, shine);
	}
	else if (n == 2) {
		float mat_ambient[] = { 0.19225f, 0.19225f, 0.19225f, alpha };
		float mat_diffuse[] = { 0.50754f, 0.50754f, 0.50754f, alpha };
		float mat_specular[] = { 0.508273f, 0.508273f, 0.508273f, alpha };
		float shine = 51.2f;

		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_ambient);
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_diffuse);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_specular);
		glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, shine);
	}
	else if (n == 3) {
		float mat_ambient[] = { 0.05f,0.05f,0.05f,1.0f };
		float mat_diffuse[] = { 0.5f,0.5f,0.5f,1.0f };
		float mat_specular[] = { 0.7f,0.7f,0.7f,1.0f };
		float shine = 10.0f;


		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_ambient);
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_diffuse);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_specular);
		glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, shine);
	}
}

void initializeTexts() {
	glGenTextures(1, &texture[0]);
	glBindTexture(GL_TEXTURE_2D, texture[0]);
	imag.LoadBmpFile("textura_joystick.bmp");
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexImage2D(GL_TEXTURE_2D, 0, 3,
		imag.GetNumCols(),
		imag.GetNumRows(), 0, GL_RGB, GL_UNSIGNED_BYTE,
		imag.ImageData());

	glGenTextures(1, &texture[1]);
	glBindTexture(GL_TEXTURE_2D, texture[1]);
	imag.LoadBmpFile("textura_xsss.bmp");
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexImage2D(GL_TEXTURE_2D, 0, 3,
		imag.GetNumCols(),
		imag.GetNumRows(), 0, GL_RGB, GL_UNSIGNED_BYTE,
		imag.ImageData());

	glGenTextures(1, &texture[2]);
	glBindTexture(GL_TEXTURE_2D, texture[2]);
	imag.LoadBmpFile("textura_circulo.bmp");
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexImage2D(GL_TEXTURE_2D, 0, 3,
		imag.GetNumCols(),
		imag.GetNumRows(), 0, GL_RGB, GL_UNSIGNED_BYTE,
		imag.ImageData());

	glGenTextures(1, &texture[3]);
	glBindTexture(GL_TEXTURE_2D, texture[3]);
	imag.LoadBmpFile("textura_quadrado.bmp");
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexImage2D(GL_TEXTURE_2D, 0, 3,
		imag.GetNumCols(),
		imag.GetNumRows(), 0, GL_RGB, GL_UNSIGNED_BYTE,
		imag.ImageData());

	glGenTextures(1, &texture[4]);
	glBindTexture(GL_TEXTURE_2D, texture[4]);
	imag.LoadBmpFile("textura_triangulo.bmp");
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexImage2D(GL_TEXTURE_2D, 0, 3,
		imag.GetNumCols(),
		imag.GetNumRows(), 0, GL_RGB, GL_UNSIGNED_BYTE,
		imag.ImageData());

	glGenTextures(1, &texture[5]);
	glBindTexture(GL_TEXTURE_2D, texture[5]);
	imag.LoadBmpFile("textura_ps4.bmp");
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexImage2D(GL_TEXTURE_2D, 0, 3,
		imag.GetNumCols(),
		imag.GetNumRows(), 0, GL_RGB, GL_UNSIGNED_BYTE,
		imag.ImageData());

	glGenTextures(1, &texture[6]);
	glBindTexture(GL_TEXTURE_2D, texture[6]);
	imag.LoadBmpFile("textura_luzComando.bmp");
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexImage2D(GL_TEXTURE_2D, 0, 3,
		imag.GetNumCols(),
		imag.GetNumRows(), 0, GL_RGB, GL_UNSIGNED_BYTE,
		imag.ImageData());
	
}

void changeInterpolationText(int flag) {
	if (flag == 6) {
		glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	}
	else {
		glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
	}
}

void initializeLightAmb(GLfloat x, GLfloat y, GLfloat z) {
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, luzGlobalCorAmb);

	float ambient[] = { 0.0f, 0.0f, 0.0f, 0.0f };
	float diffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	float specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	GLfloat position[] = { x, y, z, 1.0f };

	ambient[0] = luzR * intensidade;
	ambient[1] = luzG * intensidade;
	ambient[2] = luzB * intensidade;
	diffuse[0] = luzR * intensidade;
	diffuse[1] = luzG * intensidade;
	diffuse[2] = luzB * intensidade;
	specular[0] = luzR * intensidade;
	specular[1] = luzG * intensidade;
	specular[2] = luzB * intensidade;

	glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, specular);
	glLightfv(GL_LIGHT0, GL_POSITION, position);
}

void initializeSpotLights() {
	GLfloat aberturaFoco = 3.5;

	GLfloat Foco_direccao[] = { 0, 0, 1, 0 };	      //-Z
	GLfloat Foco1_cor[] = { 1, 1, 1, 1 };	          //Color of light
	GLfloat Foco_ak = 1.0;
	GLfloat Foco_al = 0.05f;
	GLfloat Foco_aq = 0.0f;
	GLfloat Foco_Expon = 1.0;		                  // Spot
	GLfloat Pos1[] = { 0.7f, 0.0f,  -10.0f, 1.0f };   

	//SpotLight
	glLightfv(GL_LIGHT1, GL_POSITION, Pos1);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, Foco1_cor);
	glLightf(GL_LIGHT1, GL_CONSTANT_ATTENUATION, Foco_ak);
	glLightf(GL_LIGHT1, GL_LINEAR_ATTENUATION, Foco_al);
	glLightf(GL_LIGHT1, GL_QUADRATIC_ATTENUATION, Foco_aq);
	glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, aberturaFoco);
	glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, Foco_direccao);
	glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, Foco_Expon);


	GLfloat Foco_direccao2[] = { 0, 0, 1, 0 };	     //-Z
	GLfloat Foco2_cor[] = { 1, 1,  1, 1 };           //Color of light
	GLfloat Foco_ak2 = 1.0;
	GLfloat Foco_al2 = 0.05f;
	GLfloat Foco_aq2 = 0.0f;
	GLfloat Foco_Expon2 = 1.0;		                 //Spot
	GLfloat Pos2[] = { -0.7f, 0.0f,  -10.0f, 1.0f };   

	//SpotLight
	glLightfv(GL_LIGHT2, GL_POSITION, Pos2);
	glLightfv(GL_LIGHT2, GL_DIFFUSE, Foco2_cor);
	glLightf(GL_LIGHT2, GL_CONSTANT_ATTENUATION, Foco_ak2);
	glLightf(GL_LIGHT2, GL_LINEAR_ATTENUATION, Foco_al2);
	glLightf(GL_LIGHT2, GL_QUADRATIC_ATTENUATION, Foco_aq2);
	glLightf(GL_LIGHT2, GL_SPOT_CUTOFF, aberturaFoco);
	glLightfv(GL_LIGHT2, GL_SPOT_DIRECTION, Foco_direccao2);
	glLightf(GL_LIGHT2, GL_SPOT_EXPONENT, Foco_Expon2);

	GLfloat Foco_direccao3[] = { 0, 0, 1, 0 };	     //-Z
	GLfloat Foco3_cor[] = { 1, 1,  1, 1 };           //Color of light
	GLfloat Foco_ak3 = 1.0;
	GLfloat Foco_al3 = 0.05f;
	GLfloat Foco_aq3 = 0.0f;
	GLfloat Foco_Expon3 = 1.0;		                 //Spot
	GLfloat Pos3[] = { 0.0f, 0.0f,  -10.0f, 1.0f };   

	//SpotLight
	glLightfv(GL_LIGHT3, GL_POSITION, Pos3);
	glLightfv(GL_LIGHT3, GL_DIFFUSE, Foco3_cor);
	glLightf(GL_LIGHT3, GL_CONSTANT_ATTENUATION, Foco_ak3);
	glLightf(GL_LIGHT3, GL_LINEAR_ATTENUATION, Foco_al3);
	glLightf(GL_LIGHT3, GL_QUADRATIC_ATTENUATION, Foco_aq3);
	glLightf(GL_LIGHT3, GL_SPOT_CUTOFF, aberturaFoco);
	glLightfv(GL_LIGHT3, GL_SPOT_DIRECTION, Foco_direccao3);
	glLightf(GL_LIGHT3, GL_SPOT_EXPONENT, Foco_Expon3);
}

void initialize(void){
	glClearColor(BLUUUUE);		//Clear
	glEnable(GL_DEPTH_TEST);	//Depth
	glShadeModel(GL_SMOOTH);	//Color Interpolation	
	glEnable(GL_NORMALIZE);


	initializeTexts();

	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_NORMAL_ARRAY);	

	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);
}

void drawMesh(GLfloat meshW, GLfloat meshH, GLfloat h) {
	glPushMatrix();
		glShadeModel(GL_FLAT);
		glTranslatef(-meshW/2.f, -meshH/2.f, -1);
		glRotatef(-90, 1, 0, 0);
	
		if (malha) {
			changeMaterial(3);

			glPushMatrix();
			glNormal3f(0, 1, 0);
			glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
			glBegin(GL_QUADS);

			for (int i = 0; i < dim - 1; i++) {
				for (int j = 0; j < dim - 1; j++) {
					GLfloat w0 = meshW * i / float(dim - 1);
					GLfloat h0 = meshH * j / float(dim - 1);
					GLfloat u0 = i / float(dim - 1);
					GLfloat v0 = j / float(dim - 1);

					GLfloat w1 = meshW * (i + 1) / float(dim - 1);
					GLfloat h1 = meshH * j / float(dim - 1);
					GLfloat u1 = (i + 1) / float(dim - 1);
					GLfloat v1 = j / float(dim - 1);

					GLfloat w2 = meshW * (i + 1) / float(dim - 1);
					GLfloat h2 = meshH * (j + 1) / float(dim - 1);
					GLfloat u2 = (i + 1) / float(dim - 1);
					GLfloat v2 = (j + 1) / float(dim - 1);

					GLfloat w3 = meshW * i / float(dim - 1);
					GLfloat h3 = meshH * (j + 1) / float(dim - 1);
					GLfloat u3 = i / float(dim - 1);
					GLfloat v3 = (j + 1) / float(dim - 1);

					glVertex3f(w0, h, h0);
					glVertex3f(w1, h, h1);
					glVertex3f(w2, h, h2);
					glVertex3f(w3, h, h3);
				}
			}
			glEnd();
			glPopMatrix();
		}

		changeMaterial(1);

		glPushMatrix();
			glEnable(GL_TEXTURE_2D);
			glNormal3f(0, 1, 0);          //normal 
			glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

			glBindTexture(GL_TEXTURE_2D, texture[6]);
			changeInterpolationText(6);

			glBegin(GL_QUADS);
			for (int i = 0; i < dim - 1; i++) {
				for (int j = 0; j < dim - 1; j++) {
					GLfloat w0 = meshW * i / float(dim - 1);
					GLfloat h0 = meshH * j / float(dim - 1);
					GLfloat u0 = i / float(dim - 1);
					GLfloat v0 = j / float(dim - 1);

					GLfloat w1 = meshW * (i + 1) / float(dim - 1);
					GLfloat h1 = meshH * j / float(dim - 1);
					GLfloat u1 = (i + 1) / float(dim - 1);
					GLfloat v1 = j / float(dim - 1);

					GLfloat w2 = meshW * (i + 1) / float(dim - 1);
					GLfloat h2 = meshH * (j + 1) / float(dim - 1);
					GLfloat u2 = (i + 1) / float(dim - 1);
					GLfloat v2 = (j + 1) / float(dim - 1);

					GLfloat w3 = meshW * i / float(dim - 1);
					GLfloat h3 = meshH * (j + 1) / float(dim - 1);
					GLfloat u3 = i / float(dim - 1);
					GLfloat v3 = (j + 1) / float(dim - 1);

					glTexCoord2f(u0, v0);
					glVertex3f(w0, h, h0);
					glTexCoord2f(u1, v1);
					glVertex3f(w1, h, h1);
					glTexCoord2f(u2, v2);
					glVertex3f(w2, h, h2);
					glTexCoord2f(u3, v3);
					glVertex3f(w3, h, h3);
				}
			}
			glEnd();
			glDisable(GL_TEXTURE_2D);
		glPopMatrix();

		glShadeModel(GL_SMOOTH);
	glPopMatrix();
}

void sphere(GLfloat radius, GLfloat r, GLfloat g, GLfloat b, GLint text, GLint mat=1) {
	if (text == 1) {
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, texture[0]);
		changeInterpolationText(text);
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	}

	changeMaterial(mat),


	glPushMatrix();
		GLUquadric* quad = gluNewQuadric();
		gluQuadricDrawStyle(quad, GLU_FILL);
		gluQuadricNormals(quad, GLU_SMOOTH);
		gluQuadricTexture(quad, GL_TRUE);
		gluSphere(quad, radius, 100, 20);
		gluDeleteQuadric(quad);
	glPopMatrix();
	
	if (text == 1) {
		glDisable(GL_TEXTURE_2D);
	}
}

void arrowbutton() {
	glVertexPointer(3, GL_FLOAT, 0, vertices2); 
	glNormalPointer(GL_FLOAT, 0, normais);
	int index, jndex;
	
	glColor3f(0.8, 0.8, 0.8);

	changeMaterial(2);

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	for (int i = 0; i < 2; i++) {
		glDrawElements(GL_POLYGON, 5, GL_UNSIGNED_INT, faces2top[i]);   
	}

	for (int i = 0; i < 5; i++) {
		glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, faces2lat[i]);  
	}

	for (int i = 0; i < 2; i++) {
		index = 15 * i;
		glBegin(GL_LINE_LOOP);
		for (int j = 0; j < 5; j++) {
			jndex = 3 * j;
			glVertex3f(vertices2[index + jndex], vertices2[index + jndex + 1], vertices2[index + jndex + 2]);
		}
		glEnd();
	}

	for (int j = 0; j < 5; j++) {
		glBegin(GL_LINE_LOOP);
		for (int i = 0; i < 2; i++) {
			glVertex3f(vertices2[15 * i + 3*j], vertices2[15 * i + 3*j + 1], vertices2[15 * i + 3*j + 2]);
		}
		glEnd();
	}
}

void cylinder(GLfloat radiusTOP, GLfloat radiusBOTTOM, GLfloat h, GLfloat r, GLfloat g, GLfloat b, GLint text) {
	if (text >= 1 && text <=5) {
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, texture[text]);
		changeInterpolationText(text);
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		changeMaterial(2);
	}
	else {
		changeMaterial(1);
	}

	glPushMatrix();
		glTranslatef(0, h / 2, 0);
		glRotatef(-90, 1, 0, 0);

		GLUquadric* quadT = gluNewQuadric();
		gluQuadricDrawStyle(quadT, GLU_FILL);
		gluQuadricNormals(quadT, GLU_SMOOTH);
		gluQuadricTexture(quadT, GL_TRUE);
		gluDisk(quadT, 0, radiusTOP, 60, 60);
		gluDeleteQuadric(quadT);
	glPopMatrix();

	if (text >= 1 && text <= 5) {
		glDisable(GL_TEXTURE_2D);
	}

	glPushMatrix();
		glTranslatef(0, -h / 2, 0);
		glRotatef(90, 1, 0, 0);

		GLUquadric* quadB = gluNewQuadric();
		gluQuadricDrawStyle(quadB, GLU_FILL);
		gluQuadricNormals(quadB, GLU_SMOOTH);
		gluQuadricTexture(quadB, GL_TRUE);
		gluDisk(quadB, 0, radiusBOTTOM, 60, 60);
		gluDeleteQuadric(quadB);
	glPopMatrix();

	if (text == 5) {
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		alpha = 0.2;
	}

	glPushMatrix();
		glRotatef(90, 1, 0, 0);
		glTranslatef(0, 0, -h / 2);

		GLUquadric* quad = gluNewQuadric();
		gluQuadricDrawStyle(quad, GLU_FILL);
		gluQuadricNormals(quad, GLU_SMOOTH);
		gluQuadricTexture(quad, GL_TRUE);
		gluCylinder(quad, radiusTOP, radiusBOTTOM, h, 60, 60);
		gluDeleteQuadric(quad);
	glPopMatrix();

	if (text == 5) {
		glDisable(GL_BLEND);
	}

}

void paraleliens(int material=1, int mesh=0) {
	glVertexPointer(3, GL_FLOAT, 0, vertices);
	glNormalPointer(GL_FLOAT, 0, normais);

	int index, jndex;

	changeMaterial(1);
	
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	for (int i = 0; i < 6; i++) {
		if (i == 5 && mesh==1) {
			drawMesh(4.375, 1.25, 0);
		}
		else {
			glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, faces[i]);   //draw one face
		}
	}

	changeMaterial(2);

	for (int i = 0; i < 6; i++) {
		index = 12 * i;
		glBegin(GL_LINE_LOOP);
		for (int j = 0; j < 4; j++) {
			jndex = 3 * j;
			glVertex3f(vertices[index + jndex], vertices[index + jndex + 1], vertices[index + jndex + 2]);
		}
		glEnd();
	}
}

void movButton(GLint index) {
	GLfloat limitsup = 0.86;
	GLfloat limitinf = 0.77;
	GLfloat incposBot = 0.02;

	if (flags[index] == true) {
		flags[index] = false;
		if (pos[index] - incposBot <= limitsup && pos[index] - incposBot >= limitinf) {
			pos[index] -= incposBot;
			glutPostRedisplay();
		}
	}
	else {
		if (pos[index] + incposBot <= limitsup && pos[index] + incposBot >= limitinf) {
			pos[index] += incposBot;
			glutPostRedisplay();
		}
	}
}

void movButtonPS4() {
	GLfloat limitsup = 0.625;
	GLfloat limitinf = 0.535;
	GLfloat incposBot = 0.02;

	if (flags[8] == true) {
		flags[8] = false;
		if (pos[8] - incposBot <= limitsup && pos[8] - incposBot >= limitinf) {
			pos[8] -= incposBot;
			glutPostRedisplay();
		}
	}
	else {
		if (pos[8] + incposBot <= limitsup && pos[8] + incposBot >= limitinf) {
			pos[8] += incposBot;
			glutPostRedisplay();
		}
	}
}

void drawButton(GLint index, GLfloat x, GLfloat y, GLfloat z, GLint flag, GLfloat rotate=0) {
	glPushMatrix();
		glTranslatef(0, pos[index], 0);
		glTranslatef(x, y, z);
		if (flag>=1 && flag<=4) {
			movButton(index);
			cylinder(0.2875, 0.2875, 0.3, 96 / 255.f, 96 / 255.f, 96 / 255.f, flag);
		}
		else if (flag==0) {
			movButton(index);
			glRotatef(rotate, 0, 1, 0);
			arrowbutton();
		}
		else if (flag==5) {
			movButtonPS4();
			cylinder(0.20, 0.20, 0.3, 96 / 255.f, 96 / 255.f, 96 / 255.f, flag);
		}
		else {
			printf("This flag doesn't exist\n");
		}
	glPopMatrix();
}

void drawJoystick(GLfloat xcord, GLint index) {
	glPushMatrix();
		glTranslatef(xcord, 0.54, 0.375);
		glRotatef(angJoystick[index][0], 1, 0, 0);
		glRotatef(angJoystick[index][1], 0, 0, 1);
		glTranslatef(-xcord, -0.54, 0);

		glTranslatef(xcord, 0.54, 0);

		glPushMatrix();
			glTranslatef(0, 0.3, 0);
			glScalef(0.1 * 2 / 3, 0.25, 0.1);
			paraleliens(1);
		glPopMatrix();

		glPushMatrix();
			glTranslatef(0, 0.15625 + 0.3, 0);
			glScalef(1, 0.25, 1);
			sphere(0.3, 96 / 255.f, 96 / 255.f, 96 / 255.f, 1);
		glPopMatrix();

		glPushMatrix();
			sphere(0.3, 96 / 255.f, 96 / 255.f, 96 / 255.f, 0, 2);
		glPopMatrix();
	glPopMatrix();
}

void drawBaseController() {
	glPushMatrix();
		//cylinder right diagonal
		glPushMatrix();
			glTranslatef(2.75, -0.3, 1.4);

			glRotatef(30, 0, 0, 1);
			glRotatef(-70, 1, 0, 0);
			glScalef(1.6, 1, 1);
			glPushMatrix();
				glTranslated(0, -1, 0);
				sphere(0.5, 0.8, 0.8, 0.8, 0);
			glPopMatrix();
			cylinder(0.75, 0.5, 2, 0.8, 0.8, 0.8, 0);
		glPopMatrix();

		//cylinder right
		glPushMatrix();
			glTranslatef(2.5, 0, 0);
			cylinder(1.2, 1.4, 1.72, 0.8, 0.8, 0.8, 0);
		glPopMatrix();

		//cylinder left diagonal
		glPushMatrix();
			glTranslatef(-2.75, -0.3, 1.4);

			glRotatef(-30, 0, 0, 1);
			glRotatef(-70, 1, 0, 0);
			glScalef(1.6, 1, 1);
			glPushMatrix();
				glTranslated(0, -1, 0);
				sphere(0.5, 0.8, 0.8, 0.8, 0);
			glPopMatrix();
			cylinder(0.75, 0.5, 2, 0.8, 0.8, 0.8, 0);
		glPopMatrix();

		//cylinder left
		glPushMatrix();
			glTranslatef(-2.5, 0, 0);
			cylinder(1.2, 1.4, 1.72, 0.8, 0.8, 0.8, 0);
		glPopMatrix();

		//base inicial
		paraleliens(1, 1);
	glPopMatrix();
}

void drawAxes()
{
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Eixo X
	glColor4f(RED);
	glBegin(GL_LINES);
	glVertex3i(0, 0, 0);
	glVertex3i(10, 0, 0);
	glEnd();
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Eixo Y
	glColor4f(GREEN);
	glBegin(GL_LINES);
	glVertex3i(0, 0, 0);
	glVertex3i(0, 10, 0);
	glEnd();
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Eixo Z
	glColor4f(BLUE);
	glBegin(GL_LINES);
	glVertex3i(0, 0, 0);
	glVertex3i(0, 0, 10);
	glEnd();
}

void drawScene() {	
	//base of controller
	drawBaseController();
	
	//left joystick
	drawJoystick(-0.75, 0);

	//right joystick
	drawJoystick(0.75, 1);

	//triangle
	drawButton(0, 2.5, 0, 0.575, 1);

	//circle
	drawButton(1, 3.075, 0, 0, 2);

	//square
	drawButton(2, 1.925, 0, 0, 3);

	//X
	drawButton(3, 2.5, 0, -0.575, 4);
	
	//up
	drawButton(4, -2.5, 0, -0.575, 0, 0);
	
	//right
	drawButton(5, -1.925, 0, 0, 0, -90);

	//down
	drawButton(6, -3.075, 0, 0, 0, 90);
	
	//left
	drawButton(7, -2.5, 0, 0.575, 0, 180);
	
	//PS4
	drawButton(8, 0, 0, 0.625, 5);
	
}

void projection(const char flag[], GLfloat xVP, GLfloat yVP, GLfloat xObs, GLfloat yObs, GLfloat zObs, GLfloat xOrient, GLfloat yOrient, GLfloat zOrient,  GLint on_off, GLfloat div = 1) {
	on_off_botoes = on_off;
	glViewport(xVP, yVP, wScreen/div, hScreen/div);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if (strcmp(flag, "Ortho") == 0) {
		glOrtho(-5, 5, -5, 5, -5, 5);
	}
	else if (strcmp(flag, "Perspective")==0) {
		gluPerspective(angZoom, (float)wScreen / hScreen, 0.1, 3 * zC);
	}
	gluLookAt(xObs, yObs, zObs, 0, 0, 0, xOrient, yOrient, zOrient);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glPushMatrix();
	//drawAxes();
	drawScene();
	glPopMatrix();
}

void display(void) {
	//============================== Clear the screen ===================================
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


	initializeSpotLights();
	if (views[0] == true) {
		projection("Ortho", 0, 0, 0, 4, 0, 0, 0, -1, 1);
	}
	else if (views[1] == true) {
		projection("Ortho", 0, 0, 4, 0, 0, 0, 1, 0, 1);
	}
	else if (views[2] == true) {
		projection("Ortho", 0, 0, 0, 0, 4, 0, 1, 0, 1);
	}
	else if (views[3] == true) {
		initializeLightAmb(obsP[1][0], obsP[1][1], obsP[1][2]);
		projection("Perspective", 0, 0, obsP[1][0], obsP[1][1], obsP[1][2], 0, 1, 0, 1);
	}
	else {
		initializeLightAmb(obsP[0][0], obsP[0][1], obsP[0][2]);
		R++;
		aVisao = (GLfloat)2 * R * PI / 180.f + 0.5 * PI;

		obsP[0][0] = rVisao * cos(aVisao);
		obsP[0][2] = rVisao * sin(aVisao);

		projection("Ortho", 0, 0, 0, 4, 0, 0, 0, -1, -1, 2.f);

		projection("Ortho", wScreen / 2.f, 0, 4, 0, 0, 0, 1, 0, -1, 2.f);

		projection("Ortho", wScreen / 2.f, hScreen / 2.f, 0, 0, 4, 0, 1, 0, -1, 2.f);

		projection("Perspective", 0, hScreen / 2.f, obsP[0][0], obsP[0][1], obsP[0][2], 0, 1, 0, 1, 2.f);
	}

	

	//. . . . . . . . . . . . . . . . . . . . .  Actualizacao
	glutSwapBuffers();
}

//=========================== Keys ============================
void keyboard(unsigned char key, int x, int y) {
	switch (key) {
		//joystick left
		//up
		case 'w':
			if (angJoystick[0][0] + incAngJoystick <= 35 && angJoystick[0][0] + incAngJoystick >= -35 && on_off_botoes == 1) {
				angJoystick[0][0] += incAngJoystick;
				glutPostRedisplay();
			}
			break;

		//down
		case 's':
			if (angJoystick[0][0] - incAngJoystick <= 35 && angJoystick[0][0] - incAngJoystick >= -35 && on_off_botoes == 1) {
				angJoystick[0][0] -= incAngJoystick;
				glutPostRedisplay();
			}
			break;

		//left
		case 'a':
			if (angJoystick[0][1] + incAngJoystick <= 35 && angJoystick[0][1] + incAngJoystick >= -35 && on_off_botoes == 1) {
				angJoystick[0][1] += incAngJoystick;
				glutPostRedisplay();
			}
			break;

		//right
		case 'd':
			if (angJoystick[0][1] - incAngJoystick <= 35 && angJoystick[0][1] - incAngJoystick >= -35 && on_off_botoes == 1) {
				angJoystick[0][1] -= incAngJoystick;
				glutPostRedisplay();
			}
			break;
		


		//joystick right
		//up
		case '8':
			if (angJoystick[1][0] + incAngJoystick <= 35 && angJoystick[1][0] + incAngJoystick >= -35 && on_off_botoes == 1) {
				angJoystick[1][0] += incAngJoystick;
				glutPostRedisplay();
			}
			break;

		//down
		case '5':
			if (angJoystick[1][0] - incAngJoystick <= 35 && angJoystick[1][0] - incAngJoystick >= -35 && on_off_botoes == 1) {
				angJoystick[1][0] -= incAngJoystick;
				glutPostRedisplay();
			}
			break;

		//left
		case '4':
			if (angJoystick[1][1] + incAngJoystick <= 35 && angJoystick[1][1] + incAngJoystick >= -35 && on_off_botoes == 1) {
				angJoystick[1][1] += incAngJoystick;
				glutPostRedisplay();
			}
			break;
		
		//right
		case '6':
			if (angJoystick[1][1] - incAngJoystick <= 35 && angJoystick[1][1] - incAngJoystick >= -35 && on_off_botoes == 1) {
				angJoystick[1][1] -= incAngJoystick;
				glutPostRedisplay();
			}
			break;

		//right buttons
		//X
		case 'k':
			if (on_off_botoes == 1) {
				flags[0] = true;
			}
			break;

		//Circle
		case 'l':
			if (on_off_botoes == 1) {
				flags[1] = true;
			}
			break;

		//Square
		case 'j':
			if (on_off_botoes == 1) {
				flags[2] = true;
			}
			break;

		//Triangle
		case 'i':
			if (on_off_botoes == 1) {
				flags[3] = true;
			}
			break;

		//left buttons
		//Up
		case 't':
			if (on_off_botoes == 1) {
				flags[4] = true;
			}
			break;

		//Right
		case 'h':
			if (on_off_botoes == 1) {
				flags[5] = true;
			}
			break;

		//Down
		case 'f':
			if (on_off_botoes == 1) {
				flags[6] = true;
			}
			break;

		//Left
		case 'g':
			if (on_off_botoes == 1) {
				flags[7] = true;
			}
			break;

		//middle buttons
		//PS4 button
		case ' ':
			if (on_off_botoes == 1) {
				flags[8] = true;
			}
			break;

		//View Buttons
		//view1
		case 'v':
			if (views[0] == false) {
				views[0] = true;
				views[1] = false;
				views[2] = false;
				views[3] = false;
			}
			else {
				views[0] = false;
			}
			break;

		//view2
		case 'b':
			if (views[1] == false) {
				views[0] = false;
				views[1] = true;
				views[2] = false;
				views[3] = false;
			}
			else {
				views[1] = false;
			}
			break;

		//view3
		case 'n':
			if (views[2] == false) {
				views[0] = false;
				views[1] = false;
				views[2] = true;
				views[3] = false;
			}
			else {
				views[2] = false;
			}
			break;

		//view4
		case 'm':
			if (views[3] == false) {
				views[0] = false;
				views[1] = false;
				views[2] = false;
				views[3] = true;
			}
			else {
				views[3] = false;
			}
			break;

		case '1':
			foco = !foco;
			if (foco) {
				glEnable(GL_LIGHT1);
				glEnable(GL_LIGHT2);
				glEnable(GL_LIGHT3);
				glDisable(GL_LIGHT0);
			}
			else {
				glDisable(GL_LIGHT1);
				glDisable(GL_LIGHT2);
				glDisable(GL_LIGHT3);
				glEnable(GL_LIGHT0);
			}
			glutPostRedisplay();
			break;

		case '2':
			intensidade -= 0.1;
			if (intensidade < 0) intensidade = 0;
			glutPostRedisplay();
			break;

		case '3':
			intensidade += 0.1;
			if (intensidade > 1.1) intensidade = 1;
			glutPostRedisplay();
			break;

		case '0':
			malha = !malha;
			glutPostRedisplay();
			break;

		//Change the color of pontual light
		case 'z':
			luzR = (GLint)(luzR + 1) % 2;
			glutPostRedisplay();
			break;
		case 'x':
			luzG = (GLint)(luzG + 1) % 2;
			glutPostRedisplay();
			break;
		case 'c':
			luzB = (GLint)(luzB + 1) % 2;
			glutPostRedisplay();
			break;

		case 'r':
			dim++;
			if (dim > 256) dim = 256;
			glutPostRedisplay();
			break;
		case 'y':
			dim--;
			if (dim < 2) dim = 2;
			glutPostRedisplay();
			break;


		case 'q':
			ks += 8;
			if (ks > 120) {
				ks = 120;
			}
			glutPostRedisplay();
			break;

		case 'e':
			ks -= 8;
			if (ks < 8) {
				ks = 8;
			}
			glutPostRedisplay();
			break;

		

		case 27:
			exit(0);
			break;
	}
}

void teclasNotAscii(int key, int x, int y) {
	if (key == GLUT_KEY_UP)
		obsP[1][1] += 0.2;
	if (key == GLUT_KEY_DOWN)
		obsP[1][1] -= 0.2;
	if (key == GLUT_KEY_LEFT)
		R2--;
	if (key == GLUT_KEY_RIGHT)
		R2++;

	if (obsP[1][1] > yC)
		obsP[1][1] = yC;
	if (obsP[1][1] < -yC)
		obsP[1][1] = -yC;

	aVisao2 = (GLfloat)2 * R2 * PI/180.f + 0.5 * PI;

	obsP[1][0] = rVisao * cos(aVisao2);
	obsP[1][2] = rVisao * sin(aVisao2);

	glutPostRedisplay();
}

void Timer(int value)
{
	glutPostRedisplay();
	glutTimerFunc(msec, Timer, 1);
}

void PrintCommands() {
	puts(" =============== KEYS 1ST GOAL ================                    =============== KEYS 2ND GOAL ================");
	puts(" | Left Koystick:       | Right Joystick      |                    | Turn on/off focos - 1                      |");
	puts(" | Up - W               | Up - 8              |                    | Decrease spot light resolution - Y         |");
	puts(" | Down - S             | Down - 5            |                    | Increase spot light resolution - R         |");
	puts(" | Right - D            | Right - 6           |                    | Turn on/off grid of spotlight - 0          |");
	puts(" | Left - A             | Left - 4            |                    |--------------------------------------------|");
	puts(" |--------------------------------------------|                    | Decrease spot light intensity - 2          |");
	puts(" | Left Buttons:        | Right Buttons:      |                    | Increase spot light intensity - 3          |");
	puts(" | Up - T               | Up - I              |                    | Turn on/off the red component - Z          |");
	puts(" | Down - G             | Down - K            |                    | Turn on/off the green component - X        |");
	puts(" | Right - H            | Right - L           |                    | Turn on/off the blue component - C         |");
	puts(" | Left - F             | Left - J            |                    |--------------------------------------------|");
	puts(" |         PS4 Button - (space bar)           |                    | Increase material coefficient - E          |");
	puts(" |--------------------------------------------|                    | Decrease material coefficient - Q          |");
	puts(" |                Observer:                   |                    ==============================================");
	puts(" | (O) Up - V             (O) Side - B        |");
	puts(" | (O) Front - N          (P) Side - M        |");
	puts(" | Move right - (key right)                   |");
	puts(" | Mover left - (key left)                    |");
	puts(" | Mover up - (key up)                        |");
	puts(" | Mover down - (key down)                    |");
	puts(" ==============================================");

}

//======================== MAIN===============================
int main(int argc, char** argv) {
	PrintCommands();

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(wScreen, hScreen);
	glutInitWindowPosition(300, 100);
	glutCreateWindow("{joaosilvba@dei.uc.pt}");

	initialize();

	glutSpecialFunc(teclasNotAscii);
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutTimerFunc(msec, Timer, 1);

	glutMainLoop();

	return 0;
}


