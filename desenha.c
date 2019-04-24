void desenhaCena() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f (1, 1, 1);
    switch (telas) {
        case 0:
            // Tela inicial
            glPushMatrix();
                glTranslatef(0, 0, 0);
                desenha_fundo(tela);
                escreve(GLUT_BITMAP_TIMES_ROMAN_24, "<Enter> para inciar o jogo", xBegin + 50, yBegin + 696, 1);
            glPopMatrix();
            break;
        case 1:
            // Desenha o fundo
            glPushMatrix();
                glTranslatef(0, 0, 0);
                desenha_fundo(fundo);
            glPopMatrix();

            // Desenha o personagem
            glPushMatrix();
                glTranslatef(personagem.x, personagem.y, 0);
                if (personagem.direcao) {
                    desenhaCorpo(personagem.larg,personagem.alt,pessoa_cima);
                } else {
                    desenhaCorpo(personagem.larg,personagem.alt,pessoa_baixo);
                }
            glPopMatrix();

            // Desenha os inimigos
            for (int i = 0; i < enemies_num; ++i) {
                glPushMatrix();
                    glTranslatef(enemies[i].x, enemies[i].y, 0);
                    if (enemies[i].direcao) {
                        desenhaCorpo(enemies[i].larg,enemies[i].alt,peixe_dir);
                    } else {
                        desenhaCorpo(enemies[i].larg,enemies[i].alt,peixe_esq);
                    }
                glPopMatrix();
            }

            // Desenha as moedas
            for (int i = 0; i < moedas_num; ++i) {
                glPushMatrix();
                    glTranslatef(moedas[i].x, moedas[i].y, 0);
                    desenhaCorpo(moedas[i].larg,moedas[i].alt,moeda);
                glPopMatrix();
            }
            break;
        case 2:
            // Tela final
            glPushMatrix();
                glTranslatef(0, 0, 0);
                desenha_fundo(tela);
                score_final();
                escreve(GLUT_BITMAP_TIMES_ROMAN_24, score, xBegin + 50, yBegin + 696, 1);
            glPopMatrix();
            break;
        default:
            break;
    }
    hud();

    glutSwapBuffers();
}