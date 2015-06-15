




void duplicates();

//==================================================================== Definir cores, nº de obstaculos por nivel e nº de texturas
#define TORRADO   0.77734375,  0.77734375,  0.77734375,        1.0
#define SBLUE  0.44921875,0.44921875,0.44921875, 1.0
#define DEEPBLUE  0.1171875, 0.5625,  0.99609375, 1.0
/*
#define TORRADO   0.0,  0.99609375,  0.0,        1.0
#define SBLUE  0.0,  0.74609375,  0.99609375, 1.0

*/
#define PURPURINAS  0.1171875, 0.5625,  0.99609375, 1.0
#define AZUL     0.0, 0.0, 1.0, 1.0
#define VERMELHO 1.0, 0.0, 0.0, 1.0
#define AMARELO  1.0, 1.0, 0.0, 0.8
#define AMARELO2  1.0, 1.0, 0.0, 1.0
#define VERDE    0.0, 1.0, 0.0, 1.0
#define LARANJA  0.8, 0.6, 0.1, 1.0
#define WHITE    1.0, 1.0, 1.0, 1.0
#define BLACK    0.0, 0.0, 0.0, 1.0
#define GRAY1    0.2, 0.2, 0.2, 1.0
#define GRAY2    0.6, 0.6, 0.6, 1.0
#define N_TRONCOS 12
#define N_TRONCOS2 30
#define N_TRONCOS3 30
#define CUBO_INI 3
#define CUBO_FIM 7
#define N_TEX 6

//===========================================================Variaveis e constantes

typedef struct level
{
    GLfloat n_troncos;                      /*nº de obstaculos*/
    GLfloat troncoPos[N_TRONCOS2][3];       /*posiçao do obstaculo*/
    GLfloat troncoRot[N_TRONCOS2][4];       /*rotaçao aplicada ao obstaculo*/
    GLfloat troncoDim[N_TRONCOS2][3];       /*dimensoes do obstaculo(cilindro)*/
    GLfloat diskRadius[N_TRONCOS2];         /*raio do disco que tapa o cilindro*/
    GLfloat tunelPos[3];                    /*posiçao do tunel de final de nivel*/
    GLfloat tunelDim[3];                    /*dimensoes do tunel*/
    GLfloat level_entrance[2];              /*limites da entrada no nivel*/
    GLfloat level_exit[4];                  /*limites da saida do nivel*/
}Level;

//------------------------------------------------------------ Sistema Coordenadas
GLfloat  xC=16.0, zC=15.0;                                 
GLint    eixos=1;
GLint    wScreen=800, hScreen=600;                         
char     texto[30];
//------------------------------------------------------------ Observador
GLfloat  PI = 3.14159;
GLfloat  rVisao=3.0, aVisao=0.5*PI, incVisao=0.1;   
GLfloat  obsPini[] ={3, 1, .5*xC};                 
GLfloat  obsPfin[] ={obsPini[0]-rVisao*cos(aVisao), obsPini[1], obsPini[2]-rVisao*sin(aVisao)};

//------------------------------------------------------------ Iluminacao

/*Global (ambiente)*/
GLint   noite=1;
GLfloat luzGlobalCor[4]={1.0,1.0,1.0,1.0};   
/*Lampada tecto(ambiente local)*/
GLint ligaLuz = 1;
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
//lanterna interligada ao observador-foco
GLfloat focoPini[] = {obsPini[0], obsPini[1], obsPini[2], 1.0};
GLfloat focoPfin[] = {obsPini[0] - rFoco * cos(aFoco), obsPini[1], obsPini[2] - rFoco * sin(aFoco), 1.0};
GLfloat focoDir[] = {focoPfin[0] - focoPini[0], 0, focoPfin[2] - focoPini[2]};
GLfloat focoExp = 10.0; 								/* concentraçao da luz */
GLfloat focoCut = 15.0; 								/* ângulo do foco */
GLfloat focoCorDif[4] = {0.85, 0.85, 0.85, 1.0}; 		/* intensidade da cor difusa -forma como a luz se espalha */
GLfloat focoCorEsp[4] = {1 , 1, 1, 1.0}; 				/* intensidade da cor especular- como a cor reflete para o utilizador */

//…………………………………………………………………………………………………………………………………………… Esfera
GLfloat raioEsfera = 0.1;
GLfloat velEsfera = 0.05;
GLfloat posEsfera[] = {5, raioEsfera, 8};

//…………………………………………………………………………………………………………………………………………… texturas
GLuint  tex[N_TEX];
RgbImage imag;

//…………………………………………………………………………………………………………………………………………… malha de poligonos
GLint quadsize=1;
GLint multiplier=5/2;
GLint floor_dim= 32; //numero divisoes da grelha
GLint floorsize=5;
GLint defaultReflectionSize=2;
//…………………………………………………………………………………………………………………………………………… labirinto	
Level levels[3];                                        /*estruturas com todas as informaçoes de cada nivel*/
GLint level = 0;                                        /* 0, 1 e 2 */
GLfloat entrance = 0;                                   /* por onde a bola entrou no labirinto segundo x*/
/* cor de cada obstaculo no nivel 3, usando ColorMaterial */
GLfloat lvl3_colors[N_TRONCOS3+1][4] = {VERMELHO,LARANJA,AMARELO2,VERDE,AZUL,WHITE,VERMELHO,GRAY2,BLACK,VERMELHO,AMARELO2,AZUL,VERMELHO,AMARELO2,LARANJA,WHITE,VERDE,AZUL,WHITE,BLACK,VERMELHO,AMARELO2,VERMELHO,AZUL,AMARELO2,AZUL,WHITE,GRAY2,GRAY1,BLACK,LARANJA};
GLint ascendente = 0;                                   /* descendente = 0, ascendente = 1*. controlar a transparencia dos obstaculos no nivel 3*/
clock_t t1,t2;
clock_t level_time[3];
GLint clock_active = 0;
GLint end_game = 0;















