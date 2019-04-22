void personagem_init() {
	personagem.x = 0;
	personagem.y = 0;
	personagem.alt = 80;
	personagem.larg = 80;
}

void desenhaCorpo(float largura, float altura) {
    glBegin(GL_TRIANGLE_FAN);
        glVertex3f(-largura/2, -altura/2, 0);
        glVertex3f( largura/2, -altura/2, 0);
        glVertex3f( largura/2,  altura/2, 0);
        glVertex3f(-largura/2,  altura/2, 0);
    glEnd();
}

void limiteTela(int x, int y, int largura, int altura) {
    // Limitar movimento do personagem dentro tela
    // TOPO
    if (y+(altura) >= yEnd) {
        personagem.y = yEnd-(altura);
    }
    // ESQUERDA
    if (x-(largura) <= xBegin) {
        personagem.x = xBegin+(largura);
    }
    // BAIXO
    if (y-(altura) <= yBegin) {
        personagem.y = yBegin+(altura);
    }
    // DIREITA
    if (x+(largura) >= xEnd) {
        personagem.x = xEnd-(largura);
    }
}