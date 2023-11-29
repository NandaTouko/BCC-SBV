USE ATHLANTIC;

-- Selecione as equipes participantes dos jogos e suas respectivas modalidades esportivas. 
-- Liste Liste nome do usuário, e-mail, instituição, nome da atlética, tipo de esporte e modalidade.
-- Ordene por atlética, modalidade e participante
SELECT *
FROM JOGOS J
INNER JOIN EQUIPE_JOGOS EJ ON 
