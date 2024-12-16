//#include <stdlib.h>
#include <stdio.h>
#include <GL/glut.h>

float translacaoX=0, translacaoY=0, escalaX = 1.0f, escalaY = 1.0f, rotacao = 0.0f;
int transladar=0, rotacionar=0, escalonar=0, espelhar=0;
float left, right, top, bottom, panX, panY;

void desenhaEixos() {

	glColor3f(1,1,1);

	glLineWidth(1);
	glBegin(GL_LINES);

    glVertex2f(left,0.0);
	glVertex2f(right, 0.0);
	glVertex2f(0.0,bottom);
	glVertex2f(0.0,top);

	glEnd();

}

void desenhaCasinha() {

	glLineWidth(3);
	glBegin(GL_LINE_LOOP);
    glVertex2f(-0.2f,0.1f);
	glVertex2f(-0.2f,-0.2f);
	glVertex2f(0.2f,-0.2f);
	glVertex2f(0.2f,0.1f);
	glEnd();


    glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex2f(-0.2f,0.1f);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(0.0f,0.22f);
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex2f(0.2f,0.1f);
    glEnd();

}

//TODO: alterar o desenho (opcional)
void Desenha(void)
{

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D (left+panX, right+panX, bottom+panY, top+panY);
    glMatrixMode(GL_MODELVIEW);

	// Limpa a janela de visualização com a cor branca
	glClearColor(0,0,0,1);
	glClear(GL_COLOR_BUFFER_BIT);

	glPushMatrix();

	glLoadIdentity();

	desenhaEixos();

	glPopMatrix();

	glLoadIdentity();

    glTranslatef(translacaoX,translacaoY,0);
    glRotatef(rotacao, 0, 0, 1);
    glScalef(escalaX, escalaY, 1);

    desenhaCasinha();

	//Executa os comandos OpenGL
	glFlush();
}


void resetarParametrosDesenho(){
    translacaoX=0; 
    translacaoY=0; 
    escalaX = 1.0f; 
    escalaY = 1.0f; 
    rotacao = 0.0f;    
}

void espelharImagem(){
    translacaoX *= -1;
    translacaoY *= -1;
    rotacao += 180.0f;
}

// Função callback chamada para gerenciar eventos de teclas
void Teclado (unsigned char key, int x, int y)
{
    if (key == 27)
		exit(0);
    if (key == 'T'|| key == 't'){
        //printf("tecla digitada: %c", key);
        rotacionar = 0;
        transladar = 1;
        escalonar = 0;
    }
    if(key == 'R' || key == 'r'){
        rotacionar = 1;
        transladar = 0;
        escalonar = 0;
    }
    if(key == 'S' || key == 's'){
        rotacionar = 0;
        transladar = 0;
        escalonar = 1;
    }
    if(key == 'M' || key == 'm'){
        espelharImagem();
        glutPostRedisplay();        
    }    
    if(key == 'I' || key == 'i'){
        resetarParametrosDesenho();
        glutPostRedisplay();        
    }
}

void TeclasEspecias(int key, int x, int y)
{
    if(transladar){
        if(key == GLUT_KEY_UP)
            translacaoY += 0.15f;
        if(key == GLUT_KEY_DOWN)
            translacaoY -= 0.15f;
        if(key == GLUT_KEY_LEFT)
            translacaoX -= 0.2f; 
        if(key == GLUT_KEY_RIGHT)
            translacaoX += 0.2f;
    }

    if(rotacionar){
        if(key == GLUT_KEY_UP)
            rotacao += 2.0f;
        if(key == GLUT_KEY_DOWN)
            rotacao -= 2.0f;
    }

    if(escalonar){
        if(key == GLUT_KEY_UP){
            escalaX += 0.3f;
            escalaY += 0.3f;
        }
        if(key == GLUT_KEY_DOWN && escalaX > 0.1 && escalaY > 0.1){
            escalaX -= 0.3f;
            escalaY -= 0.3f;
        }        
    }

	 glutPostRedisplay();
}


// Função responsável por inicializar parâmetros e variáveis
void Inicializa(void)
{
	// Define a janela de visualização 2D
	glMatrixMode(GL_PROJECTION);
	left=-1.0;
	right=1.0;
	top=1.0;
	bottom=-1.0;
	gluOrtho2D(left+panX,right+panX,bottom+panY,top+panY);
	glMatrixMode(GL_MODELVIEW);
}

// Programa Principal
int main(void)
{

    int argc = 0;
	char *argv[] = { (char *)"gl", 0 };

	glutInit(&argc,argv);

	// Define do modo de operação da GLUT
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

	// Especifica o tamanho inicial em pixels da janela GLUT
	glutInitWindowSize(500,500);

	// Cria a janela passando como argumento o título da mesma
	glutCreateWindow("Trabalho em progresso");

	// Registra a função callback de redesenho da janela de visualização
	glutDisplayFunc(Desenha);

	// Registra a função callback para tratamento das teclas ASCII
	glutKeyboardFunc (Teclado);

	glutSpecialFunc (TeclasEspecias);

	// Chama a função responsável por fazer as inicializações
	Inicializa();

	// Inicia o processamento e aguarda interações do usuário
	glutMainLoop();

	return 0;
}