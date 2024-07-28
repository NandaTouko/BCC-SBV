USE ATHLANTIC;

-- INSERTS DE TODOS OS GRUPOS

INSERT INTO MODALIDADES_ESPORTIVAS
(MDE_TIPO_DE_ESPORTE, MDE_NOME, MDE_GENERO)
VALUES
(1, 'Atletismo', 3),
(2, 'Volei', 1),
(2, 'Volei', 2),
(2, 'Basquete', 3),
(2, 'Futsal', 1),
(2, 'Futsal', 2),
(2, 'Handebol', 3),
(2, 'Natacao', 3),
(2, 'Xadrez', 3),
(2, 'Tenis de Mesa', 3);

INSERT INTO AUTORIDADES_MODALIDADES
(FK_MODADLIDADE_ESPORTIVA_MDE_ID)
VALUES
(1),
(2),
(3),
(4),
(5),
(6),
(7),
(8),
(9),
(10);

INSERT INTO AUTORIDADES 
(ATD_MODALIDADE_ESPORTIVA, ATD_CERTIFICACAO, ATD_TELEFONE, ATD_IDENTIFICACAO_FISCAL, ATD_NOME, ATD_EMAIL, ATD_FUNCAO)  
VALUES 
('6', 'PREMIAÇAO', '19984309999','12345678901', 'LUCAS', 'LUCAS69@GMAIL.COM', 'ARBITRO'),
('8', 'PREMIAÇAO', '19984309888','12345678902', 'SAMUEL', 'SAMUEL69@GMAIL.COM', 'ARBITRO'),
('10', 'PREMIAÇAO', '19984309777','12345678903', 'GUILHERME', 'GUILHERME69@GMAIL.COM', 'ARBITRO'),
('3', 'PREMIAÇAO', '19984309666','12345678904', 'VINICIUS', 'VINICIUS69@GMAIL.COM', 'ARBITRO'),
('5', 'PREMIAÇAO', '19984309555','12345678905', 'DIRSON', 'DIRSONBLACK69@GMAIL.COM', 'ARBITRO'),
('1', 'PREMIAÇAO', '19984309444','12345678906', 'OTAVIO', 'OTAVIO69@GMAIL.COM', 'ARBITRO'),
('2', 'PREMIAÇAO', '19984309333','12345678907', 'BLASCK', 'GOSTOSO69@GMAIL.COM', 'ARBITRO'),
('4', 'PREMIAÇAO', '19984309222','12345678908', 'MURILO', 'MURILO69@GMAIL.COM', 'ARBITRO'),
('7', 'PREMIAÇAO', '19984309222','12345678908', 'GIUSEPPE', 'GIUSEPPE69@GMAIL.COM', 'ARBITRO'),
('9', 'PREMIAÇAO', '19984309222','12345678908', 'MATHEUS', 'MATHEUS69@GMAIL.COM', 'ARBITRO');

INSERT INTO PLANOS 
(PLA_CUSTO, PLA_VANTAGEM, PLA_NOME) 
VALUES 
(99.50, 'Acesso a todas as instalações', 'Plano Premium'), 
(59.99, 'Acesso a academia e piscina', 'Plano Fitness'),
(79.99, 'Acesso a todos os eventos esportivos', 'Plano Esportes'),
(49.99, 'Acesso limitado durante a semana', 'Plano Econômico'), 
(109.99, 'Acesso ilimitado com descontos em eventos', 'Plano VIP'), 
(29.99, 'Acesso aos fins de semana', 'Plano Fim de Semana'), 
(39.99, 'Acesso a cursos e workshops', 'Plano Educativo');

INSERT INTO FORNECEDORES
(FOR_NOME, FOR_DESCRICAO, FOR_CONTATO, FOR_ENDERECO, FOR_ATIVO)
VALUES
("Fornecedor1","Fornecemos coisas de primeira linha","1111111111","São João da Boa Vista",1),
("Fornecedor2","Fornecemos coisas de segunda linha","2222222222","Mogi Mirim",1),
("Fornecedor3","Fornecemos coisas de terceira linha","333333333","Vargem Grande do Sul",1),
("Fornecedor4","Fornecemos coisas de quarta linha","44444444444","Itapira",1),
("Fornecedor5","Fornecemos coisas de quinta linha","55555555555","Monte Santo de Minas",1),
("Fornecedor6","Fornecemos coisas de sexta linha","666666666666","Espírito Santo do Pinhal",1);

