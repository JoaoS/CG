#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#ifdef __APPLE__
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
# include "materiais.h"


//==================================================================== Definir cores
#define AZUL     0.0, 0.0, 1.0, 1.0
#define VERMELHO 1.0, 0.0, 0.0, 1.0
#define AMARELO  1.0, 1.0, 0.0, 1.0
#define VERDE    0.0, 1.0, 0.0, 1.0
#define LARANJA  0.8, 0.6, 0.1, 1.0
#define WHITE    1.0, 1.0, 1.0, 1.0
#define BLACK    0.0, 0.0, 0.0, 1.0
#define GRAY1    0.2, 0.2, 0.2, 1.0
#define GRAY2    0.93, 0.93, 0.93, 1.0


//================================================================================
//===========================================================Variaveis e constantes

//------------------------------------------------------------ Sistema Coordenadas
GLfloat  xC=16.0, zC=15.0;                                 /* medidas para os comprimentos dos eixos */
GLint    eixos=1;
GLint    wScreen=800, hScreen=600;                         /*  dimensao da janela   */
char     texto[30];
//------------------------------------------------------------ Observador
GLfloat  PI = 3.14159;
GLfloat  rVisao=3.0, aVisao=0.5*PI, incVisao=0.1;   /* incvisao=incremento da visao quando anda  ,rvisao=raio de visao do observador  aVisao-abertura do angulo de visao  */
GLfloat  obsPini[] ={3, 1, .5*xC};                 /*eixos x y z , o y é a altura*/
GLfloat  obsPfin[] ={obsPini[0]-rVisao*cos(aVisao), obsPini[1], obsPini[2]-rVisao*sin(aVisao)};

//------------------------------------------------------------ Iluminacao

/*Global (ambiente)*/
GLint   noite=1;
GLfloat luzGlobalCor[4]={1.0,1.0,1.0,1.0};   
/*Lampada tecto(ambiente local)*/
GLint ligaLuz = 0;
GLfloat localPos[4] = {xC/2, 10.0, xC/2, 1.0}; 			/* posição da fonte de luz */
GLfloat localCor[4] = {0.1, 0.1, 0.1, 1.0}; 			/* intensidade da cor */
GLfloat localAttCon = 1.0; 								/* atenuação atmosféria C (constante) */
GLfloat localAttLin = 0.05; 							/* atenuação atmosféria L (linear) */
GLfloat localAttQua = 0.0; 								/* atenuação atmosféria Q (quadrática) */

/* Lanterna (local) */
GLint ligaFoco = 0;
GLfloat rFoco = 1.1, aFoco = aVisao;
GLfloat incH = 0.0, incV = 0.0;
GLfloat incMaxH = 0.5, incMaxV = 0.35;
GLfloat focoPini[] = {obsPini[0], obsPini[1], obsPini[2], 1.0};
GLfloat focoPfin[] = {obsPini[0] - rFoco * cos(aFoco), obsPini[1], obsPini[2] - rFoco * sin(aFoco), 1.0};
GLfloat focoDir[] = {focoPfin[0] - focoPini[0], 0, focoPfin[2] - focoPini[2]};
GLfloat focoExp = 10.0; 								/* concentraçao da luz */
GLfloat focoCut = 15.0; 								/* ângulo do foco */
GLfloat focoCorDif[4] = {0.85, 0.85, 0.85, 1.0}; 		/* intensidade da cor difusa */
GLfloat focoCorEsp[4] = {1.0 , 1.0, 1.0, 1.0}; 			/* intensidade da cor especular */

/* Materiais */
GLint colorM = 1;										/*color material activo = 1*/
GLint material = 4; 									/* tipo de material aplicado à esfera */
GLint material1 = 5; 									/* tipo de material aplicado ao torus da frente */
GLint material2 = 18; 									/* tipo de material aplicado do torus de trás */
GLint material3 = 9; 									/* tipo de material aplicado ao cone */
GLint material4 = 4; 									/* tipo de material aplicado ao quadrado */

//…………………………………………………………………………………………………………………………………………… Esfera
GLfloat matAmbiente[] = {1.0,1.0,1.0,1.0};	  
GLfloat matDifusa[]   = {1.0,1.0,1.0,1.0};	  
GLfloat matEspecular[]= {1.0, 1.0, 1.0, 1.0}; 
GLint   especMaterial = 20;
GLint quadsize=1;


