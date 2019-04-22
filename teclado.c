void teclado(unsigned char key, int x, int y) {
    switch(key) {
        // Tecla ESC
        case 27:
        	//msg confirmação
            exit(0);
            break;
        case 'r':
        case 'R':
            //msg confirmação
        	//reinicia o jogo
            break;
        case 'p':
        case 'P':
            //pausa o jogo
            break;
        case 'W':
        case 'w':
        	// tecla W pressionada
        	moveKeys[0] = 1; 
            glutPostRedisplay();
            break;
        case 'A':
        case 'a':
			// tecla A pressionada
        	moveKeys[1] = 1;
            glutPostRedisplay();
            break;
        case 'S':
        case 's':
			// tecla S pressionada
        	moveKeys[2] = 1;
            glutPostRedisplay();
            break;
        case 'D':
        case 'd':
			// tecla D pressionada
        	moveKeys[3] = 1;
            glutPostRedisplay();
            break;
        default:
            break;
    }
}

void tecladoUp(unsigned char key, int x, int y) {
    switch(key) {
        case 'W':
        case 'w':
		    // tecla W levantada
        	moveKeys[0] = 0;
            glutPostRedisplay();
            break;
		case 'A':
        case 'a':
			// tecla A levantada
        	moveKeys[1] = 0;
            glutPostRedisplay();
            break;
		case 'S':
        case 's':
			// tecla S levantada
        	moveKeys[2] = 0;
            glutPostRedisplay();
            break;
		case 'D':
        case 'd':
			// tecla D levantada
        	moveKeys[3] = 0;
            glutPostRedisplay();
            break;
        default:
            break;
    }
}