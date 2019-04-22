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

	// Movimento dos inimigos
    for (int i = 0; i < enemies_num; ++i) {
        enemies[i].x += enemies[i].velo;
        enemies[i].y -= 8;
        limiteX(enemies[i].x, enemies[i].larg/2, 1, i);
    }

    // Rolagem do mapa 15 por segundo
    yBegin -= 15;
    yEnd -= 15;
    // Personagem cai numa velocidade de 3 por segundo
    personagem.y -= 18;

    limiteX(personagem.x, personagem.larg/2, 0, 0);
    limiteY(personagem.y, personagem.alt/2);

    
    colidir(enemies,colisao);
    if (colisao[0]) {
        enemies[colisao[1]].velo = 0;
        enemies[colisao[1]].velo = 0;
    }

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(xBegin, xEnd, yBegin, yEnd, -1, 1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    glutPostRedisplay();
    glutTimerFunc(33, atualiza, 0);
}