INSERT INTO CHAMADOS 
(CHA_NOME, CHA_DESCRICAO)
VALUES
('Suporte Quadra AAACH', 'Quadra com problemas de goteiras'),
('Equipamentos Esportivos', 'Faltam 3 Bolas de Volei'),
('Procura de Novos Integrantes', 'Atletica necessita de novos integrantes para Financeiro'),
('Falta de Segurança em jogos', 'Pessoas não autorizadas entraram nos jogos particulares'),
('Compra de Bebidas para Festa', 'Comprar 8 fardos de cereveja'),
('Suplementação', 'Falta do SUCO para os atletas');

INSERT INTO FUNCIONALIDADES
(FUN_NOME)
VALUES
('Gerir o dinheiro da Atletica'),
('Gerir os atletas da Atletica'),
('Organizar os eventos da Atletica'),
('Gerir os times da Atletica'),
('Treinar o time de natação'),
('Treinar o time de futebol'),
('Treinar o time de basquete');

INSERT INTO CARGOS
(CAR_NOME) 
VALUES
('Diretor de Eventos'), 
('Diretor de Comunicação'), 
('Diretor de Esportes'), 
('Presidente'), 
('Vice-Presidente'), 
('Diretor Financeiro');

INSERT INTO PATROCINADORES
(PTS_TELEFONE, PTS_SITE_URL, PTS_CPF_CNPJ, PTS_PESSOA_FISICA, PTS_DATA_CADASTRO, PTS_NOME, PTS_EMAIL, PTS_ATIVO)
VALUES
/* PTS_PESSOA_FISICA = 0 ou 1 (0 para pessoa jurídica e 1 para pessoa física) */
('19996587070', 'https://www.itau.com.br/', '32145678000154', 0, '2022-05-19', 'Roberto Itau', 'roberto.itau@itau.com', 1),
('19956738245', 'https://www.nubank.com.br/', '62451973000147', 0, '2021-05-28', 'Geraldo Nubank', 'geraldo.nubank@nubank.com', 1),
('19945612758', 'https://www.google.com.br/', '42597816000126', 0, '2023-01-14', 'Marco Google', 'marco.google@gmail.com', 1),
('19954279156', 'https://www.milkmoni.com.br/', '24519764000187', 0, '2022-10-01', 'Robson MilkMoni', 'robson.milkmoni@gmail.com', 1),
('19942657813', 'https://www.netflix.com.br/', '75315924000182', 0, '2022-02-02', 'Neti Flicsi', 'neti.flicsi@gmail.com', 1),
('19944276159', 'https://www.amazon.com.br/', '45216859000134', 0, '2021-03-15', 'Ama Zompraime', 'ama.zompraime@gmail.com', 1),
('19978523565', 'https://www.santander.com.br/', '24675194000125', 0, '2022-04-01', 'São Tander', 'sao.tander@gmail.com', 1);

INSERT INTO ADMINISTRADORES
(ADM_NOME, ADM_SENHA, ADM_EMAIL)
VALUES
('MARCO', 'EUSOUGATAO', 'MARCOGATAO@GMAIL.COM'),
('MATEUS', 'EUSOUGENTIL', 'MATEUSGENTIL@GMAIL.COM'),
('AMANDA', 'EUSOUFELIZ', 'AMANDAFELIZ@GMAIL.COM'),
('KRATOS', 'EUSOUGODKILLER', 'KRATOSGODKILLER@GMAIL.COM'),
('NARUTO', 'EUSOUHOKAGE', 'NARUTOHOKAGE@GMAIL.COM'),
('BATMAN', 'EUSOUPREPARADO', 'BATMANPREPARADO@GMAIL.COM'),
('MESSI', 'EUSOUCAMPEAOMUNDIAL', 'MESSICAMPEAOMUNDIAL@GMAIL.COM');

