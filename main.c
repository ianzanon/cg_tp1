#include <GL/glew.h>
#include <GL/freeglut.h>
#include <SOIL/SOIL.h>
#include <stdio.h>
#include <math.h>

struct obj {
	float x, y, alt, larg;
};

struct obj personagem;

// Mundo inicial
int xBegin = -1280;
int xEnd = 1280;
int yBegin = -720;
int yEnd = 720;

// Teclas [W, A, S, D] desligadas
int moveKeys[4] = {0,0,0,0}; 

void desenhaCena() {
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0, 0, 0);

    glPushMatrix();
    	glTranslatef(personagem.x, personagem.y, 0);
        glBegin(GL_TRIANGLE_FAN);
            glVertex3f(-personagem.larg/2, -personagem.alt/2, 0);
            glVertex3f( personagem.larg/2, -personagem.alt/2, 0);
            glVertex3f( personagem.larg/2,  personagem.alt/2, 0);
            glVertex3f(-personagem.larg/2,  personagem.alt/2, 0);
        glEnd();
    glPopMatrix();
    
    glColor3f(1, 0, 0);
    
    glPushMatrix();
        glTranslatef(0, -360, 0);
        glBegin(GL_TRIANGLE_FAN);
            glVertex3f(-personagem.larg/2, -personagem.alt/2, 0);
            glVertex3f( personagem.larg/2, -personagem.alt/2, 0);
            glVertex3f( personagem.larg/2,  personagem.alt/2, 0);
            glVertex3f(-personagem.larg/2,  personagem.alt/2, 0);
        glEnd();
        glTranslatef(-200, -720, 0);
        glBegin(GL_TRIANGLE_FAN);
            glVertex3f(-personagem.larg/2, -personagem.alt/2, 0);
            glVertex3f( personagem.larg/2, -personagem.alt/2, 0);
            glVertex3f( personagem.larg/2,  personagem.alt/2, 0);
            glVertex3f(-personagem.larg/2,  personagem.alt/2, 0);
        glEnd();
        glTranslatef(200, -1080, 0);
        glBegin(GL_TRIANGLE_FAN);
            glVertex3f(-personagem.larg/2, -personagem.alt/2, 0);
            glVertex3f( personagem.larg/2, -personagem.alt/2, 0);
            glVertex3f( personagem.larg/2,  personagem.alt/2, 0);
            glVertex3f(-personagem.larg/2,  personagem.alt/2, 0);
        glEnd();
        glTranslatef(200, -1440, 0);
        glBegin(GL_TRIANGLE_FAN);
            glVertex3f(-personagem.larg/2, -personagem.alt/2, 0);
            glVertex3f( personagem.larg/2, -personagem.alt/2, 0);
            glVertex3f( personagem.larg/2,  personagem.alt/2, 0);
            glVertex3f(-personagem.larg/2,  personagem.alt/2, 0);
        glEnd();
        glTranslatef(-200, -1800, 0);
        glBegin(GL_TRIANGLE_FAN);
            glVertex3f(-personagem.larg/2, -personagem.alt/2, 0);
            glVertex3f( personagem.larg/2, -personagem.alt/2, 0);
            glVertex3f( personagem.larg/2,  personagem.alt/2, 0);
            glVertex3f(-personagem.larg/2,  personagem.alt/2, 0);
        glEnd();
        glTranslatef(-200, -2160, 0);
        glBegin(GL_TRIANGLE_FAN);
            glVertex3f(-personagem.larg/2, -personagem.alt/2, 0);
            glVertex3f( personagem.larg/2, -personagem.alt/2, 0);
            glVertex3f( personagem.larg/2,  personagem.alt/2, 0);
            glVertex3f(-personagem.larg/2,  personagem.alt/2, 0);
        glEnd();
        glTranslatef(200, -2520, 0);
        glBegin(GL_TRIANGLE_FAN);
            glVertex3f(-personagem.larg/2, -personagem.alt/2, 0);
            glVertex3f( personagem.larg/2, -personagem.alt/2, 0);
            glVertex3f( personagem.larg/2,  personagem.alt/2, 0);
            glVertex3f(-personagem.larg/2,  personagem.alt/2, 0);
        glEnd();
    glPopMatrix();


    glutSwapBuffers();
}

void inicializa() {
    glClearColor(1, 1, 1, 0);

    personagem.x = 0.0;
	personagem.y = 0.0;
	personagem.alt = 80.0;
	personagem.larg = 80.0;
}

void redimensiona(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(xBegin, xEnd, yBegin, yEnd, -1, 1);
    glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void teclado(unsigned char key, int x, int y) {
    switch(key) {
        // Tecla ESC
        case 27:
        	//msg confirmação
            exit(0);
            break;
        case 'r':
        case 'R':
            //msg confirmação
        	//reinicia o jogo
            break;
        case 'p':
        case 'P':
            //pausa o jogo
            break;
        case 'W':
        case 'w':
        	// tecla W pressionada
        	moveKeys[0] = 1; 
            glutPostRedisplay();
            break;
        case 'A':
        case 'a':
			// tecla A pressionada
        	moveKeys[1] = 1;
            glutPostRedisplay();
            break;
        case 'S':
        case 's':
			// tecla S pressionada
        	moveKeys[2] = 1;
            glutPostRedisplay();
            break;
        case 'D':
        case 'd':
			// tecla D pressionada
        	moveKeys[3] = 1;
            glutPostRedisplay();
            break;
        default:
            break;
    }
}

void tecladoUp(unsigned char key, int x, int y) {
    switch(key) {
        case 'W':
        case 'w':
		    // tecla W levantada
        	moveKeys[0] = 0;
            glutPostRedisplay();
            break;
		case 'A':
        case 'a':
			// tecla A levantada
        	moveKeys[1] = 0;
            glutPostRedisplay();
            break;
		case 'S':
        case 's':
			// tecla S levantada
        	moveKeys[2] = 0;
            glutPostRedisplay();
            break;
		case 'D':
        case 'd':
			// tecla D levantada
        	moveKeys[3] = 0;
            glutPostRedisplay();
            break;
        default:
            break;
    }
}

void atualiza() {
	// Pressionar duas teclas em eixos distintos geram movimentos diagonais
	// Pressionar duas teclas no mesmo eixo cancelam o movimento
	for (int i = 0; i < 4; ++i) { 
		if (moveKeys[i]) {
			switch(i) {
				// Tecla W
				case 0:
					personagem.y += 20;
					break;
				// Tecla A
				case 1:
					personagem.x -= 15;
					break;
				// Tecla S
				case 2:
					personagem.y -= 15;
					break;
				// Tecla D
				case 3:
					personagem.x += 15;
					break;
				default:
            		break;
			}
		}
	}

    yBegin-=10;
    yEnd-=10;
    personagem.y -= 10;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(xBegin, xEnd, yBegin, yEnd, -1, 1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    glutPostRedisplay();
    glutTimerFunc(33, atualiza, 0);
} 

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(1280, 720);
    glutInitWindowPosition(0, 0);

    glutCreateWindow("TP1 - nome do jogo");
    
    // Callbacks
    glutDisplayFunc(desenhaCena);
    glutReshapeFunc(redimensiona);
    glutKeyboardFunc(teclado);
    glutKeyboardUpFunc(tecladoUp);
    glutTimerFunc(0, atualiza, 0);
    inicializa();

    glutMainLoop();
    return 0;
}