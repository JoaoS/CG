#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <cstring>
#include <iostream>
#ifdef __APPLE__
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include "RgbImage.h"
#include <unistd.h>
#include <time.h>
#include "mainquerida.h"





//---------------------------------------------------------Niveis
void init_levels()
{       
        //level 1
        levels[0].n_troncos = N_TRONCOS;
        GLfloat troncoPos[N_TRONCOS][3] = {{3.01,0.2,3.2},{3.01,0.15,5.0},{3.01,0.1,6.25},{4.4,0.15,3.01},{3.9,0.15,4.9},{4.4,0.2,6},{3.7,0.15,6.9},{4.5,0.2,5.8},{5,0.2,4},{5.2,0.1,4},{6,0.1,4.5}};
        memcpy(levels[0].troncoPos, troncoPos, sizeof(GLfloat) * 3 * N_TRONCOS);
        GLfloat troncoRot[N_TRONCOS][4] =  {{90, 0, 1, 0},{90, 0, 1, 0},{90, 0, 1, 0},{90,0,0,1},{90,0,0,1},{90,0,0,1},{90,0,1,0},{90,0,1,0},{90,0,0,1},{90,0,1,0},{90,0,0,1}};
        memcpy(levels[0].troncoRot, troncoRot, sizeof(GLfloat) * 4 * N_TRONCOS);
        GLfloat troncoDim[N_TRONCOS][3] = {{0.2,0.2,1.25},{0.15,0.15,0.75},{0.1,0.1,0.5},{0.15,0.15,1.25},{0.15,0.15,0.60},{0.2,0.2,1},{0.15,0.15,0.5},{0.2,0.2,2.1},{0.2,0.2,1.25},{0.1,0.1,1.25},{0.1,0.1,0.75}};
        memcpy(levels[0].troncoDim, troncoDim, sizeof(GLfloat) * 3 * N_TRONCOS);
        GLfloat diskRadius[N_TRONCOS] = {0.2,0.15,0.1,0.15,0.15,0.2,0.15,0.2,0.2,0.1,0.1};
        memcpy(levels[0].diskRadius, diskRadius, sizeof(GLfloat) * N_TRONCOS);
        GLfloat tunelPos[3] = {6.8,0.2,5.85};
        memcpy(levels[0].tunelPos, tunelPos, sizeof(GLfloat) * 3);
        GLfloat tunelDim[3] = {0.2,0.2,1.0};
        memcpy(levels[0].tunelDim, tunelDim, sizeof(GLfloat) * 3);
        GLfloat level_entrance[2] = {0.0,3.65};
        memcpy(levels[0].level_entrance, level_entrance, sizeof(GLfloat) * 2);
        GLfloat level_exit[4] = {6.75,6.95,6.85,7.0};
        memcpy(levels[0].level_exit, level_exit, sizeof(GLfloat) * 4);
        //level 2
        levels[1].n_troncos = N_TRONCOS2;
        GLfloat troncoPos2[N_TRONCOS2][3] = {{3.2,0.2,6.0},{3.6,0.2,6.0},{4.0,0.2,6.0},{3.01,0.15,5.0},{3.01,0.15,4.70},{3.01,0.15,4.40},{5.0,1.0,6.0},{5.3,1.0,6.0},{5.6,1.0,6.0},{6.7,1.0,6.0},{6.4,1.0,6.0},{3.81,1.0,3.60},{4.11,1.0,3.60},{4.41,1.0,3.60},{4.71,1.0,3.60},{5.01,1.0,3.60},{5.31,1.0,3.60},{5.61,1.0,3.60},{5.91,1.0,3.60},{6.21,1.0,3.60},{5.2,1.0,5.6},{5.2,1.0,5.2},{5.2,1.0,4.8},{5.2,1.0,4.4},{5.2,1.0,4.0},{6.24,0.1,4.5},{6.24,0.1,4.7},{6.24,0.1,4.9},{6.24,0.1,5.1},{6.24,0.1,5.3}};
        memcpy(levels[1].troncoPos, troncoPos2, sizeof(GLfloat) * 3 * N_TRONCOS2);
        GLfloat troncoRot2[N_TRONCOS2][4] =  {{90, 0, 0, 1},{90, 0, 0, 1},{90, 0, 0, 1},{90, 0, 1, 0},{90, 0, 1, 0},{90, 0, 1, 0},{90, 1, 0, 0},{90, 1, 0, 0},{90, 1, 0, 0},{90, 1, 0, 0},{90, 1, 0, 0},{90, 1, 0, 0},{90, 1, 0, 0},{90, 1, 0, 0},{90, 1, 0, 0},{90, 1, 0, 0},{90, 1, 0, 0},{90, 1, 0, 0},{90, 1, 0, 0},{90, 1, 0, 0},{90, 1, 0, 0},{90, 1, 0, 0},{90, 1, 0, 0},{90, 1, 0, 0},{90, 1, 0, 0},{90,0, 1, 0},{90,0, 1, 0},{90,0, 1, 0},{90,0, 1, 0},{90,0, 1, 0}};
        memcpy(levels[1].troncoRot, troncoRot2, sizeof(GLfloat) * 4 * N_TRONCOS2);
        GLfloat troncoDim2[N_TRONCOS2][3] = {{0.2,0.2,1.0},{0.2,0.2,1.0},{0.2,0.2,1.0},{0.15,0.15,1.0},{0.15,0.15,1.0},{0.15,0.15,1.0},{0.15,0.15,1.0},{0.15,0.15,1.0},{0.15,0.15,1.0},{0.15,0.15,1.0},{0.15,0.15,1.0},{0.15,0.15,1.0},{0.15,0.15,1.0},{0.15,0.15,1.0},{0.15,0.15,1.0},{0.15,0.15,1.0},{0.15,0.15,1.0},{0.15,0.15,1.0},{0.15,0.15,1.0},{0.15,0.15,1.0},{0.2,0.2,1.0},{0.2,0.2,1.0},{0.2,0.2,1.0},{0.2,0.2,1.0},{0.2,0.2,1.0},{0.1,0.1,0.75},{0.1,0.1,0.75},{0.1,0.1,0.75},{0.1,0.1,0.75},{0.1,0.1,0.75}};
        memcpy(levels[1].troncoDim, troncoDim2, sizeof(GLfloat) * 3 * N_TRONCOS2);
        GLfloat diskRadius2[N_TRONCOS2] = {0.2,0.2,0.2,0.15,0.15,0.15,0.15,0.15,0.15,0.15,0.15,0.15,0.15,0.15,0.15,0.15,0.15,0.15,0.15,0.15,0.2,0.2,0.2,0.2,0.1,0.1,0.1,0.1,0.1,0.1};
        memcpy(levels[1].diskRadius, diskRadius2, sizeof(GLfloat) * N_TRONCOS2);
        GLfloat tunelPos2[3] = {6,0.2,5.85};
        memcpy(levels[1].tunelPos, tunelPos2, sizeof(GLfloat) * 3);
        GLfloat tunelDim2[3] = {0.2,0.2,1.0};
        memcpy(levels[1].tunelDim, tunelDim2, sizeof(GLfloat) * 3);
        GLfloat level_entrance2[2] = {4.30,4.70};
        memcpy(levels[1].level_entrance, level_entrance2, sizeof(GLfloat) * 2);
        GLfloat level_exit2[4] = {5.85,6.10,6.85,7.05};
        memcpy(levels[1].level_exit, level_exit2, sizeof(GLfloat) * 4);
        //level 3
        levels[2].n_troncos = N_TRONCOS3;
        GLfloat troncoPos3[N_TRONCOS3][3] = {{4.0,1.0,6.8},{4.4,1.0,6.8},{4.8,1.0,6.8},{5.2,1.0,6.8},{5.99,0.15,6.0},{5.99,0.15,6.3},{5.99,0.15,6.6},{5.99,0.15,6.9},{5.5,0.15,3.7},{5.5,0.15,4.0},{5.5,0.15,4.3},{5.2,0.2,4.3},{4.8,0.2,4.3},{5.0,0.55,4.3},{3.01,0.1,5.3},{3.01,0.1,5.5},{3.01,0.1,5.7},{4.7,1.0,3.1},{4.7,1.0,3.3},{4.7,1.0,3.5},{3.01,0.15,3.15},{3.01,0.15,3.45},{3.01,0.15,3.75},{4.4,1.0,4.6},{4.1,1.0,4.6},{3.8,1.0,4.6},{5.2,1.0,6.4},{5.2,1.0,6.1},{5.2,1.0,5.8},{5.2,1.0,5.5}};
        memcpy(levels[2].troncoPos, troncoPos3, sizeof(GLfloat) * 3 * N_TRONCOS3);
        GLfloat troncoRot3[N_TRONCOS3][4] =  {{90, 1, 0, 0},{90, 1, 0, 0},{90, 1, 0, 0},{90, 1, 0, 0},{90, 0, 1, 0},{90, 0, 1, 0},{90, 0, 1, 0},{90, 0, 1, 0},{90, 0, 1, 0},{90, 0, 1, 0},{90, 0, 1, 0},{90, 0, 0, 1},{90, 0, 0, 1},{90, 0, 0, 1},{90, 0, 1, 0},{90, 0, 1, 0},{90, 0, 1, 0},{90, 1, 0, 0},{90, 1, 0, 0},{90, 1, 0, 0},{90, 0, 1, 0},{90, 0, 1, 0},{90, 0, 1, 0},{90, 1,0 , 0},{90, 1,0 , 0},{90, 1,0 , 0},{90, 1,0 , 0},{90, 1,0 , 0},{90, 1,0 , 0},{90, 1,0 , 0}};
        memcpy(levels[2].troncoRot, troncoRot3, sizeof(GLfloat) * 4 * N_TRONCOS3);
        GLfloat troncoDim3[N_TRONCOS2][3] = {{0.2,0.2,1.0},{0.2,0.2,1.0},{0.2,0.2,1.0},{0.2,0.2,1.0},{0.15,0.15,1.0},{0.15,0.15,1.0},{0.15,0.15,1.0},{0.15,0.15,1.0},{0.15,0.15,1.0},{0.15,0.15,1.0},{0.15,0.15,1.0},{0.2,0.2,1.0},{0.2,0.2,1.0},{0.2,0.2,1.0},{0.1,0.1,1.0},{0.1,0.1,1.0},{0.1,0.1,1.0},{0.1,0.1,1.0},{0.1,0.1,1.0},{0.1,0.1,1.0},{0.15,0.15,1.0},{0.15,0.15,1.0},{0.15,0.15,1.0},{0.15,0.15,1.0},{0.15,0.15,1.0},{0.15,0.15,1.0},{0.15,0.15,1.0},{0.15,0.15,1.0},{0.15,0.15,1.0},{0.15,0.15,1.0}};
        memcpy(levels[2].troncoDim, troncoDim3, sizeof(GLfloat) * 3 * N_TRONCOS3);
        GLfloat diskRadius3[N_TRONCOS2] = {0.2,0.2,0.2,0.2,0.15,0.15,0.15,0.15,0.15,0.15,0.15,0.2,0.2,0.2,0.1,0.1,0.1,0.1,0.1,0.1,0.15,0.15,0.15,0.15,0.15,0.15,0.15,0.15,0.15};
        memcpy(levels[2].diskRadius, diskRadius3, sizeof(GLfloat) * N_TRONCOS3);
        GLfloat tunelPos3[3] = {3.4,0.35,6.5};
        memcpy(levels[2].tunelPos, tunelPos3, sizeof(GLfloat) * 3);
        GLfloat tunelDim3[3] = {0.35,0.35,0.5};
        memcpy(levels[2].tunelDim, tunelDim3, sizeof(GLfloat) * 3);
        GLfloat level_entrance3[2] = {5.45,5.90};
        memcpy(levels[2].level_entrance, level_entrance3, sizeof(GLfloat) * 2);
        GLfloat level_exit3[4] = {3.0,3.65,6.95,7.05};
        memcpy(levels[2].level_exit, level_exit3, sizeof(GLfloat) * 4);

}

