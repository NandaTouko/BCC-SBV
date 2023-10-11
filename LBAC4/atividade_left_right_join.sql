USE LBAEVENTOS;

-- ATIVIDADE: RIGHT E LEFT JOIN

-- 1) Selecione apenas os nomes dos setores que não possuem área de atuação em ordem de setor.
SELECT S.NOMESETOR FROM Setor AS S
LEFT JOIN Atuacao AS A ON S.CODSETOR = A.FKCODSETOR
WHERE A.FKCODSETOR IS NULL
ORDER BY S.NOMESETOR;

-- 2) Selecione todos eventos (nome, data, horário e nome do local) e colaboradores envolvidos, 
-- mesmo para eventos que não tiveram colaboradores. Ordene pelo evento mais antigo, nome do evento 
-- e nome do colaborador.
SELECT E.NOMEEVENTO,
E.DATAEVENTO,
E.HORARIO,
LE.NOMELOCAL,
C.NOMECONTATO 
FROM Evento AS E
INNER JOIN LocalEvento AS LE ON E.FKCODLOCAL = LE.CODLOCAL
LEFT JOIN EventosColaborador as EC ON E.CODEVENTO = EC.FKCODEVENTO
LEFT JOIN Colaborador AS C ON C.CODCONTATO = EC.FKCODCONTATO
ORDER BY E.DATAEVENTO, E.NOMEEVENTO, C.NOMECONTATO;

-- 3) Selecione nome do colaborador, departamento, cargo, interesses e redes sociais de todos os colaboradores 
-- cadastrados, mesmo que não possuam as informações que não são de preenchimento obrigatório.
SELECT C.NOMECONTATO,
D.NOMEDEPARTAMENTO,
CA.NOMECARGO,
I.NOMEINTERESSE,
RSC.USUARIO 
FROM Colaborador AS C
INNER JOIN Departamento AS D ON C.FKCODDEPARTAMENTO = D.CODDEPARTAMENTO
INNER JOIN Cargo AS CA ON C.FKCODCARGO = CA.CODCARGO
LEFT JOIN InteressesContato AS IC ON C.CODCONTATO = IC.FKCODCONTATO
LEFT JOIN Interesse AS I ON IC.FKCODINTERESSE = I.CODINTERESSE
LEFT JOIN RedesSociaisColaborador AS RSC ON C.CODCONTATO = RSC.FKCODCONTATO;

-- 4) Selecione, em uma única listagem, as entidades e fornecedores. 
-- Crie uma coluna para diferenciar os registros como "Entidades" e "Fornecedores". Ordene alfabeticamente.
SELECT 'ENTIDADE' AS TIPO, RAZAOSOCIAL FROM Entidade
UNION
SELECT 'FORNECEDORES' AS TIPO, RAZAOSOCIAL FROM Fornecedor
ORDER BY RAZAOSOCIAL;