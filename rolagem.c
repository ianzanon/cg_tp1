void descer() {
    // Rolagem do mapa 15 por segundo
    yBegin -= 15;
    yEnd -= 15;
    // Personagem cai numa velocidade de 3 por segundo
    personagem.y -= 18;
}

void subir() {
    personagem.direcao = 1;
    // Sobe até a tela esconder o primeiro inimigo
    if (personagem.y < enemies[0].y + 1440) {
        // Rolagem do mapa 30 por segundo
        yBegin += 30;
        yEnd += 30;
        // Personagem sobe numa velocidade de 5 por segundo
        personagem.y += 40;
        // Após o personagem ultrapassar o primeiro inimigo em 500
        if(personagem.y > enemies[0].y && personagem.y - enemies[0].y > 1000) {
            telas = 2;
            reset();
        }
    }
}