//……………………………………………………………………………………………………………………………………………………… Iluminacao
void initLights(void)
{
	/*Ambiente*/
	//glLightModelfv(GL_LIGHT_MODEL_AMBIENT, luzGlobalCor);
    /* Teto */
    glLightfv(GL_LIGHT0, GL_POSITION, localPos);
    glLightfv(GL_LIGHT0, GL_AMBIENT, localCor);
    glLightf(GL_LIGHT0, GL_CONSTANT_ATTENUATION, localAttCon);
    glLightf(GL_LIGHT0, GL_LINEAR_ATTENUATION, localAttLin);
    glLightf(GL_LIGHT0, GL_QUADRATIC_ATTENUATION, localAttQua);
    /* Foco */
    glLightfv(GL_LIGHT1, GL_POSITION, focoPini);
    glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, focoDir);
    glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, focoExp);
    glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, focoCut);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, focoCorDif);
    glLightfv(GL_LIGHT1, GL_SPECULAR, focoCorEsp);
	
}

void criaDefineTexturas()
{

    //textura com o blend activado, tem de ser a primeira a ser carregada senão o resto fica com uma cor esquesita
    glGenTextures(1, &tex[5]);
    glBindTexture(GL_TEXTURE_2D, tex[5]);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_BLEND);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    imag.LoadBmpFile("mirror.bmp");
    glTexImage2D(GL_TEXTURE_2D, 0, 3, imag.GetNumCols(),imag.GetNumRows(), 0, GL_RGB, GL_UNSIGNED_BYTE,imag.ImageData());

    //----------------------------------------- Chao y=0 nivel 1
    glGenTextures(1, &tex[0]);
    glBindTexture(GL_TEXTURE_2D, tex[0]);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    imag.LoadBmpFile("grass1.bmp");
    glTexImage2D(GL_TEXTURE_2D, 0, 3, imag.GetNumCols(),imag.GetNumRows(), 0, GL_RGB, GL_UNSIGNED_BYTE,imag.ImageData());
    //----------------------------------------- obstaculos nivel 1
    glGenTextures(1, &tex[1]);
    glBindTexture(GL_TEXTURE_2D, tex[1]);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    imag.LoadBmpFile("wood.bmp");
    glTexImage2D(GL_TEXTURE_2D, 0, 3, imag.GetNumCols(),imag.GetNumRows(), 0, GL_RGB, GL_UNSIGNED_BYTE,imag.ImageData());
    //----------------------------------------- Chao y=0 nivel 2
    glGenTextures(1, &tex[2]);
    glBindTexture(GL_TEXTURE_2D, tex[2]);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    imag.LoadBmpFile("paver.bmp");
    glTexImage2D(GL_TEXTURE_2D, 0, 3, imag.GetNumCols(),imag.GetNumRows(), 0, GL_RGB, GL_UNSIGNED_BYTE,imag.ImageData());
    //----------------------------------------- obstaculos nivel 2
    glGenTextures(1, &tex[3]);
    glBindTexture(GL_TEXTURE_2D, tex[3]);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    imag.LoadBmpFile("aluminium.bmp");
    glTexImage2D(GL_TEXTURE_2D, 0, 3, imag.GetNumCols(),imag.GetNumRows(), 0, GL_RGB, GL_UNSIGNED_BYTE,imag.ImageData());
     //----------------------------------------- Chao y=0 nivel 3
    glGenTextures(1, &tex[4]);
    glBindTexture(GL_TEXTURE_2D, tex[4]);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    imag.LoadBmpFile("futuristic.bmp");
    glTexImage2D(GL_TEXTURE_2D, 0, 3, imag.GetNumCols(),imag.GetNumRows(), 0, GL_RGB, GL_UNSIGNED_BYTE,imag.ImageData());


}