INSERT INTO PRODUTOS
(PRO_NOME, PRO_DESCRICAO, PRO_QUANTIDADE, PRO_STATUS, PRO_EXCLUSIVIDADE, PRO_EXCLUIDO, FK_FORNECEDORES_FOR_ID)
VALUES
('CANECA IFSP SJBV', 'Caneca verde da atletica de São João da Boa Vista', 20, 'Available', 0, 0, 1),
('MOLETOM IFSP SJBV 2019', 'MOLETOM DA ATLETICA DE SÃO JOÃO DA BOA VISTA DO ANO DE 2019', 15, 'Available', 0, 0, 1),
('SAMBA ATLETICA', 'SAMBA ATLETICA MASCULINA DA ATLETICA DE SÃO JOÃO DA BOA VISTA', 30, 'Available', 0, 0, 1),
('MOLETOM IFSP SJBV 2023', 'MOLETOM DA ATLETICA DE SÃO JOÃO DA BOA VISTA DO ANO DE 2023', 14, 'Available', 0, 0,2),
('COLETE PERSONALIZADO IFSP PIRACICABA', 'COLETE PERSONALIZADO DA ATLETICA DE PIRACICABA', 35, 'Available', 0, 0, 3),
('KIT CAPIFARRA MASCULINO IFSP PIRACICABA', 'KIT CAPIFARRA MASCULINO COM 2 COLETES E 2 SAMBAS ATLETICAS DA ATLETICA DE PIRACICABA', 16, 'Available', 0, 0, 3),
('SHORTS DOLL IFSP PIRACICABA', 'SHORTS DOLL DA ATLETICA DE POIRACICABA', 27, 'Available', 0, 0, 3);

INSERT INTO PRODUTOS_IMAGENS 
(PDI_IMAGEM, FK_PRODUTOS_PRO_ID)
VALUES
('https://www.google.com/url?sa=i&url=https%3A%2F%2Fcbt.ifsp.edu.br%2Findex.php%2Fatletica&psig=AOvVaw30VYZ1BBdUXMjYhWFY4kgx&ust=1700671016428000&source=images&cd=vfe&opi=89978449&ved=0CBEQjRxqFwoTCKC-j7DD1YIDFQAAAAAdAAAAABAE', 1),
('https://www.google.com/url?sa=i&url=https%3A%2F%2Fm.facebook.com%2Fatleticaifspsaocarlos%2F&psig=AOvVaw0I9PyqfEVhBq9Glf_jF2wx&ust=1700671108233000&source=images&cd=vfe&opi=89978449&ved=0CBEQjRxqFwoTCOj37dvD1YIDFQAAAAAdAAAAABAJ', 2),
('https://www.google.com/url?sa=i&url=https%3A%2F%2Fwww.facebook.com%2Fatleticaifspsaocarlos%2F%3Flocale%3Dpt_BR&psig=AOvVaw0I9PyqfEVhBq9Glf_jF2wx&ust=1700671108233000&source=images&cd=vfe&opi=89978449&ved=0CBEQjRxqFwoTCOj37dvD1YIDFQAAAAAdAAAAABAR', 3),
('https://www.google.com/url?sa=i&url=https%3A%2F%2Fwww.facebook.com%2Fatletica1defevereiro%2F%3Flocale%3Dpt_BR&psig=AOvVaw0I9PyqfEVhBq9Glf_jF2wx&ust=1700671108233000&source=images&cd=vfe&opi=89978449&ved=0CBEQjRxqFwoTCOj37dvD1YIDFQAAAAAdAAAAABAZ', 4),
('https://www.google.com/url?sa=i&url=https%3A%2F%2Fwww.facebook.com%2Fatletica1defevereiro%2F%3Flocale%3Dpt_BR&psig=AOvVaw0I9PyqfEVhBq9Glf_jF2wx&ust=1700671108233000&source=images&cd=vfe&opi=89978449&ved=0CBEQjRxqFwoTCOj37dvD1YIDFQAAAAAdAAAAABAh', 5),
('https://www.google.com/url?sa=i&url=https%3A%2F%2Fwww.facebook.com%2Fatletica1defevereiro%2F%3Flocale%3Dpt_BR&psig=AOvVaw0I9PyqfEVhBq9Glf_jF2wx&ust=1700671108233000&source=images&cd=vfe&opi=89978449&ved=0CBEQjRxqFwoTCOj37dvD1YIDFQAAAAAdAAAAABAp', 6),
('https://www.google.com/url?sa=i&url=https%3A%2F%2Fwww.facebook.com%2Fatletica1defevereiro%2F%3Flocale%3Dpt_BR&psig=AOvVaw0I9PyqfEVhBq9Glf_jF2wx&ust=1700671108233000&source=images&cd=vfe&opi=89978449&ved=0CBEQjRxqFwoTCOj37dvD1YIDFQAAAAAdAAAAABAw', 7);

INSERT INTO LOTES_PRODUTOS
(LOP_QUANTIDADE_PENDENTE, LOP_PRECO_PRODUTO, LOP_QUANTIDADE_DISPONIVEL, LOP_VENDAMINIMA, FK_PRODUTOS_PRO_ID)
VALUES 
(25, 15.50, 10, 5, 1),
(30, 11.00, 15, 5, 2),
(50, 12.25, 50, 20, 3),
(100, 2.50, 50, 25, 4),
(45, 5.00, 10, 25, 1);

