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
	    // Reduz a velocidade durante a rolagem
	    enemies[i].y += control_speed;
	    limiteX(enemies[i].x, enemies[i].larg/2, 1, i);
	}

	// Reduz a velocidade durante a rolagem
	for (int i = 0; i < moedas_num; ++i) {
	    moedas[i].y += control_speed;
	}

	if (personagem.y + personagem.alt < moedas[moedas_num-1].y) {
		descendo = 0;
		reduz_velo();
		control_speed = 8;
	} 

	if (!descendo) {
		subir();
	} else {
		descer();
	}

	limiteX(personagem.x, personagem.larg/2, 0, 0);
	limiteY(personagem.y, personagem.alt/2);

	colidir(enemies,colisao_enemy);
	if (colisao_enemy[0]) {
		enemies[colisao_enemy[1]].x = xEnd+1;
	    enemies[colisao_enemy[1]].alt = 0;
	    enemies[colisao_enemy[1]].larg = 0;
	    moedas_coletadas--;
	    atualiza_score();
	    // Para a condição
	    colisao_enemy[0] = 0;
	    descendo = 0;
		reduz_velo();
		control_speed = 8;
	}

	colidir(moedas,colisao_moeda);
	if (colisao_moeda[0]) {
		// Moeda "some", zera largura e altura e é redesenhada fora da tela
		moedas[colisao_moeda[1]].x = xEnd+1;
	    moedas[colisao_moeda[1]].alt = 0;
	    moedas[colisao_moeda[1]].larg = 0;
	    moedas_coletadas++;
	    atualiza_score();
	    colisao_moeda[0] = 0;
	}

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(xBegin, xEnd, yBegin, yEnd, -1, 1);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glutPostRedisplay();
	if (!pause) {
    	glutTimerFunc(33, atualiza, 0);
    }
}