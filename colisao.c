void colidir(Object enemies[], int colisao[]) {
    for (int i = 0; i < enemies_num; ++i) {
        // Soma das distâncias entre os centros até as extremidades
        somaLarguras = personagem.larg/2 + enemies[i].larg/2;
        somaAlturas = personagem.alt/2 + enemies[i].alt/2;
        // Personagem está a esquerda ou direita do inimigo?
        if (personagem.x < enemies[i].x) {
            distanciaX = enemies[i].x - personagem.x;
        } else {
            distanciaX = personagem.x - enemies[i].x;
        }
        // Personagem está acima ou abaixo do inimigo?
        if (personagem.y > enemies[i].y) {
            distanciaY = personagem.y - enemies[i].y;
        } else {
            distanciaY = enemies[i].y - personagem.y;
        }
        if ((somaLarguras > distanciaX) && (somaAlturas > distanciaY)) {
            colisao[0] = 1;
            colisao[1] = i;
            break;
        }
    }
}