INSERT INTO CARGOS_FUNCIONALIDADES
(FK_CARGOS_CAR_ID,FK_FUNCIONALIDADES_FUN_ID ,PRI_POSSUI)
VALUES 
(6,1,1),
(4,1,1),
(1,3,1),
(3,5,1),
(3,6,1),
(3,7,1);

INSERT INTO ATLETICAS
(ATL_NOME, ATL_LEMA, ATL_ATIVO, ATL_DESCRICAO, ATL_LOGO, ATL_INSTITUICAO_ENSINO, FK_ADMINISTRADORES_ADM_ID)
VALUES 
('Moverio', 'Coloque o Rio em movimento', 1, 'Localizada no Rio de Janeiro somos a primeira atletica internacional do estado', 'img.png', 'PUC-Rio', 1),
('Abs Lab', 'Tecnologia e saúde lada a lado', 1, 'Usando a ciencia ajudamos pessoas de todos os lugares a conseguir seu copo desejado', 'img.png', 'UNICID', 3),
('Ativiflex', 'Movimente seu corpo, seja flexivel!', 1, 'Com anos de experiencia na area educacional fisica, ajudamos as pessoas a se desenvolver fisicamente', 'img.png', 'UNIP', 2),
('Velovita', 'Colocando velocidade na sua vida', 1, 'Através de exercicios de cardio, ajudamos diversas pessoas com problemas de coração a manter a saúde em dia sem correr riscos', 'img.png', 'UNINOVE', 5),
('Atlética Growth', 'Alimentando seu crescimento', 1, 'Através de produtos liçenciados ajudamos e testamos novas formulas de suplementação para crescer musculos e melhorar desempenho', 'img.png', 'UNOPAR', 6);

INSERT INTO REQUISICOES_USUARIOS 
(REQ_NOME_USUARIO, REQ_SENHA, REQ_EMAIL, REQ_CONFIRMAR_SENHA, FK_ATLETICAS_ATL_ID) 
VALUES
('Guilherme', 'Guilherme@5','guiIfsp@gmail.com','Guilherme@5', 1),
('Joao', 'Joao@5','joaoIfsp@gmail.com','Joao@5', 1),
('Guilherme', 'Guilherme@5','guiIfsp@gmail.com','Guilherme@5', 1),
('Luana', 'Luana@5','luanaIfsp@gmail.com','luana@5', 1),
('Aline', 'Aline@5','alineifsp@gmail.com','Aline@5', 1);

INSERT INTO PATROCINIOS 
(PAT_IMAGEM, PAT_DATAFINAL, PAT_DATAINICIAL, PAT_VALOR, PAT_NOME, PAT_DESCRICAO, FK_ATLETICAS_ATL_ID, FK_PATROCINADORES_PTS_ID) 
VALUES
('imgPatrocinio50.jpg', '2030-05-12', '2023-05-12', 9000.88, 'Auxílio Mensal P/ Jogadores', 'O patrocinador dará 50 reais para cada jogador mensalmente.', 1, 1),
('imgLimite.jpg', '2027-03-07', '2023-03-27', 7500.78, 'Aumento Anual de 5% no Limite dos Técnicos', 'Os técnicos receberão 5% de aumento no limite.', 2, 2),
('imgViagem.jpg', '2024-11-04', '2023-11-04', 900, 'Viagem de Férias P/ Jogadores', 'Nas férias de dezembro os jogadores receberão uma viagem.', 3, 3),
('imgSorvetinho.jpg', '2025-06-01', '2023-06-01', 755.88, 'Sorvetes Pós Jogos', 'Após todos os jogos, os jogadores e técnicos poderão tomar sorvete.', 4, 4),
('imgFilmes.jpg', '2026-08-31', '2023-08-31', 75.88, 'Desconto em Filmes', 'Todos os jogadores e técnicos receberão um desconto de 70% em filmes', 5, 5);

