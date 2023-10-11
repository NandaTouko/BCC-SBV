USE INSERT_EXCEL_2;

SELECT * FROM CIDADES;

-- ATIVIDADE - FUNÇÕES DE AGREGAÇÃO

-- 1) Liste a população da maior cidade.
SELECT MAX(POPULACAO_TOTAL) FROM CIDADES;

-- Para conseguir trazer o nome da cidade usando o MAX(), não dá para fazer sem ser com subselect
SELECT NOME_CIDADE, ESTADO, POPULACAO_TOTAL FROM CIDADES
WHERE POPULACAO_TOTAL = (
	SELECT MAX(POPULACAO_TOTAL) FROM CIDADES
);

-- 2) Liste a população da menor cidade.
SELECT MIN(POPULACAO_TOTAL) FROM CIDADES;

-- 3) Liste a sigla, estado e média da população da região sudeste em ordem da média
SELECT ESTADO, AVG(POPULACAO_TOTAL) AS MEDIA_POPULACAO FROM CIDADES
WHERE ESTADO IN('SP', 'MG', 'ES', 'RJ')
GROUP BY ESTADO
ORDER BY MEDIA_POPULACAO;

-- 4) Liste a quantidade de cidades cadastradas.
SELECT COUNT(*) AS QTD_CIDADES FROM CIDADES;

-- 5) Liste a quantidade de cidades no Estado de SP.
SELECT ESTADO, COUNT(*) AS QTD_CIDADES FROM CIDADES
WHERE ESTADO = 'SP';

-- 6) Liste a quantidade de cidades que tenham a população menor que 10000 habitantes
SELECT COUNT(*) FROM CIDADES
WHERE POPULACAO_TOTAL < 10000;

-- 7) Calcule a média aritmética da população de todas as cidades.
SELECT AVG(POPULACAO_TOTAL) FROM CIDADES;

-- 8) Calcule a soma das populações da região Sul.
SELECT ESTADO, SUM(POPULACAO_TOTAL) FROM CIDADES
WHERE ESTADO IN('PR', 'RS', 'SC')
GROUP BY ESTADO;

-- 9) Liste o custo total dos eventos nos últimos 3 anos considerando apenas os anos cujo custo total 
-- foi superior a R$5.000,00. Ordene por ano.
USE LBAEVENTOS;

INSERT INTO FornecedoresEventosProdutos(CODFORNECEDOREVENTOPRODUTO, FKCNPJ, FKCODPRODUTOSERVICO, FKCODEVENTO, CUSTO)
VALUES (1, '04.091.915/0001-00', 4, 2, 5200), (2, '04.091.915/0001-00', 1, 1, 1000), (3, '50.582.170/0004-42', 5, 2, 7900);

SELECT YEAR(E.DATAEVENTO) AS ANO,
SUM(FEP.CUSTO) AS TOTAL_CUSTO
FROM Evento AS E
INNER JOIN FornecedoresEventosProdutos AS FEP ON FEP.FKCODEVENTO = E.CODEVENTO
WHERE YEAR(E.DATAEVENTO) IN(2023, 2022, 2021)
GROUP BY YEAR(E.DATAEVENTO)
HAVING SUM(FEP.CUSTO) > 5000
ORDER BY YEAR(E.DATAEVENTO);