void init(void)
{
	glClearColor(WHITE);
    glShadeModel(GL_SMOOTH);
    glEnable(GL_COLOR_MATERIAL);

    glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE ); 
    criaDefineTexturas();
    initLights();
    glEnable(GL_LIGHTING);  
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);    
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    init_levels();
}
	

//======================================================================== DISPLAY
void desenhaTexto(char *string, GLfloat x, GLfloat y, GLfloat z,GLint size) 
{  
    glDisable(GL_BLEND);
    glColor3f(1.0,1.0,1.0);
	glRasterPos3f(x,y,z); 
	while(*string)
	{  
        if(size ==12)
        {
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, *string++); 
        }
        else if(size ==18)
        {
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *string++);  
        }
        else
        {
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *string++);
        }
    }
    glEnable(GL_BLEND);
}

//desenha um quadrado de lado quadsize  e normal x=1, y=2, z=3
void quad(int normal,int size,int texture, int teste)
{
    GLint i,j;
    float med_dim=(float)floor_dim/2;
    if(texture ==1)  /*se for para aplicar textura*/
    {
        glEnable(GL_TEXTURE_2D);
        if(level==0)
        {
            glBindTexture(GL_TEXTURE_2D,tex[0]);
        }
        else if(level == 1)
        {    
            glBindTexture(GL_TEXTURE_2D,tex[2]);
        }
        else
        {
            glBindTexture(GL_TEXTURE_2D,tex[4]);
        }    
        glPushMatrix();
        glBegin(GL_QUADS);

        for (int i=0;i<floor_dim*floorsize;i++)//preenche para z maior
        {   
            for (int j=0;j<floor_dim*floorsize;j++)//preenche para x maior
            {
                glNormal3f(0,1,0);
                glTexCoord2f((float)j/floor_dim,(float)i/floor_dim);              
                glVertex3d((float)j/med_dim,0,(float)i/med_dim);                
                glTexCoord2f((float)(j+1)/floor_dim,(float)i/floor_dim);              
                glVertex3d((float)(j+1)/med_dim,0,(float)i/med_dim);                    
                glTexCoord2f((float)(j+1)/floor_dim,(float)(i+1)/floor_dim);
                glVertex3d((float)(j+1)/med_dim,0,(float)(i+1)/med_dim);          
                glTexCoord2f((float)j/floor_dim,(float)(i+1)/floor_dim);
                glVertex3d((float)j/med_dim,0,(float)(i+1)/med_dim);

                if(teste==2 && j==31)
                break;
            }
            if(teste==1 && i==31)
                break;
           
        }

        glEnd();
        glPopMatrix();
        glDisable(GL_TEXTURE_2D);
    }
    else
    {    
        glBegin(GL_QUADS);
        for (i=0;i<floor_dim*multiplier;i++)
        {   
            for (j=0;j<floor_dim*multiplier;j++)
            {   
                switch(normal)
                {
                    case 1:
                        glNormal3f(1, 0, 0); // definição da normal ao polígono 
                        break;
                    case 2:
                        glNormal3f(0, 1, 0); // definição da normal ao polígono 
                        break;
                    case 3:
                        glNormal3f(0, 0, 1); // definição da normal ao polígono 
                        break;
                }
                glVertex3d((float)j/med_dim,0,(float)i/med_dim); //r[0]
                glVertex3d((float)(j+1)/med_dim,0,(float)i/med_dim); // r[1]
                glVertex3d((float)(j+1)/med_dim,0,(float)(i+1)/med_dim);
                glVertex3d((float)j/med_dim,0,(float)(i+1)/med_dim);
            }
        }
        glEnd();
    }
}