INSERT INTO EVENTOS_ESPORTIVOS
(EVE_PRECO, EVE_DATAEVENTO, EVE_TIPOENTRADA, EVE_DESCRICAO, EVE_IMAGEMPROMOCIONAL, EVE_NOME, EVE_ENDERECOEVENTO, FK_ATLETICAS_ATL_ID)
VALUES
(1000, '2023-11-30', 1, 'Campeonato de futsal universitário, destinado às atléticas das instituições de ensino superior de São João da Boa Vista.', 'imagem.jpg', 'Taça São João de Futsal Universitário', 'Av. Brasília, 10', 3),
(2000, '2023-12-02', 1, 'Campeonato de vôlei universitário, destinado às atléticas das instituições de ensino superior de São João da Boa Vista.', 'imagem.jpg', 'Taça São João de Vôlei Universitário', 'Rua Peixoto de Castro, 25', 3),
(3000, '2023-12-16', 0, 'Campeonato de basquete universitário, destinado às atléticas das instituições de ensino superior de São João da Boa Vista.', 'imagem.jpg', 'Taça São João de Basquete Universitário', 'Av. São Paulo, 161', 3),
(4000, '2024-01-04', 1, 'Campeonato de atletismo universitário, destinado às atléticas das instituições de ensino superior de São João da Boa Vista.', 'imagem.jpg', 'Taça São João de Atletismo Universitário', 'Rua 15 de Novembro, 233', 3),
(5000, '2024-01-20', 0, 'Campeonato de tênis de mesa universitário, destinado às atléticas das instituições de ensino superior de São João da Boa Vista.', 'imagem.jpg', 'Taça São João de Tênis de Mesa Universitário', 'Rua Tiradentes, 398', 4),
(3500, '2024-01-22', 1, 'Campeonato de Handebol universitário, destinado às atléticas das instituições de ensino superior de São João da Boa Vista.', 'imagem.jpg', 'Taça São João de Handebol Universitário', 'Rua Campos Salles, 666', 4),
(4000, '2024-01-23', 0, 'Campeonato de Natação universitário, destinado às atléticas das instituições de ensino superior de São João da Boa Vista.', 'imagem.jpg', 'Taça São João de Natação Universitário', 'Rua 13 de maio, 333', 4),
(1500, '2024-01-24', 0, 'Campeonato de Xadrez universitário, destinado às atléticas das instituições de ensino superior de São João da Boa Vista.', 'imagem.jpg', 'Taça São João de Xadrez Universitário', 'Rua 9 de julho, 298', 4);

INSERT INTO EVENTOS_SOCIAIS
(EVE_PRECO, EVE_DATAEVENTO, EVE_TIPOENTRADA, EVE_DESCRICAO, EVE_IMAGEMPROMOCIONAL, EVE_NOME, EVE_ENDERECOEVENTO, FK_ATLETICAS_ATL_ID)
VALUES
(1000, '2023-11-23', 1, 'Evento beneficente, voltado para a arrecadação de alimentos para pessoas necessitadas.', 'imagem.jpg', 'São João Solidária', 'Rua dos Trabalhadores, 746', 2),
(2000, '2023-11-27', 0, 'Evento voltado para a divulgação dos projetos desenvolvidos pelos estudantes.', 'imagem.jpg', 'Semana de Tecnologia', 'Rua Santo Antônio, 23', 3),
(3000, '2023-12-10', 1, 'Festa de formatura dos formandos 2023.', 'imagem.jpg', 'Formatura 2023', 'Av. Ruy Barbosa, 94', 5),
(4000, '2023-12-19', 0, 'Evento beneficente, voltado para a arrecadação de vestimentas para pessoas necessitadas.', 'imagem.jpg', 'Arrecada São João', 'Av. Castro Alves, 419', 4),
(5000, '2024-01-07', 0, 'Festa para a recepção dos novos estudantes.', 'imagem.jpg', 'Calourada 2024', 'Rua Getúlio Vargas, 281', 1);

INSERT INTO PATROCINADORES_EVENTOS
(FK_EVENTOS_SOCIAIS_EVS_ID, FK_EVENTOS_ESPORTIVOS_EVE_ID, FK_PATROCINADORES_PTS_ID)
VALUES 
(1, NULL, 1),
(NULL, 3, 2),
(4, NULL, 4),
(5, 2, 3),
(NULL, 1, 3);

INSERT INTO CAMPEONATOS_MODALIDADES
(FK_MODALIDADES_ESPORTIVAS_MDE_ID, FK_EVENTOS_ESPORTIVOS_EVE_ID)
VALUES
(1, 4), /* Evento atletismo ID 4*/
(2, 2), /*Evento volei ID 2*/
(3, 2), /*Evento volei ID 2*/
(4, 3), /*Evento basquete ID 3*/
(5, 1), /* Evento futsal ID 1*/
(6, 1), /* Evento futsal ID 1*/
(7, 6), /* Evento handebol ID 6*/
(8, 7), /* Evento natação ID 7*/
(9, 8), /* Evento Xadrez ID 8*/
(10, 5); /*Evento Tenis de Mesa ID 5*/

