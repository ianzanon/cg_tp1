void personagem_init() {
	personagem.x = 0;
	personagem.y = 0;
	personagem.alt = 80;
	personagem.larg = 80;
	personagem.velo = 20;
}

void enemies_init() {
	for (int i = 0; i < enemies_num; ++i) {
        enemies[i].x = xBegin/2 + rand() % xEnd;
		enemies[i].y = next_enemy;
		enemies[i].alt = 80;
		enemies[i].larg = 80;
		enemies[i].velo = 15 + rand() % 26;
		next_enemy -= (350 + rand() % 850);
	}
}

void desenhaCorpo(float largura, float altura) {
    glBegin(GL_TRIANGLE_FAN);
        glVertex3f(-largura/2, -altura/2, 0);
        glVertex3f( largura/2, -altura/2, 0);
        glVertex3f( largura/2,  altura/2, 0);
        glVertex3f(-largura/2,  altura/2, 0);
    glEnd();
}

void limiteX(int x, int largura, int enemy, int index) {
    // Limitar movimento do personagem dentro tela
    // ESQUERDA
    if (x-(largura) <= xBegin) {
        if (enemy) {
    		enemies[index].velo *= -1;
        } else {
			personagem.x = xBegin + largura;
        }
    }
    // DIREITA
    if (x+(largura) >= xEnd) {
        if (enemy) {
    		enemies[index].velo *= -1;
        } else {
        	personagem.x = xEnd - largura;
    	}
    }
}

void limiteY(int y, int altura) {
    // Limitar movimento do personagem dentro tela
    // TOPO
    if (y+(altura) >= yEnd) {
        personagem.y = yEnd - altura;
    }
    // BAIXO
    if (y-(altura) <= yBegin) {
        personagem.y = yBegin + altura;
    }
}