void draw_troncos(GLint k,GLint level)
{
    if(level ==0)
    {    
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D,tex[1]);	
    }
    else if(level ==1)
    {   
        glEnable(GL_TEXTURE_2D);
        glColor4f(GRAY2);
        glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE); // blending + textura
        glBindTexture(GL_TEXTURE_2D,tex[3]);   
    }
    else
    {
        if(ascendente == 1)
        {
            if(lvl3_colors[k][3]<0.5)
            {
                lvl3_colors[k][3]+=0.0005;            
            }
            else
            {
                lvl3_colors[k][3]+=0.001; 
            }   
            if(lvl3_colors[k][3]>1.0)
            {
                ascendente = 0;
            }
        }
        else
        {   

            lvl3_colors[k][3]-=0.001;
            if(lvl3_colors[k][3]<0.0)
            {
                ascendente = 1;
            }
        }
        glEnable(GL_BLEND);  
        glColor4f(lvl3_colors[k][0],lvl3_colors[k][1],lvl3_colors[k][2],lvl3_colors[k][3]);
    }
    glPushMatrix();	
        /*desenho do cilindro*/	
		glTranslatef(levels[level].troncoPos[k][0],levels[level].troncoPos[k][1],levels[level].troncoPos[k][2]);
		glRotatef (levels[level].troncoRot[k][0],levels[level].troncoRot[k][1],levels[level].troncoRot[k][2],levels[level].troncoRot[k][3]);
		GLUquadricObj*  y = gluNewQuadric( );		
		gluQuadricDrawStyle(y, GLU_FILL);			
		gluQuadricNormals(y, GLU_SMOOTH);   		
		gluQuadricTexture(y,GL_TRUE);				
		gluCylinder(y,levels[level].troncoDim[k][0],levels[level].troncoDim[k][1],levels[level].troncoDim[k][2],32,32);
		/*desenho dos discos que tapam a extremidades do cilindro*/   
        gluDisk(y, 0.0, levels[level].diskRadius[k], 32, 32);
		glTranslatef(0,0,levels[level].troncoDim[k][2]);
		gluDisk(y, 0.0, levels[level].diskRadius[k], 32, 32);			
		gluDeleteQuadric(y);						
	glPopMatrix();
	glDisable(GL_TEXTURE_2D);
       glDisable(GL_BLEND);  
}


void draw_level(GLint level)
{
    for(int k =0;k<levels[level].n_troncos;k++)
        draw_troncos(k,level);
    /*desenho do tunel*/  
    if(level ==0)
    {    
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D,tex[1]);    
    }
    else if(level ==1)
    {   
        glEnable(GL_TEXTURE_2D);
        glColor4f(GRAY2);
        glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE); // blending + textura
        glBindTexture(GL_TEXTURE_2D,tex[3]);   
    }    
    glPushMatrix();     
        glTranslatef(levels[level].tunelPos[0],levels[level].tunelPos[1],levels[level].tunelPos[2]);
        GLUquadricObj*  y = gluNewQuadric( );       
        gluQuadricDrawStyle(y, GLU_FILL);           
        gluQuadricNormals(y, GLU_SMOOTH);           
        gluQuadricTexture(y,GL_TRUE);               
        gluCylinder(y,levels[level].tunelDim[0],levels[level].tunelDim[1],levels[level].tunelDim[2],32,32);       
        gluDeleteQuadric(y);                        
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
}