INSERT INTO PROVAS 
(PRO_DIA, PRO_HORARIO, PRO_LOCAL, FK_CAMPEONATOS_MODALIDADES_CMM_ID)
VALUES 
('2023-12-05', '2023-12-05 15:00:00', 'IFSP - QUADRA',  1),
('2023-12-13' , '2023-12-13 14:00:00' , 'IFSP - QUADRA', 2),
('2023-12-20' , '2023-12-20 10:00:00' , 'CIC - QUADRA 1', 3),
('2024-01-05' , '2024-01-05 14:00:00', 'IFSP - QUADRA', 4),
('2024-01-06' , '2024-01-06 16:00:00' , 'CIC - QUADRA 2', 5),
('2024-01-07' , '2024-01-07 19:00:00' , 'CIC - QUADRA 1', 6),
('2024-01-09' , '2024-01-09 17:00:00' , 'IFSP - QUADRA', 7),
('2024-01-10' , '2024-01-10 18:00:00' , 'CIC - QUADRA 1', 8),
('2024-01-11', '2024-01-11 15:00:00', 'IFSP - QUADRA', 9),
('2024-01-11', '2024-01-11 17:00:00', 'CIC - QUADRA', 10);

INSERT INTO JOGOS 
(JOG_HORARIO, JOG_EQPB_RESULTADO_FINAL, JOG_EQPA_RESULTADO_FINAL, JOG_DIA, JOG_LOCAL, FK_CAMPEONATOS_MODALIDADES_CMM_ID)
VALUES
('2023-12-01 08:00:00', 11, 14, '2023-12-01', 'IFSP - QUADRA', '1'),
('2023-12-01 10:00:00', '3', '1', '2023-12-01', 'IFSP - QUADRA', '2'),
('2023-12-02 09:00:00', '3', '2', '2023-12-02', 'CIC - QUADRA 1', '3'),
('2023-12-03 11:00:00', '67', '56', '2023-12-03', 'CIC - QUADRA 1', '4'),
('2023-12-03 15:00:00', '0', '1', '2023-12-03', 'CIC - QUADRA 2', '5'),
('2023-12-03 19:00:00', '4', '0', '2023-12-03', 'IFSP - QUADRA', '6'),
('2023-12-04 08:00:00', '6', '2', '2023-12-04', 'CIC - QUADRA 1', '7'),
('2023-12-04 10:00:00', 40 , 30, '2023-12-04', 'CIC - QUADRA 2', '8'),
('2023-12-04 13:00:00', 1, 0, '2023-12-04', 'CIC - QUADRA 1', '9'),
('2023-12-05 16:00:00', 3, 2, '2023-12-05', 'IFSP - QUADRA', '10');

INSERT INTO ENTRADAS
(ENT_DESCRICAO, ENT_DATA, ENT_VALOR, ENT_NOME, FK_ATLETICAS_ATL_ID)
VALUES
('FESTA!', '2023-03-28', 301.00, 'festa', 1),
('FESTA!', '2022-03-24', 3022.00, 'festa', 2),
('FESTA!', '2023-03-21', 321.00, 'festa', 3),
('FESTA!', '2023-03-22', 401.00, 'festa', 4),
('FESTA!', '2023-03-19', 5601.00, 'festa', 5);

INSERT INTO DESPESAS
(DEP_NOME, DEP_DESCRICAO, DEP_ID_ENTIDADE, DEP_DATA, DEP_VALOR, DEP_TIPO, DEP_FORMA_PAGAMENTO, FK_ATLETICAS_ATL_ID )
VALUES
('chácara', 'aluguel', 1, '2023-03-10', 255.50, 'EVENTO', 'DEBITO', 1),
('chácara', 'aluguel', 1, '2023-03-09', 2398.50, 'EVENTO', 'DEBITO', 2),
('chácara', 'aluguel', 1, '2023-03-09', 3336.50, 'EVENTO', 'DEBITO', 3),
('chácara', 'aluguel', 1, '2023-03-10', 2559.50, 'EVENTO', 'DEBITO', 4),
('chácara', 'aluguel', 1, '2023-03-10', 2575.50, 'EVENTO', 'DEBITO', 5);

INSERT INTO INGRESSOS
(ING_NUMEROINGRESSO,FK_EVENTOS_SOCIAIS_EVS_ID,FK_EVENTOS_ESPORTIVOS_EVE_ID)
VALUES
(1,1,1),
(2,1,1),
(3,1,1),
(1,2,1),
(1,1,2),
(2,1,2),
(4,1,1),
(1,3,5),
(2,3,5),
(3,1,2);

