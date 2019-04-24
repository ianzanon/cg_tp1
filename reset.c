void reset() {
    glClearColor(.1, .2, .75, 0);
    srand(time(0));
    inicio = 0;
    telas = 0;
    xBegin = -1280;
    xEnd = 1280;
    yBegin = -720;
    yEnd = 720;
    control_speed = -8;
    next_enemy = -500;
    next_coin = -500;
    moedas_coletadas = 0;
    pause = 1;
    last_char = 'a';
    descendo = 1;
    atualiza_score();
    personagem_init();
    enemies_init();
    moedas_init();
	glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(xBegin, xEnd, yBegin, yEnd, -1, 1);
    glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
    atualiza();
}
