void carrega_textura() {
	pessoa_cima = SOIL_load_OGL_texture(
        "../src/char/char.png",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y
	);
	pessoa_baixo = SOIL_load_OGL_texture(
        "../src/char/char2.png",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y
	);
	peixe_esq = SOIL_load_OGL_texture(
        "../src/enemies/peixe.png",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y
	);
	peixe_dir = SOIL_load_OGL_texture(
        "../src/enemies/peixe2.png",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y
	);
	moeda = SOIL_load_OGL_texture(
        "../src/itens/moeda.png",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y
	);
	fundo = SOIL_load_OGL_texture(
        "../src/fundo/fundo2.png",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y
	);
	tela = SOIL_load_OGL_texture(
        "../src/fundo/fundo.png",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y
	);
}