INSERT INTO PLANOS_ATLETICA
(FK_PLANOS_PLA_ID, FK_ATLETICAS_ATL_ID)
VALUES 
(1,1), 
(2,1), 
(3,1), 
(4,1), 
(5,1), 
(3,2), 
(5,4);

INSERT INTO LOTES_INGRESSOS
(LOI_QUANTIDADE_PENDENTE, LOI_QUANTIDADE_DISPONIVEL, LOI_VALOR, LOI_VENDAMINIMA, FK_INGRESSOS_ING_ID)
VALUES 
(300, 14, 10.00, 10,1),
(250, 100, 20.00, 20,2),
(200, 50, 25.00, 10,3),
(150, 100, 30.00, 20,4),
(100, 50, 35.00, 10,5),
(80, 100, 55.00, 20,6),
(70, 50, 65.00, 10, 7),
(50, 100, 75.00, 20, 8),
(20, 50, 80.00, 10, 9),
(10, 100, 85.00, 20, 10);

INSERT INTO USUARIOS
(USU_SENHA, USU_INSTITUICAO_ENSINO, USU_ATIVO, USU_FOTO ,USU_NOME, USU_DESCRICAO, USU_EMAIL, FK_ATLETICAS_ATL_ID, FK_EQUIPES_EQP_ID)
VALUES 
('SENHA1','IFSP', 1,'FOTO','Ramin','cara do lol','ramin@gmail.com',1,null),
('SENHA2','IFSP', 1,'FOTO','Bianca','egirl','bianca@gmail.com',2,null),
('SENHA3','IFSP', 1,'FOTO','Maju','loira odonto','maju@gmail.com',3,null),
('SENHA4','IFSP', 1,'FOTO','Victor','calvo','victor@gmail.com',4,null),
('SENHA5','IFSP', 1,'FOTO','Samuel','nadador','samuel@gmail.com',5,null);

INSERT INTO POSTAGENS_GERAL
(PST_DESCRICAO ,PST_CURTIDAS ,PST_DATA ,PST_IMAGEM, FK_USUARIOS_USU_ID) 
VALUES 
('SAVE THE DATE', 555, '2023-04-04','POST1',2),
('VENDA DE INGRESSOS', 453, '2023-05-04','POST2',2),
('OPEN BAR', 656, '2023-06-04','POST3',3),
('ATRACAO', 345, '2023-07-04','POST4',3),
('ATENCAO', 322, '2023-08-04','POST5',3);

INSERT INTO USUARIOS_CARGOS
(FK_CARGOS_CAR_ID, FK_USUARIOS_USU_ID) 
VALUES 
(4,3),
(2,2),
(6,1),
(3,5),
(1,4);
 
INSERT INTO COMENTARIOS
(CMT_TIPO_POSTAGEM, CMT_FK_ID_POSTAGEM, CMT_CURTIDAS, CMT_TEXTO, FK_USUARIOS_USU_ID)
VALUES
(1, null, '100', 'a', 2),
(1, null, '1123', 'B', 3),
(2, null, '451', 'c', 3),
(2, null, '0', 'd', 4),
(2, null, '98', 'e', 5);

INSERT INTO PAGAMENTOS
(PAG_VALOR_PAGO, PAG_DATA, PAG_CONDICAO, FK_USUARIOS_USU_ID) 
VALUES
('300.00', '2023-11-18', 'PENDENTE',1),
('1500.00', '2023-11-22', 'PAGO',2),
('20.00', '2021-07-21', 'CANCELADO',2),
('7.50', '2019-04-01', 'PAGO',1),
('700.00', '2022-12-08', 'PENDENTE',3);

INSERT INTO USUARIOS_CHAMADOS
(FK_USUARIOS_USU_ID, FK_CHAMADOS_CHA_ID) 
VALUES 
(3,1),
(3,2),
(3,3),
(4,4),
(5,5),
(5,6);
INSERT INTO DENUNCIAS
(DNC_DESCRICAO, DNC_TIPO_DENUNCIA, DNC_FK_ID_COMENTARIO_POSTAGEM, DNC_MOTIVO, DNC_DATA, FK_USUARIOS_USU_ID) 
VALUES
("Denuncia",1,2,1,curdate(),2),
("Comentario Improprio",1,2,1,curdate(),3),
("Banimento",2,2,1,curdate(),3),
("Denunciado",2,2,1,curdate(),4),
("Paia",3,2,1,curdate(),5);

