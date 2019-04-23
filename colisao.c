void colidir(Object alvo[], int colisao[]) {
    for (int i = 0; i < enemies_num; ++i) {
        // Soma das distâncias entre os centros até as extremidades
        somaLarguras = personagem.larg/2 + alvo[i].larg/2;
        somaAlturas = personagem.alt/2 + alvo[i].alt/2;
        // Personagem está a esquerda ou direita do inimigo?
        if (personagem.x < alvo[i].x) {
            distanciaX = alvo[i].x - personagem.x;
        } else {
            distanciaX = personagem.x - alvo[i].x;
        }
        // Personagem está acima ou abaixo do inimigo?
        if (personagem.y > alvo[i].y) {
            distanciaY = personagem.y - alvo[i].y;
        } else {
            distanciaY = alvo[i].y - personagem.y;
        }
        if ((somaLarguras > distanciaX) && (somaAlturas > distanciaY)) {
            colisao[0] = 1;
            colisao[1] = i;
            break;
        }
    }
}