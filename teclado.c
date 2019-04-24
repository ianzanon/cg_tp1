void teclado(unsigned char key, int x, int y) {
    switch(key) {
        // Tecla ESC
        case 27:
        	pause = 1;
        	if (last_char == ' ') {
            	exit(0);
        	}
        	last_char = ' ';
        	glutPostRedisplay();
            break;
        case 13:
            inicio = 1;
            telas = 1;
            pause = 0;
            atualiza();
            glutPostRedisplay();
            break;
        case 'r':
        case 'R':
        	pause = 1;
            if (last_char == 'r') {
            	reset();    
            } else {
            	last_char = 'r';
            	glutPostRedisplay();
            }
            break;
        case 'p':
        case 'P':
            if (pause) {
            	pause = 0;
                last_char = 'a';
                atualiza();
            } else {
                pause = 1;
                last_char = 'p';
            }
            glutPostRedisplay();
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