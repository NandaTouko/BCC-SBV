USE ATHLANTIC;

INSERT INTO ADMINISTRADORES (
	ADM_NOME,
    ADM_SENHA,
    ADM_EMAIL
) VALUES (
	'João V. R. Maciel',
    'jaozinho',
    'jao@gmail.com'
);

INSERT INTO ADMINISTRADORES (
	ADM_NOME,
    ADM_SENHA,
    ADM_EMAIL
) VALUES (
	'Amanda Moreira',
    'amanda123',
    'amanda@gmail.com'
);

SELECT * FROM ADMINISTRADORES;
-- DELETE FROM ADMINISTRADORES; -- Deleta todas as linhas
-- ALTER TABLE ADMINISTRADORES AUTO_INCREMENT = 1; -- Retorna o contador pro número desejado

INSERT INTO PATROCINADORES (
	PTS_PESSOA_FISICA,
    PTS_NOME,
    PTS_CPF_CNPJ,
    PTS_TELEFONE,
    PTS_DATA_CADASTRO,
    PTS_SITE_URL,
    PTS_EMAIL
) VALUES (
	1,
    'Fernando Carlos',
    '472.036.318-00',
    '(16)99608-9808',
    current_date(),
    'www.fernando.com.br',
    'fernando@gmail.com'
);

INSERT INTO PATROCINADORES (
	PTS_PESSOA_FISICA,
    PTS_NOME,
    PTS_CPF_CNPJ,
    PTS_TELEFONE,
    PTS_DATA_CADASTRO,
    PTS_SITE_URL,
    PTS_EMAIL
) VALUES (
	1,
    'Carla Joaninha',
    '488.999.318-00',
    '(16)99608-0589',
    current_date(),
    'www.carla.com.br',
    'carla@gmail.com'
);

SELECT * FROM PATROCINADORES;

INSERT INTO MODALIDADES_ESPORTIVAS (
	MDE_TIPO_DE_ESPORTE,
    MDE_NOME,
    MDE_GENERO
) VALUES (
	1,
    'Vôlei',
    1
);