void quadradito(){

    //atras
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,tex[0]);
    glPushMatrix();
        glColor4f(VERMELHO);
        glNormal3f(0,0,1); 
       
        glTranslatef(3, 0, 3);
        glRotatef(-90,1,0,0);
        glBegin(GL_QUADS); 
            glTexCoord2f(0,0); 
            glVertex3d(0,0,0);

            glTexCoord2f(0,1); 
            glVertex3d(5,0,0);
        
            glTexCoord2f(1,0);
            glVertex3d(5,0,5);

            glTexCoord2f(1,1);
            glVertex3d(0,0,5);  
        glEnd();
    glPopMatrix();

}

void  drawReflectionPanel(int x,int z, int position){

    //desenha o painel reflector e
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,tex[5]);
    glPushMatrix();
        
        if(x>=0){
            glTranslatef(x,0,position);
            glRotatef(270,1,0,0);
        }
        else{

            glTranslatef(z,0,position);
            glRotatef(-270,0,0,1);
        }

        glBegin(GL_QUADS);

        if(x>=0)
            glNormal3f(0, 0, 1);//se estiver a desenhar em x a normal é em Z
        else
            glNormal3f(1, 0, 0);//se não é em Z
        
        glTexCoord2f(0,0);
        glVertex3d(0, 0, 0);
                        
        glTexCoord2f(0,1);
        glVertex3d(2, 0, 0);
                            
        glTexCoord2f(1,1);
        glVertex3d(2, 0, 2);
                        
        glTexCoord2f(1,0);
        glVertex3d(0, 0, 2);
        glEnd();
        
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);


}
void drawEdges(){


    int flag=0;

    //desenha os planos em z
    for(int i=0;i<10;i+=2){

        drawReflectionPanel(i,0,0);//desenha z=0
        drawReflectionPanel(i,0,10);//z=10

        drawReflectionPanel(-1,0,i);//desenha z=0
        drawReflectionPanel(-1,10,i);//desenha z=0

    }

}


void reflection(){

    glPushMatrix();
        //glRotatef(-90,1,0,0);
        quad(2,1,1,0);
    glPopMatrix();

    //REFLEXÃO 
    //1. Activa o uso do stencil buffer
    glEnable(GL_STENCIL_TEST);
    //2. Nao escreve no color buffer - desativar
    glColorMask(GL_FALSE, GL_FALSE,GL_FALSE, GL_FALSE);
    //3. Torna inactivo o teste de profundidade                                                 
    glDisable(GL_DEPTH_TEST);
    //4. Coloca a 1 todos os pixels no stencil buffer que representam o chão. A combinaçao desenhaChao + StencilFunc + StencilOp e que me da a mascara. A area de desenho, que vai ser colocada  1, e dada pelo desenhaChao.
    glStencilFunc(GL_ALWAYS, 1, 1);
    glStencilOp(GL_KEEP, GL_KEEP, GL_REPLACE);
    //5. Desenhar o quadrado
    drawEdges();
    //6. Activa a escrita de cor                                                                
    glColorMask(1, 1, 1, 1);
    //7. Activa o teste de profundidade                                                         
    glEnable(GL_DEPTH_TEST);
    //8. O stencil test passa apenas quando o pixel tem o valor 1 no stencil buffer             
    glStencilFunc(GL_EQUAL, 1, 1);
    //9. Stencil buffer read-only
    glStencilOp(GL_KEEP, GL_KEEP, GL_KEEP);
    //10. Desenha o objecto com a reflexão onde stencil buffer é 1
    
    //para z=0 e z=10
    glPushMatrix();
        glTranslatef(0, 0, -0.001);
        glRotatef(-90,1,0,0);
        glScalef(1,-1,1);
        quad(2,1,1,1);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(0, 2, 10.001);
        glRotatef(90,1,0,0);
        
        glScalef(1,-1,1);
        quad(2,1,1,1);
    glPopMatrix();
    //----------------------------
    
    //para x=0 e x=10
    glPushMatrix();
        glTranslatef(-0.001, 0,0);
        glRotatef(90,0,0,1);
        glScalef(1,-1,1);
        quad(2,1,1,2);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(10.001, 2,0);
        glRotatef(270,0,0,1);
        glScalef(1,-1,1);
        quad(2,1,1,2);
    glPopMatrix();

    
    //11. Desactiva a utilização do stencil buffer
    glDisable(GL_STENCIL_TEST);
    // isto aplica a textura ao chao Blending
    glEnable(GL_BLEND);
    glColor4f(1, 1, 1, 0.3);
    drawEdges();
    glDisable(GL_BLEND);
}

