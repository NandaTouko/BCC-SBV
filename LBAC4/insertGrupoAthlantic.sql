USE ATHLANTIC;
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

INSERT INTO REQUISICOES_ATLETICAS (REQ_NOME_USUARIO, REQ_INSTITUICAO_ENSINO, REQ_SENHA, REQ_EMAIL, REQ_CONFIRMAR_SENHA, REQ_NOME_ATLETICA, REQ_LOGO_ATLETICA, REQ_DESCRICAO_ATLETICA, FK_ADMINISTRADORES_ADM_ID) VALUES
("Rafaela Oliveira", "Instituto Educacional Progresso", "rafa123", "rafaoliveira@gmail.com", "rafa123", "Falcões Velozes", "Falcão", 
"Solicitação de licença para participar de um curso de aprimoramento profissional por uma semana.", 1),
("Lucas Santos", "Universidade Nova Horizonte", "lucas0505", "santoslucas@gmail.com", "lucas0505", "Tigres Alados", "Tigres", 
"Pedido de reembolso de despesas relacionadas a uma viagem de trabalho.", 2),
("Carolina Silva", "Escola Técnica Avançada", "carol2000", "carolinasilva@gmail.com", "carol2000", "Leões da Vitória", "Leão",
"Equipamentos de escritório para otimizar o ambiente de trabalho.", 3),
("André Pereira", "Centro de Ensino Harmonia", "senha123", "andrepereira1@gmail.com", "senha123", "Panteras Douradas", "Pantera",
"Solicitação de aumento salarial devido ao desempenho excepcional no último trimestre.", 4),
("Mariana Costa", "Faculdade Excelência Cultural", "mari12321", "costamariana@gmail.com", "mari12321", "Águias Radiantes", "Águia",
"Pedido de flexibilidade no horário de trabalho para conciliar responsabilidades familiares.", 5),
("Tiago Almeida", "Colégio Renovação Educativa", "tiago0101", "tiagoalmei@gmail.com", "tiago01010", "Lobos Esportivos", "Lobo",
"Requisição de treinamento específico para aprimorar habilidades técnicas.", 6),
("Isabela Fernandes", "Academia de Saberes Integrados", "isa2000", "isafernandes@gmail.com", "isa2000", "Golfinhos Atléticos", "Golfinho",
"Pedido de licença não remunerada para um projeto voluntário de curto prazo.", 7);

INSERT INTO ATLETICAS(ATL_NOME, ATL_LEMA, ATL_ATIVO, ATL_DESCRICAO, ATL_LOGO, ATL_INSTITUICAO_ENSINO, FK_ADMINISTRADORES_ADM_ID)
VALUES ('Moverio', 'Coloque o Rio em movimento', 1, 'Localizada no Rio de Janeiro somos a primeira atletica internacional do estado', 'img.png', 'PUC-Rio', 1),
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

INSERT INTO PATROCINIOS (
PAT_IMAGEM,
PAT_DATAFINAL,
PAT_DATAINICIAL,
PAT_VALOR,
PAT_NOME,
PAT_DESCRICAO,
FK_ATLETICAS_ATL_ID,
FK_PATROCINADORES_PTS_ID
) VALUES
('imgPatrocinio50.jpg', '2030-05-12', '2023-05-12', 9000.88, 'Auxílio Mensal P/ Jogadores', 'O patrocinador dará 50 reais para cada jogador mensalmente.', 1, 1),
('imgLimite.jpg', '2027-03-07', '2023-03-27', 7500.78, 'Aumento Anual de 5% no Limite dos Técnicos', 'Os técnicos receberão 5% de aumento no limite.', 2, 2),
('imgViagem.jpg', '2024-11-04', '2023-11-04', 900, 'Viagem de Férias P/ Jogadores', 'Nas férias de dezembro os jogadores receberão uma viagem.', 3, 3),
('imgSorvetinho.jpg', '2025-06-01', '2023-06-01', 755.88, 'Sorvetes Pós Jogos', 'Após todos os jogos, os jogadores e técnicos poderão tomar sorvete.', 4, 4),
('imgFilmes.jpg', '2026-08-31', '2023-08-31', 75.88, 'Desconto em Filmes', 'Todos os jogadores e técnicos receberão um desconto de 70% em filmes', 5, 5);

