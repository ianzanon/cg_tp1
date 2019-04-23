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
	personagem.alt = 80;
	personagem.larg = 80;
	personagem.velo = 20;
}

void enemies_init() {
	for (int i = 0; i < enemies_num; ++i) {
        enemies[i].x = -(rand() % xBegin) + rand() % xEnd;
		enemies[i].y = next_enemy;
		enemies[i].alt = 80;
		enemies[i].larg = 80;
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
		next_enemy -= (250 + rand() % 450);
	}
}

void moedas_init() {
    for (int i = 0; i < moedas_num; ++i) {
        moedas[i].x = -(rand() % xBegin) + rand() % xEnd;
        moedas[i].y = next_coin;
        moedas[i].alt = 50;
        moedas[i].larg = 50;
        moedas[i].velo = 0;
        next_coin -= (250 + rand() % 450);
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

void atualiza_score() {
    sprintf(score, "Moedas: %d", moedas_coletadas);
}

void descer() {
    // Rolagem do mapa 15 por segundo
    yBegin -= 15;
    yEnd -= 15;
    // Personagem cai numa velocidade de 3 por segundo
    personagem.y -= 18;
}

void subir() {
    // Sobe até a tela esconder o primeiro inimigo
    if (personagem.y < enemies[0].y + 1440) {
        // Rolagem do mapa 30 por segundo
        yBegin += 30;
        yEnd += 30;
        // Personagem sobe numa velocidade de 5 por segundo
        personagem.y += 40;
        // Após o personagem ultrapassar o primeiro inimigo em 500
        if(personagem.y > enemies[0].y && personagem.y - enemies[0].y > 1000) {
            pause = 1;
        }
    }
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