void drawScene()
{
	
    
    reflection();


	//============================================Eixos
	if (noite)
		glColor4f(AMARELO);
	else
		glColor4f(BLACK);

    glColor4f(WHITE); //fazer reset as cores para o blend + texturas
    /*desenho da caixa*/

    duplicates();//mesmas funcoes que abaixo para meter os paineis a reflectir por  dentro
    //atras
     glPushMatrix();
        glColor4f(DEEPBLUE);
        glTranslatef(3, 0, 3);
        glRotatef(-90,1,0,0);  
        quad(2,0,0,0);
    glPopMatrix();

    //contrario a bola
     glPushMatrix();
        glColor4f(TORRADO);
        glTranslatef(3+multiplier*2, 0, 3+multiplier*2);
        glRotatef(180,0,1,0); //para a reflexao ficar na face exterior da caixa, senão ficava interior
        glRotatef(90,0,0,1); 
        quad(2,0,0,0);
    glPopMatrix();
    
    //em cima
   glPushMatrix();
        glColor4f(SBLUE);
        glTranslatef(3, multiplier*2, 3);   
        quad(2,0,0,0);
    glPopMatrix();

    //lado da bola
    glPushMatrix();
        glColor4f(TORRADO);
        glTranslatef(3, 0, 3);
        glRotatef(90,0,0,1); 
        quad(2,0,0,0);
    glPopMatrix();

    /* desenho do nivel */
    draw_level(level);
    /* desenho da bola */
    glPushMatrix();
        glColor4f(AMARELO);
        glTranslatef(posEsfera[0],posEsfera[1],posEsfera[2]);
        glutSolidSphere(raioEsfera, 256, 256);//radius , (slices(longitude), stacks(latitude))->malhas
    glPopMatrix();
   	glutPostRedisplay();
}

void duplicates(){



     //atras
     glPushMatrix();
        glColor4f(DEEPBLUE);
        glTranslatef(3, 4, 3.001);
        glRotatef(90,1,0,0);  
        quad(2,0,0,0);
    glPopMatrix();
    

    //chao


    //contrario a bola
     glPushMatrix();
        glColor4f(TORRADO);
        glTranslatef(6.999, 0, 3);
        glRotatef(90,0,0,1); 
        quad(2,0,0,0);
    glPopMatrix();
    
    //em cima
   glPushMatrix();
        glColor4f(SBLUE);
        glTranslatef(3, multiplier*1.99, 3+4);
        //glTranslatef(0,3,0);
        glRotatef(180,1,0,0);   
        quad(2,0,0,0);
    glPopMatrix();

    //ladoesquerdo
    glPushMatrix();
        glColor4f(TORRADO);
        glTranslatef(3.001, 4, 3);
        glRotatef(-90,0,0,1); 
        quad(2,0,0,0);
    glPopMatrix();
    


}


GLvoid resize(GLsizei width, GLsizei height)
{
	wScreen=width;
	hScreen=height;
	drawScene();	
}


/* ================================================== ILUMINAÇÃO */
void iluminacao()
{
    if (ligaLuz == 1)
    {
        glEnable(GL_LIGHT0);
    }
    else
    {
        glDisable(GL_LIGHT0);
    }
    if (ligaFoco == 1)
    {
        glEnable(GL_LIGHT1);
    }
    else
    {
        glDisable(GL_LIGHT1);
    }
    glLightfv(GL_LIGHT1, GL_POSITION, focoPini);
    glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, focoDir);
}


void display(void)
{
	if (noite)
		glClearColor(GRAY1);
	else
		glClearColor(GRAY2);
	
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    if(end_game == 0)
	{
        //================================================================= Viewport1
        glViewport (0, hScreen/4, wScreen/4, hScreen/4);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho (-xC,xC, -xC,xC, -zC,zC);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();	
        gluLookAt( 0, 10,0, 0,0,0, 0, 0, -1);
	   //--------------------- Informacao
        sprintf(texto,"Nivel : %d",level+1);
        desenhaTexto(texto,-8,1,0,18);
        if(clock_active ==1)
        {    
            t2 = clock() - t1;
            sprintf(texto,"Tempo : %.2f",((float)t2)/CLOCKS_PER_SEC);
            desenhaTexto(texto,-8,1,4,12);
        }
        if(noite)
            strcpy(texto, "Noite : Activo\n");
        else
            strcpy(texto, "Noite : Inactivo\n");
        desenhaTexto(texto,-8,1,8,12);
        if(ligaLuz)
            strcpy(texto, "Luz tecto : Activo\n");
        else
            strcpy(texto, "Luz tecto : Inactivo\n");
        desenhaTexto(texto,-8,1,12,12);
        if(ligaFoco)
            strcpy(texto, "Luz foco : Activo\n");
        else
            strcpy(texto, "Luz foco : Inactivo\n");
        desenhaTexto(texto,-8,1,16,12);

	   //================================================================= Viewport2
	   glEnable(GL_LIGHTING);  
	   glViewport (wScreen/4, hScreen/4, 0.75*wScreen, 0.75*hScreen);
	   glMatrixMode(GL_PROJECTION);
	   glLoadIdentity();
	   gluPerspective(99.0, wScreen/hScreen, 0.1, 100.0);
	   glMatrixMode(GL_MODELVIEW);
	   glLoadIdentity();
	   gluLookAt(obsPini[0], obsPini[1], obsPini[2], obsPfin[0], obsPfin[1], obsPfin[2], 0, 1, 0);
	   /* desenha objectos */
	   iluminacao();
	   drawScene();
       glutSwapBuffers();
    }
    else
    {   
        glViewport (0, 0, wScreen, hScreen);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho (-xC,xC, -xC,xC, -zC,zC);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();   
        gluLookAt( 0, 10,0, 0,0,0, 0, 0, -1);
        strcpy(texto,"FIM");
        desenhaTexto(texto,0,0,-8,24);
        sprintf(texto,"Tempo Nivel 1 : %.2f",((float)level_time[0])/CLOCKS_PER_SEC);
        desenhaTexto(texto,-8,0,-4,24);
        sprintf(texto,"Tempo Nivel 2 : %.2f",((float)level_time[1])/CLOCKS_PER_SEC);
        desenhaTexto(texto,-8,0,0,24);
        sprintf(texto,"Tempo Nivel 3 : %.2f",((float)level_time[2])/CLOCKS_PER_SEC);
        desenhaTexto(texto,-8,0,4,24);
        strcpy(texto,"Pressione ESC para sair");
        desenhaTexto(texto,-4,0,8,24);
        glutSwapBuffers();
    }
}

