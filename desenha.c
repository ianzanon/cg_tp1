void desenhaCena() {
    glClear(GL_COLOR_BUFFER_BIT);
    
    // Desenha o personagem
    glColor3f(0, 0, 0);
    glPushMatrix();
        glTranslatef(personagem.x, personagem.y, 0);
        desenhaCorpo(personagem.larg,personagem.alt);
    glPopMatrix();

    // Desenha os inimigos
    glColor3f(1, 0, 0);
    for (int i = 0; i < enemies_num; ++i) {
        glPushMatrix();
            glTranslatef(enemies[i].x, enemies[i].y, 0);
            desenhaCorpo(enemies[i].larg,enemies[i].alt);
        glPopMatrix();
    }

    // Desenha as moedas
    glColor3f(0, 1, 0);
    for (int i = 0; i < moedas_num; ++i) {
        glPushMatrix();
            glTranslatef(moedas[i].x, moedas[i].y, 0);
            desenhaCorpo(moedas[i].larg,moedas[i].alt);
        glPopMatrix();
    }

    glColor3f(1, 1, 1);
    hud();

    glutSwapBuffers();
}