#include <GL/glew.h>
#include <GL/freeglut.h>
#include <SOIL/SOIL.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#include "global.h"
#include "global.c"
 
void inicializa() {
    glClearColor(.1, .2, .75, 0);
    srand(time(0));
    personagem_init();
    enemies_init();
}

void desenhaCena() {
    glClear(GL_COLOR_BUFFER_BIT);
    
    glColor3f(0, 0, 0);
    
    glPushMatrix();
        glTranslatef(personagem.x, personagem.y, 0);
        desenhaCorpo(personagem.larg,personagem.alt);
    glPopMatrix();

    glColor3f(1, 0, 0);
    for (int i = 0; i < enemies_num; ++i) {
        glPushMatrix();
            glTranslatef(enemies[i].x, enemies[i].y, 0);
            desenhaCorpo(enemies[i].larg,enemies[i].alt);
        glPopMatrix();
    }

    glutSwapBuffers();
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
					personagem.y += (personagem.velo + 8);
					break;
				// Tecla A
				case 1:
					personagem.x -= personagem.velo;
					break;
				// Tecla S
				case 2:
					personagem.y -= personagem.velo;
					break;
				// Tecla D
				case 3:
					personagem.x += personagem.velo;
					break;
				default:
            		break;
			}
		}
	}

    for (int i = 0; i < enemies_num; ++i) {
        enemies[i].x += enemies[i].velo;
        enemies[i].y -= 8;
        limiteX(enemies[i].x, enemies[i].larg/2, 1, i);
    }

    yBegin -= 15;
    yEnd -= 15;
    personagem.y -= 18;
    limiteX(personagem.x, personagem.larg/2, 0, 0);
    limiteY(personagem.y, personagem.alt/2);
    
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