void updateVisao()
{
    obsPfin[0] = obsPini[0] + rVisao * cos(aVisao);
    obsPfin[2] = obsPini[2] - rVisao * sin(aVisao);
    focoPini[0] = obsPini[0];
    focoPini[2] = obsPini[2];
    focoPfin[0] = focoPini[0] - rFoco * cos(aFoco + incH);
    focoPfin[2] = focoPini[2] - rFoco * sin(aFoco + incH);
    focoDir[0] = focoPfin[0] - focoPini[0];
    focoDir[1] = incV;
    focoDir[2] = focoPfin[2] - focoPini[2];
    glutPostRedisplay();
}

/*saber se a bola se encontra dentro do labirinto, se o jogo esta a decorrer*/
void game_on()
{
	if(posEsfera[2]> CUBO_INI && posEsfera[2] < CUBO_FIM && posEsfera[0] >CUBO_INI && posEsfera[0] < CUBO_FIM) //se esta dentro da caixa
	{
		if(posEsfera[0]> levels[level].level_entrance[0] && posEsfera[0]< levels[level].level_entrance[1]  && entrance ==0)	// se a entrada na caixa foi pela entrada que nao a do tunel
		{
            if(clock_active ==0) 
            {
                t1 = clock();
                clock_active = 1;
			}
            entrance = posEsfera[0];
		}
		if(entrance >levels[level].level_entrance[0]  && entrance< levels[level].level_entrance[1] && posEsfera[0] >= levels[level].level_exit[0] && posEsfera[0] <= levels[level].level_exit[1] && posEsfera[2] >= levels[level].level_exit[2] && posEsfera[2] <= levels[level].level_exit[3])
		{
            level_time[level] = clock() - t1;
            level++;
            clock_active = 0;
            posEsfera[0] = 5;posEsfera[1]= raioEsfera;posEsfera[2]= 8;
            if(level == 3)
            {
                end_game = 1;
            }
		}
	}
	else	// se nao esta dentro da caixa, faz reset a entrance
	{
		entrance = 0;
	}
}

/*percorrer todos os obstaculos do nivel actual para detectar colisoes*/
int check_colisions(GLfloat ball_x,GLfloat ball_y,GLfloat ball_z)
{	
	for(int i=0;i<levels[level].n_troncos;i++)
	{
		if(levels[level].troncoRot[i][2] ==1)	/* ---(rotaçao segundo y)*/
		{
			if( (ball_x + raioEsfera > levels[level].troncoPos[i][0]) && (ball_x-raioEsfera < levels[level].troncoPos[i][0] + levels[level].troncoDim[i][2]))
			{
				if((ball_z+raioEsfera > levels[level].troncoPos[i][2]-levels[level].troncoDim[i][0]) && (ball_z-raioEsfera < levels[level].troncoPos[i][2]+levels[level].troncoDim[i][0]))
				{
					return 1;
				}
			}
		}
		if(levels[level].troncoRot[i][3] ==1) /*  | (rotaçao segundo z)*/
		{
			if((ball_x + raioEsfera  > levels[level].troncoPos[i][0]-levels[level].troncoDim[i][0]) && (ball_x-raioEsfera < levels[level].troncoPos[i][0] + levels[level].troncoDim[i][0]))
			{
				if((ball_z+raioEsfera > levels[level].troncoPos[i][2]-levels[level].troncoDim[i][0]) && (ball_z-raioEsfera < levels[level].troncoPos[i][2]+levels[level].troncoDim[i][2]))
				{
					return 1;
				}
			}
		}
        if(levels[level].troncoRot[i][1] ==1) /* ^^ |(rotaçao segundo x)*/
        {
            if((ball_z+raioEsfera > levels[level].troncoPos[i][2]-levels[level].troncoDim[i][0]) && (ball_z-raioEsfera < levels[level].troncoPos[i][2]+levels[level].troncoDim[i][0]))
            {
                if((ball_x+raioEsfera > levels[level].troncoPos[i][0]-levels[level].troncoDim[i][0]) && (ball_x-raioEsfera < levels[level].troncoPos[i][0]+levels[level].troncoDim[i][0]))
                {

                    return 1;
                }
            }
        } 
	}
	/*detecçao de colisoes com as paredes da caixa*/
	if(ball_z> CUBO_INI && ball_z < CUBO_FIM && ball_x >CUBO_INI && ball_x <CUBO_FIM) /*se dentro da caixa*/
	{
		if(ball_z < CUBO_INI + raioEsfera)
		{
			return 1;
		}
		if(ball_x < CUBO_INI + raioEsfera)
		{
			return 1;
		}
		if(ball_x > CUBO_FIM - raioEsfera)
		{
			return 1;
		}
	}
	else	
	{
		if(ball_z>= CUBO_INI && ball_z <= CUBO_FIM)
		{
			if(ball_x + raioEsfera >= CUBO_INI && ball_x+raioEsfera <= CUBO_INI+raioEsfera)
			{
				return 1;
			}
			if(ball_x - raioEsfera <= CUBO_FIM && ball_x - raioEsfera >= CUBO_FIM-raioEsfera )
			{
				return 1;
			}
		}
	}
	return 0;
}

