#include <GL/glew.h>
#include <GL/freeglut.h>
#include <SOIL/SOIL.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#include "global.h"
#include "global.c"
#include "desenha.c"
#include "teclado.c"
#include "colisao.h"
#include "colisao.c"
#include "atualiza.c"

void inicializa() {
    glClearColor(.1, .2, .75, 0);
    srand(time(0));
    personagem_init();
    enemies_init();
}

void redimensiona(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(xBegin, xEnd, yBegin, yEnd, -1, 1);
    glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
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