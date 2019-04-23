void hud() {
    switch(last_char) {
        case 'r':
            escreve(GLUT_BITMAP_TIMES_ROMAN_24, "R novamente para reiniciar o jogo ou P para resumir", xBegin + 35, yBegin + 35, 1);
            break;
        case ' ':
            escreve(GLUT_BITMAP_TIMES_ROMAN_24, "ESC novamente para encerrar o jogo ou P para resumir", xBegin + 35, yBegin + 35, 1);
            break;
        case 'p':
            escreve(GLUT_BITMAP_TIMES_ROMAN_24, "P para resumir", xBegin + 35, yBegin + 35, 1);
            break;
        default:
            break;
    }

    escreve(GLUT_BITMAP_TIMES_ROMAN_24, score, xEnd - 450, yEnd - 100, 1);
}