//======================================================= EVENTOS-movimentaçao do foco e da bola e iluminaçao
void keyboard(unsigned char key, int x, int y)
{
    switch (key){
        /* -------------------- Direção da lanterna */
        case 's':
        case 'S':
            incH = incH - 0.05;
            if (incH < -incMaxH)
            {
                incH = -incMaxH;
            }
            updateVisao();
            break;
        case 'd':
        case 'D':
            incH = incH + 0.05;
            if (incH > incMaxH)
            {
                incH = incMaxH;
            }
            updateVisao();
            break;
        case 'e':
        case 'E':
            incV = incV + 0.05;
            if (incV > incMaxV)
            {
                incV = incMaxV;
            }
            updateVisao();
            break;
        case 'c':
        case 'C':
            incV = incV - 0.05;
            if (incV < -incMaxV)
            {
                incV = -incMaxV;
            }
            updateVisao();
            break;
        /* -------------------- Dia / noite */
        case 'n':
        case 'N':
            noite = !noite;
            if (noite == 1)
            {
                luzGlobalCor[0] = 0.3; luzGlobalCor[1] =  0.3; luzGlobalCor[2] =  0.3;
            }
            else
            {
                luzGlobalCor[0] = 0.7; luzGlobalCor[1] = 0.7; luzGlobalCor[2] = 0.7;
            }
            glLightModelfv(GL_LIGHT_MODEL_AMBIENT, luzGlobalCor);
            glutPostRedisplay();
            break;
        /* -------------------- Iluminação sala */
        case 't':
        case 'T':
            ligaLuz = !ligaLuz;
            glutPostRedisplay();
            break;
        /* -------------------- Observador */
        case 'f':
        case 'F':
            ligaFoco = !ligaFoco;
            glutPostRedisplay();
            break;
        /*-----------------movimento da bola---*/
        case 'i':
        case 'I':
        	game_on();
        	if(check_colisions(posEsfera[0],posEsfera[1],posEsfera[2]-velEsfera)==1)
        	{
        		;
        	}
        	else
        	{
        		posEsfera[2]-= velEsfera;
        	}
        	if(posEsfera[2] < raioEsfera)
        	{
        		posEsfera[2] = raioEsfera;
        	}
        	break;
        case 'k':
        case 'K':
        	game_on();
        	if(check_colisions(posEsfera[0],posEsfera[1],posEsfera[2]+velEsfera)==1)
        	{
        		;
        	}
        	else
        	{
        		posEsfera[2]+= velEsfera;
        	}
        	if(posEsfera[2] > 10-raioEsfera)
        	{
        		posEsfera[2] = 10-raioEsfera;
        	}
        	break;
        case 'j':
        case 'J':
        	game_on();
        	if(check_colisions(posEsfera[0]-velEsfera,posEsfera[1],posEsfera[2])==1)
        	{
        		;
        	} /*colisao com o tunel do nivel actual*/
        	else if((posEsfera[2]+raioEsfera > levels[level].tunelPos[2]-levels[level].tunelDim[0]) && (posEsfera[2]-raioEsfera < levels[level].tunelPos[2]+levels[level].tunelDim[2]) && (posEsfera[0]-velEsfera-raioEsfera > levels[level].tunelPos[0]-levels[level].tunelDim[0]) && (posEsfera[0]-velEsfera-raioEsfera <levels[level].tunelPos[0]+levels[level].tunelDim[0] ))  
			{
				;
			}
        	else
        	{
        		posEsfera[0]-= velEsfera;
        	}
        	if(posEsfera[0] < raioEsfera)
        	{
        		posEsfera[0] = raioEsfera;
        	}
        	break;
        case 'l':
        case 'L':
        	game_on();
        	if(check_colisions(posEsfera[0]+velEsfera,posEsfera[1],posEsfera[2])==1)
        	{
        		;
        	} /*colisao com o tunel do nivel actual*/
        	else if((posEsfera[2]+raioEsfera > levels[level].tunelPos[2]-levels[level].tunelDim[0]) && (posEsfera[2]-raioEsfera < levels[level].tunelPos[2]+levels[level].tunelDim[2]) && (posEsfera[0]+velEsfera+raioEsfera  > levels[level].tunelPos[0]-levels[level].tunelDim[0]) && (posEsfera[0]+velEsfera-raioEsfera < levels[level].tunelPos[0]+levels[level].tunelDim[0]))
			{
				;
			}
        	else
        	{
        		posEsfera[0]+= velEsfera;
        	}
        	if(posEsfera[0] > 10-raioEsfera)
        	{
        		posEsfera[0] = 10-raioEsfera;
        	}
        	break;
        /* -------------------- Escape */
        case 27:
            exit(0);
            break;
    }
}

/*movimentaçao do observador e do foco*/
void teclasNotAscii(int key, int x, int y)
{
    if(key == GLUT_KEY_UP) 
    {
		obsPini[0]=obsPini[0]+incVisao*cos(aVisao); 
		obsPini[2]=obsPini[2]-incVisao*sin(aVisao); 
	}
	if(key == GLUT_KEY_DOWN) 
	{
		obsPini[0]=obsPini[0]-incVisao*cos(aVisao); 
		obsPini[2]=obsPini[2]+incVisao*sin(aVisao); 
	} 
	if(key == GLUT_KEY_LEFT) 
	{
		aVisao = (aVisao + 0.1);
		aFoco = aFoco - 0.1;
	}
	if(key == GLUT_KEY_RIGHT) 
	{
		aVisao = (aVisao - 0.1);
		aFoco = aFoco + 0.1;
	}

	updateVisao();
}

//======================================================= MAIN
int main(int argc, char** argv){

	glutInit(&argc, argv);




	glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH   | GLUT_STENCIL );
	glutInitWindowSize (wScreen, hScreen); 
	glutInitWindowPosition (400, 400); 
	glutCreateWindow ("Projecto CG");  /*falta por as teclas certas*/  
	init();
	glutSpecialFunc(teclasNotAscii); 
	glutReshapeFunc(resize);
	glutDisplayFunc(display); 
	glutKeyboardFunc(keyboard);
	glutMainLoop();
	return 0;
}