INSERT INTO EVENTOS_ESPORTIVOS(EVE_PRECO, EVE_DATAEVENTO, EVE_TIPOENTRADA, EVE_DESCRICAO, EVE_IMAGEMPROMOCIONAL, EVE_NOME, EVE_ENDERECOEVENTO, FK_ATLETICAS_ATL_ID)
VALUES(1000, '2023-11-30', 1, 'Campeonato de futsal universitário, destinado às atléticas das instituições de ensino superior de São João da Boa Vista.', 'imagem.jpg', 'Taça São João de Futsal Universitário', 'Av. Brasília, 10', 1),
(2000, '2023-12-02', 1, 'Campeonato de vôlei universitário, destinado às atléticas das instituições de ensino superior de São João da Boa Vista.', 'imagem.jpg', 'Taça São João de Vôlei Universitário', 'Rua Peixoto de Castro, 25', 1),
(3000, '2023-12-16', 0, 'Campeonato de basquete universitário, destinado às atléticas das instituições de ensino superior de São João da Boa Vista.', 'imagem.jpg', 'Taça São João de Basquete Universitário', 'Av. São Pulo, 161', 1),
(4000, '2024-01-04', 1, 'Campeonato de atletismo universitário, destinado às atléticas das instituições de ensino superior de São João da Boa Vista.', 'imagem.jpg', 'Taça São João de Atletismo Universitário', 'Rua 15 de Novembro, 233', 1),
(5000, '2024-01-20', 0, 'Campeonato de tênis de mesa universitário, destinado às atléticas das instituições de ensino superior de São João da Boa Vista.', 'imagem.jpg', 'Taça São João de Tênis de Mesa Universitário', 'Rua Tiradentes, 398', 1);

INSERT INTO EVENTOS_SOCIAIS(EVE_PRECO, EVE_DATAEVENTO, EVE_TIPOENTRADA, EVE_DESCRICAO, EVE_IMAGEMPROMOCIONAL, EVE_NOME, EVE_ENDERECOEVENTO, FK_ATLETICAS_ATL_ID)
VALUES(1000, '2023-11-23', 1, 'Evento beneficente, voltado para a arrecadação de alimentos para pessoas necessitadas.', 'imagem.jpg', 'São João Solidária', 'Rua dos Trabalhadores, 746', 1),
(2000, '2023-11-27', 0, 'Evento voltado para a divulgação dos projetos desenvolvidos pelos estudantes.', 'imagem.jpg', 'Semana de Tecnologia', 'Rua Santo Antônio, 23', 1),
(3000, '2023-12-10', 1, 'Festa de formatura dos formandos 2023.', 'imagem.jpg', 'Formatura 2023', 'Av. Ruy Barbosa, 94', 1),
(4000, '2023-12-19', 0, 'Evento beneficente, voltado para a arrecadação de vestimentas para pessoas necessitadas.', 'imagem.jpg', 'Arrecada São João', 'Av. Castro Alves, 419', 1),
(5000, '2024-01-07', 0, 'Festa para a recepção dos novos estudantes.', 'imagem.jpg', 'Calourada 2024', 'Rua Getúlio Vargas, 281', 1);

INSERT INTO PATROCINADORES_EVENTOS(FK_EVENTOS_SOCIAIS_EVS_ID, FK_EVENTOS_ESPORTIVOS_EVE_ID, FK_PATROCINADORES_PTS_ID)
VALUES (1, NULL, 1),
(NULL, 3, 2),
(4, NULL, 4),
(5, 2, 3),
(NULL, 1, 3);