INSERT INTO VOTACOES
(VOT_PRAZO, FK_CHAMADOS_CHA_ID) 
VALUES 
('2024-01-01',1),
('2024-01-02',2), 
('2024-01-03',1), 
('2024-01-04',2), 
('2024-01-05',4);

INSERT INTO ARBITRO_PROVAS
(ABP_FUNCAO, FK_PROVAS_PRO_ID, FK_AUTORIDADES_ATD_ID)
VALUES
('1', '1', '10'),
('1', '2', '9'),
('1', '3', '5'),
('1', '4', '3'),
('1', '5', '7'),
('1', '6', '1'),
('1', '7', '2'),
('1', '8', '4'),
('1', '9', '6'),
('1', '10', '8');

INSERT INTO ARBITRO_JOGOS
(ABJ_FUNCAO, FK_JOGOS_JOG_ID, FK_AUTORIDADES_ATD_ID)
VALUES
(1, 1, 1),
(1, 2, 2),
(1, 3, 3),
(1, 4, 4),
(1, 5, 5),
(1, 6, 6),
(1, 7, 7),
(1, 8, 8),
(1, 9, 9),
(1, 10, 10);

INSERT INTO EQUIPES_ATLETAS
(FK_USUARIOS_USU_ID)
VALUES
(1),
(2),
(3),
(4),
(5);

INSERT INTO EQUIPES
(EQP_TREINADOR,FK_ATLETICAS_ATL_ID,FK_MODALIDADES_ESPORTIVAS_MDE_ID,FK_EQUIPES_ATLETAS_ETL_ID)
VALUES
('guilherme',1,5,1),
('guilherme',1,5,2),
('guilherme',1,5,3),
('guilherme',1,5,4),
('guilherme',1,5,5);

INSERT INTO EQUIPES_JOGOS
(FK_JOGOS_JOG_ID, FK_EQUIPES_EQP_ID)
VALUES
(1,1),
(1,2),
(1,3),
(1,4),
(1,5);

INSERT INTO USUARIOS_PLANOS 
(FK_PLANOS_PLA_ID, FK_USUARIOS_USU_ID) 
VALUES 
(6, 1), 
(5, 2), 
(1, 3), 
(3, 4), 
(2, 5);

INSERT INTO 
COMPRAS_INGRESSOS
(CPI_DATA_COMPRA, CPI_STATUS, FK_USUARIOS_USU_ID, FK_LOTES_INGRESSOS_LOI_ID)
VALUES
(01052023,'FINALIZADO',1,1),
(01052023,'PENDENTE',2,1),
(07052023,'CANCELADO',3,1),
(08052023,'FINALIZADO',4,1),
(23092023,'CANCELADO',5,2),
(23092023,'CANCELADO',2,2),
(31092023,'FINALIZADO',2,5),
(31092023,'CANCELADO',3,5),
(31092023,'FINALIZADO',4,10),
(01102023,'PENDENTE',5,10);

INSERT INTO COMPRAS 
(CMP_VALOR_DESCONTO, CMP_STATUS, CMP_DATA, CMP_DESCONTO, FK_USUARIOS_USU_ID) 
VALUES 
(90, 'FINALIZADO', '2023-11-01', 10.0, 1), 
(80, 'FINALIZADO', '2023-11-02', 20.0, 2), 
(70, 'FINALIZADO', '2023-11-03', 30.0, 2), 
(60, 'PENDENTE', '2023-11-04', 40.0, 3), 
(50, 'CANCELADO', '2023-11-05', 50.0, 5);

INSERT INTO ITEMS_COMPRAS
(ITS_QUANTIDADE, FK_COMPRAS_CMP_ID, FK_LOTES_PRODUTOS_LOP_ID)
VALUES
(15, 1, 1),
(20, 2, 1),
(20, 3, 3),
(50, 4, 4),
(15, 5, 5);

INSERT INTO VOTACAOES_USUARIOS
(FK_USUARIOS_USU_ID, FK_VOTACOES_VOT_ID, VTS_DATA, VTS_STATUS)
VALUES
(1, 1, curdate(), 1),
(2, 1, '2022-12-07', 1), 
(3, 1, '2004-06-13', 0),
(4, 1, '2019-05-31', 1),
(5, 1, '2020-08-23', 0),
(1, 2, '2022-12-08', 1),
(2, 2, '2019-08-28', 0),
(3, 3, '2019-05-07', 0),
(4, 3, '2022-04-20', 0);





