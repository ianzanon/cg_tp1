void escreve(void* fonte, char* texto, float x, float y, float z) {
    glRasterPos3f(x, y, z);
    glPushMatrix();
        for (int i = 0; i < strlen(texto); i++) {
            glutBitmapCharacter(fonte, texto[i]);
        }
    glPopMatrix();
}

void personagem_init() {
	personagem.x = 0;
	personagem.y = 0;
	personagem.alt = 257;
	personagem.larg = 80;
	personagem.velo = 20;
    // Apontado para baixo
    personagem.direcao = 0;
}

void enemies_init() {
	for (int i = 0; i < enemies_num; ++i) {
        enemies[i].x = -(rand() % xBegin) + rand() % xEnd;
		enemies[i].y = next_enemy;
		enemies[i].alt = 60;
		enemies[i].larg = 112;
        enemies[i].direcao = 1;
        // Quanto mais fundo, mais rápidos são os inimigos
        if (i < 10) {
            enemies[i].velo = 20 + rand() % 31;
        } else if (i < 20) {
            enemies[i].velo = 35 + rand() % 46;
        } else if (i < 40) {
            enemies[i].velo = 50 + rand() % 61;
        } else if (i < 60) {
            enemies[i].velo = 65 + rand() % 76;
        } else {
            enemies[i].velo = 75 + rand() % 86;
        }
		next_enemy -= (300 + rand() % 450);
	}
}

void moedas_init() {
    for (int i = 0; i < moedas_num; ++i) {
        moedas[i].x = -(rand() % xBegin) + rand() % xEnd;
        moedas[i].y = next_coin;
        moedas[i].alt = 71;
        moedas[i].larg = 33;
        moedas[i].velo = 0;
        next_coin -= (300 + rand() % 450);
    }
}

void desenha_fundo(int textura) {
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, textura);
    glBegin(GL_TRIANGLE_FAN);
        glTexCoord2f(0, 0); glVertex3f(xBegin, yBegin, 0);
        glTexCoord2f(1, 0); glVertex3f(  xEnd, yBegin, 0);
        glTexCoord2f(1, 1); glVertex3f(    xEnd, yEnd, 0);
        glTexCoord2f(0, 1); glVertex3f(  xBegin, yEnd, 0);
    glEnd();
    glDisable(GL_TEXTURE_2D);
}

void desenhaCorpo(float largura, float altura, int textura) {
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, textura);
    glBegin(GL_TRIANGLE_FAN);
        glTexCoord2f(0, 0); glVertex3f(-largura/2, -altura/2, 0);
        glTexCoord2f(1, 0); glVertex3f( largura/2, -altura/2, 0);
        glTexCoord2f(1, 1); glVertex3f( largura/2,  altura/2, 0);
        glTexCoord2f(0, 1); glVertex3f(-largura/2,  altura/2, 0);
    glEnd();
    glDisable(GL_TEXTURE_2D);
}

void atualiza_score() {
    sprintf(score, "Moedas: %d", moedas_coletadas);
}

void score_final() {
    sprintf(score, "Total: %d moedas", moedas_coletadas);
}

void reduz_velo() {
    for (int i = 0; i < enemies_num; ++i) {
        if(enemies[i].velo > 0) {
            enemies[i].velo = 15;
        } else {
            enemies[i].velo = -15;
        }
    }
}

void inverte_peixe(int index) {
    if (enemies[index].velo > 0) {
        enemies[index].direcao = 1;
    } else {
        enemies[index].direcao = 0;
    }
}

void limiteX(int x, int largura, int enemy, int index) {
    // Limitar movimento do personagem dentro tela
    // ESQUERDA
    if (x-(largura) <= xBegin) {
        if (enemy) {
    		enemies[index].velo *= -1;
            inverte_peixe(index);
        } else {
			personagem.x = xBegin + largura;
        }
    }
    // DIREITA
    if (x+(largura) >= xEnd) {
        if (enemy) {
    		enemies[index].velo *= -1;
            inverte_peixe(index);
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