//================================================================================
//=========================================================================== INIT
//================================================================================



//……………………………………………………………………………………………………………………………………………………… Iluminacao
void initLights(void)
{
	/*Ambiente*/
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, luzGlobalCor);
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

void initMaterials(int material) /* Determina as componentes e os seus valores */
{
    switch (material)
    {
        case 0: /* esmerald */
            glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, esmeraldAmb);
            glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, esmeraldDif);
            glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, esmeraldSpec);
            glMateriali(GL_FRONT_AND_BACK, GL_SHININESS, esmeraldCoef);
            break;
        case 1: /* jade */
            glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, jadeAmb);
            glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, jadeDif);
            glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, jadeSpec);
            glMateriali(GL_FRONT_AND_BACK, GL_SHININESS, jadeCoef);
            break;
        case 2: /* obsidian */
            glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, obsidianAmb);
            glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, obsidianDif);
            glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, obsidianSpec);
            glMateriali(GL_FRONT_AND_BACK, GL_SHININESS, obsidianCoef);
            break;
        case 3: /* pearl */
            glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, pearlAmb);
            glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, pearlDif);
            glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, pearlSpec);
            glMateriali(GL_FRONT_AND_BACK, GL_SHININESS, pearlCoef);
            break;
        case 4: /* ruby */
            glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, rubyAmb);
            glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, rubyDif);
            glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, rubySpec);
            glMateriali(GL_FRONT_AND_BACK, GL_SHININESS, rubyCoef);
            break;
        case 5: /* turquoise */
            glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, turquoiseAmb);
            glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, turquoiseDif);
            glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, turquoiseSpec);
            glMateriali(GL_FRONT_AND_BACK, GL_SHININESS, turquoiseCoef);
            break;
        case 6: /* brass */
            glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, brassAmb);
            glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, brassDif);
            glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, brassSpec);
            glMateriali(GL_FRONT_AND_BACK, GL_SHININESS, brassCoef);
            break;
        case 7: /* bronze */
            glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, bronzeAmb);
            glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, bronzeDif);
            glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, bronzeSpec);
            glMateriali(GL_FRONT_AND_BACK, GL_SHININESS, bronzeCoef);
            break;
        case 8: /* chrome */
            glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, chromeAmb);
            glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, chromeDif);
            glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, chromeSpec);
            glMateriali(GL_FRONT_AND_BACK, GL_SHININESS, chromeCoef);
        break;
        case 9: /* copper */
            glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, copperAmb);
            glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, copperDif);
            glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, copperSpec);
            glMateriali(GL_FRONT_AND_BACK, GL_SHININESS, copperCoef);
            break;
        case 10: /* gold */
            glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, goldAmb);
            glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, goldDif);
            glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, goldSpec);
            glMateriali(GL_FRONT_AND_BACK, GL_SHININESS, goldCoef);
            break;
        case 11: /* silver */
            glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, silverAmb);
            glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, silverDif);
            glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, silverSpec);
            glMateriali(GL_FRONT_AND_BACK, GL_SHININESS, silverCoef);
            break;
        case 12: /* blackPlastic */
            glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, blackPlasticAmb);
            glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, blackPlasticDif);
            glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, blackPlasticSpec);
            glMateriali(GL_FRONT_AND_BACK, GL_SHININESS, blackPlasticCoef);
            break;
        case 13: /* cyankPlastic */
            glMaterialfv(GL_FRONT, GL_AMBIENT, cyanPlasticAmb);
            glMaterialfv(GL_FRONT, GL_DIFFUSE, cyanPlasticDif);
            glMaterialfv(GL_FRONT, GL_SPECULAR, cyanPlasticSpec);
            glMateriali(GL_FRONT, GL_SHININESS, cyanPlasticCoef);
            break;
        case 14: /* greenPlastic */
            glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, greenPlasticAmb);
            glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, greenPlasticDif);
            glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, greenPlasticSpec);
            glMateriali(GL_FRONT_AND_BACK, GL_SHININESS, greenPlasticCoef);
            break;
        case 15: /* redPlastic */
            glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, redPlasticAmb);
            glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, redPlasticDif);
            glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, redPlasticSpec);
            glMateriali(GL_FRONT_AND_BACK, GL_SHININESS, redPlasticCoef);
            break;
        case 16: /* whitePlastic */
            glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, whitePlasticAmb);
            glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, whitePlasticDif);
            glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, whitePlasticSpec);
            glMateriali(GL_FRONT_AND_BACK, GL_SHININESS, whitePlasticCoef);
            break;
        case 17: /* yellowPlastic */
            glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, yellowPlasticAmb);
            glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, yellowPlasticDif);
            glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, yellowPlasticSpec);
            glMateriali(GL_FRONT_AND_BACK, GL_SHININESS, yellowPlasticCoef);
            break;
        case 18: /* blackRubber */
            glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, blackRubberAmb);
            glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, blackRubberDif);
            glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, blackRubberSpec);
            glMateriali(GL_FRONT_AND_BACK, GL_SHININESS, blackRubberCoef);
            break;
        case 19: /* cyanRubber */
            glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, cyanRubberAmb);
            glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, cyanRubberDif);
            glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, cyanRubberSpec);
            glMateriali(GL_FRONT_AND_BACK, GL_SHININESS, cyanRubberCoef);
            break;
        case 20: /* greenRubber */
            glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, greenRubberAmb);
            glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, greenRubberDif);
            glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, greenRubberSpec);
            glMateriali(GL_FRONT_AND_BACK, GL_SHININESS, greenRubberCoef);
            break;
        case 21: /* redRubber */
            glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, redRubberAmb);
            glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, redRubberDif);
            glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, redRubberSpec);
            glMateriali(GL_FRONT_AND_BACK, GL_SHININESS, redRubberCoef);
            break;
        case 22: /* whiteRubber */
            glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, whiteRubberAmb);
            glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, whiteRubberDif);
            glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, whiteRubberSpec);
            glMateriali(GL_FRONT_AND_BACK, GL_SHININESS, whiteRubberCoef);
            break;
        case 23: /* yellowRubber */
            glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, yellowRubberAmb);
            glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, yellowRubberDif);
            glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, yellowRubberSpec);
            glMateriali(GL_FRONT_AND_BACK, GL_SHININESS, yellowRubberCoef);
            break;
    }
}


void init(void)
{
	glClearColor(WHITE);
	glShadeModel(GL_SMOOTH);
	glEnable(GL_COLOR_MATERIAL);
	glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE ); 
	initLights();
	glEnable(GL_LIGHTING);  
	glEnable(GL_DEPTH_TEST);
}
	

//================================================================================
//======================================================================== DISPLAY
void desenhaTexto(char *string, GLfloat x, GLfloat y, GLfloat z) 
{  
	glRasterPos3f(x,y,z); 
	while(*string)
	  glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10, *string++); 
}

//desenha um quadrado de lado quadsize ou 10 e normal x=1, y=2, z=3
void quad(int normal,int size){

    glBegin(GL_QUADS);

        switch(normal){
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
        if(!size){
            glVertex3d(0, 0, 0);
            glVertex3d(quadsize, 0, 0);
            glVertex3d(quadsize, quadsize, 0);
            glVertex3d(0, quadsize, 0);

        }
        else{
            glVertex3d(0, 0, 0);
            glVertex3d(10, 0, 0);
            glVertex3d(10, 10, 0);
            glVertex3d(0, 10, 0);
        }

            

    glEnd();
        



}

void drawScene(){
	
	//============================================Eixos
	if (noite)
		glColor4f(AMARELO);
	else
		glColor4f(BLACK);
	
    if(eixos){
    glColor4f(VERDE);
    if(!colorM)
         initMaterials(19);


    glBegin(GL_LINES);                      
        glVertex3i(0,0,-xC); 
        glVertex3i(0,0, xC);        
    glEnd();
    glBegin(GL_LINES);                      
        glVertex3i(0,-xC,0); 
        glVertex3i(0,xC,0);         
    glEnd();
    glBegin(GL_LINES);                      
        glVertex3i(-xC,0,0); 
        glVertex3i( xC,0,0);        
    glEnd();


    //eixos para o plano
    glBegin(GL_LINES);  //z=5                    
        glVertex3i(-xC,0,5); 
        glVertex3i( xC,0,5);        
    glEnd();

     glBegin(GL_LINES); //z=10                     
        glVertex3i(-xC,0,10); 
        glVertex3i( xC,0,10);        
    glEnd();

    glBegin(GL_LINES); //x=5                     
        glVertex3i(5,0,-xC); 
        glVertex3i(5,0,xC);        
    glEnd();

     glBegin(GL_LINES); //x=5                     
        glVertex3i(10,0,-xC); 
        glVertex3i(10,0,xC);        
    glEnd();

    }
    

	//************************************************** Poligonos
	//  As cores dos objectos devem ser definidas:
	//		1. Cor usando o glColorMAterial
	//		2. Propriedades materiais (a implementar)
	
	if(colorM ==0)	/*propriedades dos materiais*/
	{
		glDisable(GL_COLOR_MATERIAL);

        glPushMatrix();
            initMaterials(material);
            glTranslatef(2.5, 1.2, 5);
            glutSolidSphere(1.5, 1000, 1000);//radius , (slices(longitude), stacks(latitude))->malhas
        glPopMatrix();

    
        //plano de baixo
        glPushMatrix();
            initMaterials(0);
            glTranslatef(0, -.6, 0);
            glRotatef(90,1,0,0);  
            //glScalef(2,0,0); 
            quad(2,1);
        glPopMatrix();



        //lado de baixo
        glPushMatrix();
            initMaterials(material);
            glTranslatef(7, 0, 4.5);
            glRotatef(90,1,0,0);   
            quad(2,0);
        glPopMatrix();


        //lado da esfera
        glPushMatrix();
            initMaterials(material);
            glTranslatef(7, 0, 5.5);
            glRotatef(90,0,1,0);   
            quad(2,0);//pode estar mal
        glPopMatrix();

        //para tras
        glPushMatrix();
            initMaterials(material);
            glTranslatef(8, 0, 4.5);
            glRotatef(90,0,0,1);   
            quad(2,0);//pode estar mal
        glPopMatrix();

         //para frente
        glPushMatrix();
            initMaterials(material);
            glTranslatef(8, 0, 5.5);
            glRotatef(90,0,0,1);   
            quad(2,0);//pode estar mal
        glPopMatrix();

         //contrario a bola
        glPushMatrix();
            initMaterials(material);
            glTranslatef(8, 0, 5.5);
            glRotatef(90,0,1,0);   
            quad(1,0);//pode estar mal
        glPopMatrix();

         //cima
        glPushMatrix();
            initMaterials(material);
            glTranslatef(7, 1, 4.5);
            glRotatef(90,1,0,0);   
            quad(2,0);
        glPopMatrix();

	}
	else	/*usando glColorMaterial*/
	{	
		glEnable(GL_COLOR_MATERIAL);
		glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE ); 
	

        glPushMatrix();
            glColor4f(AMARELO);
            glTranslatef(2.5, 1.2, 5);
            glutSolidSphere(1.5, 1000, 1000);//radius , (slices(longitude), stacks(latitude))->malhas
        glPopMatrix();

    
        //plano de baixo
        glPushMatrix();
            glColor4f(LARANJA);
            glTranslatef(0, -.1, 0);
            glRotatef(90,1,0,0);  
            //glScalef(2,0,0); 
            quad(2,1);
        glPopMatrix();



        //lado de baixo
        glPushMatrix();
            glColor4f(LARANJA);
            glTranslatef(7, 0, 4.5);
            glRotatef(90,1,0,0);   
            quad(2,0);
        glPopMatrix();


        //lado da esfera
        glPushMatrix();
            glColor4f(VERMELHO);
            glTranslatef(7, 0, 5.5);
            glRotatef(90,0,1,0);   
            quad(2,0);//pode estar mal
        glPopMatrix();

        //para tras
        glPushMatrix();
            glColor4f(VERDE);
            glTranslatef(8, 0, 4.5);
            glRotatef(90,0,0,1);   
            quad(2,0);//pode estar mal
        glPopMatrix();

         //para frente
        glPushMatrix();
            glColor4f(VERDE);
            glTranslatef(8, 0, 5.5);
            glRotatef(90,0,0,1);   
            quad(2,0);//pode estar mal
        glPopMatrix();

         //contrario a bola
        glPushMatrix();
             glColor4f(VERMELHO);
            glTranslatef(8, 0, 5.5);
            glRotatef(90,0,1,0);   
            quad(1,0);//pode estar mal
        glPopMatrix();

         //cima
        glPushMatrix();
            glColor4f(AZUL);
            glTranslatef(7, 1, 4.5);
            glRotatef(90,1,0,0);   
            quad(2,0);
        glPopMatrix();

	}
   	glutPostRedisplay();
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

void drawOrientacao()
{
	glPushMatrix();
		glColor4f(VERDE);
		glTranslatef (obsPini[0],obsPini[1],obsPini[2]);		
		glutSolidCube(0.75);
	glPopMatrix();

	glPushMatrix();
		glColor4f(LARANJA);
		glTranslatef (obsPfin[0],obsPfin[1],obsPfin[2]);		
		glutSolidCube(0.5);
	glPopMatrix();
	/* Direccao do FOCO=lanterna */
	glPushMatrix();
        glColor4f(VERMELHO);
        glTranslatef(focoPfin[0], focoPfin[1], focoPfin[2]);
        glutSolidCube(0.25);
    glPopMatrix();
}	

void display(void)
{
	if (noite)
		glClearColor(GRAY1);//valor de limpeza para os buffers
	else
		glClearColor(GRAY2);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

	//================================================================= Viewport1 (x,y,width,height)
	glViewport (0, hScreen/4, wScreen/4, hScreen/4);
  	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho (-xC,xC, -xC,xC, -zC,zC);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();	
	gluLookAt( 0, 10,0, 0,0,0, 0, 0, -1);
	/* desenha objectos */
	iluminacao();
	drawScene(); 
	drawOrientacao(); 
	//--------------------- Informacao
	glColor3f(1,0,0);
	sprintf(texto, "%d - Noite", noite);
	desenhaTexto(texto,-12,1,-6);
	sprintf(texto, "%d - Tecto", ligaLuz);
	desenhaTexto(texto,-12,1,-9);
	sprintf(texto, "%d - Foco", ligaFoco);
	desenhaTexto(texto,-12,1,-12);
	sprintf(texto, "%d - Color Material", colorM);
	desenhaTexto(texto,-12,1,-15);
    sprintf(texto, "%d - Eixos ", eixos);
    desenhaTexto(texto,-12,1,-3);

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

//======================================================= EVENTOS
void keyboard(unsigned char key, int x, int y)
{
    switch (key){
        /* -------------------- Direção da lanterna */
        case 'A'://desacivar/activar os eixos
        case 'a':
            if(eixos)
                eixos=0;
            else
                eixos=1;
            updateVisao();
            break;

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
                luzGlobalCor[0] = 0.3; luzGlobalCor[1] = 0.3; luzGlobalCor[2] = 0.3;
            }
            else
            {
                luzGlobalCor[0] = 1.0; luzGlobalCor[1] = 1.0; luzGlobalCor[2] = 1.0;
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
        /* -------------------- ColorMaterial */
        case 'm':
        case 'M':
            colorM = !colorM;
            glutPostRedisplay();
            break;
        /* -------------------- Escape */
        case 27:
            exit(0);
            break;
    }
}


void teclasNotAscii(int key, int x, int y)
{
    if(key == GLUT_KEY_UP) 
    {
		obsPini[0]=obsPini[0]+incVisao*cos(aVisao); //*cos(aVisao)
		obsPini[2]=obsPini[2]-incVisao*sin(aVisao); //sin(aVisao)
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
	glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH );
	glutInitWindowSize (wScreen, hScreen); 
	glutInitWindowPosition (400, 400); 
	glutCreateWindow ("Projecto CG(left,right,up,down) - (N,T,F,M) - (s,d-e,c) a->eixos");
  
	init();
	glutSpecialFunc(teclasNotAscii); 
	glutReshapeFunc(resize);
	glutDisplayFunc(display); 
	glutKeyboardFunc(keyboard);
	glutMainLoop();
	return 0;
}




/*

1-> objectos            //falta o plano de baixo
->visita guiada



2->cores e texturas
3->reflexoes
4->transparencias













*/















