DROP DATABASE IF EXISTS	LBAEVENTOS;
CREATE DATABASE IF NOT EXISTS LBAEVENTOS;
USE LBAEVENTOS;

CREATE TABLE IF NOT EXISTS Setor (
CodSetor Integer auto_increment not null PRIMARY KEY,
NomeSetor Varchar(30) not null unique
);

CREATE TABLE IF NOT EXISTS Atuacao (
CodAtuacao Integer auto_increment not null PRIMARY KEY,
NomeAtuacao Varchar(30),
fkCodSetor Integer not null,
FOREIGN KEY(fkCodSetor) REFERENCES Setor (CodSetor)
);

CREATE TABLE IF NOT EXISTS Estado (
SiglaUF Varchar(2) not null PRIMARY KEY,
NomeUF Varchar(30) not null unique
);

CREATE TABLE IF NOT EXISTS Cidade (
CodCidade Integer auto_increment not null PRIMARY KEY,
NomeCidade Varchar(50) not null,
Populacao Integer,
fkSiglaUF Varchar(2) not null,
FOREIGN KEY(fkSiglaUF) REFERENCES Estado (SiglaUF)
);

CREATE TABLE IF NOT EXISTS Departamento (
CodDepartamento Integer auto_increment not null PRIMARY KEY,
NomeDepartamento Varchar(30) not null unique
);

CREATE TABLE IF NOT EXISTS Cargo (
CodCargo Integer auto_increment not null PRIMARY KEY,
NomeCargo Varchar(30) not null unique
);

CREATE TABLE IF NOT EXISTS Entidade (
RazaoSocial Varchar(100) not null,
CNPJ_CPF Varchar(20) not null PRIMARY KEY,
Site Varchar(80),
Email Varchar(80),
CEP Varchar(10),
Logradouro Varchar(80),
Numero Varchar(10),
Complemento Varchar(50),
Bairro Varchar(50),
NomeFantasia Varchar(60),
fkCodAtuacao Integer not null,
fkCodCidade Integer not null,
FOREIGN KEY(fkCodAtuacao) REFERENCES Atuacao (CodAtuacao),
FOREIGN KEY(fkCodCidade) REFERENCES Cidade (CodCidade)

);

CREATE TABLE IF NOT EXISTS Colaborador (
DataNascimento Date,
NomeContato Varchar(80) not null,
CodContato Integer not null auto_increment PRIMARY KEY,
fkCodDepartamento Integer not null,
fkCNPJ_CPF Varchar(20) not null,
fkCodCargo Integer not null,
FOREIGN KEY(fkCNPJ_CPF) REFERENCES Entidade (CNPJ_CPF),
FOREIGN KEY(fkCodCargo) REFERENCES Cargo (CodCargo),
FOREIGN KEY(fkCodDepartamento) REFERENCES Departamento (CodDepartamento)
);

CREATE TABLE IF NOT EXISTS Interesse (
CodInteresse Integer auto_increment not null PRIMARY KEY,
NomeInteresse Varchar(20) not null unique
);



CREATE TABLE IF NOT EXISTS InteressesContato (
fkCodContato Integer not null,
fkCodInteresse Integer not null,
CodInteresseContato Integer auto_increment not null PRIMARY KEY,
FOREIGN KEY(fkCodContato) REFERENCES Colaborador (CodContato),
FOREIGN KEY(fkCodInteresse) REFERENCES Interesse (CodInteresse)
);

CREATE TABLE IF NOT EXISTS Fornecedor (
Contato Varchar(80) not null,
NomeFantasia Varchar(60),
CEP Varchar(10),
Bairro Varchar(50),
Complemento Varchar(50),
Numero Varchar(10),
Logradouro Varchar(80),
CNPJ Varchar(20) not null PRIMARY KEY,
RazaoSocial Varchar(100) not null,
fkCodCidade Integer not null,
FOREIGN KEY(fkCodCidade) REFERENCES Cidade (CodCidade)
);


CREATE TABLE IF NOT EXISTS ProdutoServico (
CodProdutoServico Integer not null auto_increment PRIMARY KEY,
DescricaoProdutoServico Varchar(255),
NomeProdutoServico Varchar(30) not null unique
);


CREATE TABLE IF NOT EXISTS Classificacao (
CodClassificacao Integer auto_increment not null PRIMARY KEY,
NomeClassificacao Varchar(20) not null unique
);



CREATE TABLE IF NOT EXISTS ClassificacaoContato (
fkCodContato Integer not null,
fkCodClassificacao Integer not null,
CodClassificacaoContato Integer auto_increment not null PRIMARY KEY,
FOREIGN KEY(fkCodContato) REFERENCES Colaborador (CodContato),
FOREIGN KEY(fkCodClassificacao) REFERENCES Classificacao (CodClassificacao)
);

CREATE TABLE IF NOT EXISTS RedesSociaisEntidade (
Usuario Varchar(50) not null,
fkCNPJ_CPF Varchar(20) not null,
CodRedeSocialEntidade Integer auto_increment not null PRIMARY KEY,
FOREIGN KEY(fkCNPJ_CPF) REFERENCES Entidade (CNPJ_CPF)
);

CREATE TABLE IF NOT EXISTS RedesSociaisColaborador (
Usuario Varchar(50) not null,
fkCodContato Integer not null,
CodRedeSocialContato Integer(4) auto_increment not null PRIMARY KEY,
FOREIGN KEY(fkCodContato) REFERENCES Colaborador (CodContato)
);

CREATE TABLE IF NOT EXISTS LocalEvento (
CodLocal Integer auto_increment not null PRIMARY KEY,
Logradouro Varchar(80),
Numero Varchar(10),
Complemento Varchar(50),
Bairro Varchar(50),
CEP Varchar(10),
Lotacao int,
Observacao Varchar(255),
NomeLocal Varchar(80) not null,
fkCodCidade Integer not null,
FOREIGN KEY(fkCodCidade) REFERENCES Cidade (CodCidade)
);


CREATE TABLE IF NOT EXISTS Evento (
DataEvento Date not null,
CodEvento Integer auto_increment not null PRIMARY KEY,
NomeEvento Varchar(80) not null,
Horario Time not null,
fkCodLocal Integer not null,
foreign key(fkCodLocal) references LocalEvento(CodLocal)
);



CREATE TABLE IF NOT EXISTS EventosColaborador (
fkCodContato Integer not null,
fkCodEvento Integer not null,
CodEventoColaborador Integer auto_increment not null PRIMARY KEY,
FOREIGN KEY(fkCodContato) REFERENCES Colaborador (CodContato),
FOREIGN KEY(fkCodEvento) REFERENCES Evento (CodEvento)
);

CREATE TABLE IF NOT EXISTS PublicoConvidado (
fkCodEvento Integer not null,
fkCodClassificacao Integer not null,
CodPublicoConvidado Integer auto_increment not null PRIMARY KEY,
FOREIGN KEY(fkCodEvento) REFERENCES Evento (CodEvento),
FOREIGN KEY(fkCodClassificacao) REFERENCES Classificacao (CodClassificacao)
);

CREATE TABLE IF NOT EXISTS FornecedoresEventosProdutos (
Contrato Varchar(255),
Custo Decimal(10,2) not null,
fkCodEvento Integer not null,
fkCodProdutoServico Integer not null,
fkCNPJ Varchar(20) not null,
CodFornecedorEventoProduto Integer auto_increment not null PRIMARY KEY,
FOREIGN KEY(fkCodEvento) REFERENCES Evento (CodEvento),
FOREIGN KEY(fkCodProdutoServico) REFERENCES ProdutoServico (CodProdutoServico),
FOREIGN KEY(fkCNPJ) REFERENCES Fornecedor (CNPJ)
);

CREATE TABLE IF NOT EXISTS TelefonesFornecedor (
Telefone Varchar(10) not null,
DDD Integer not null,
fkCNPJ Varchar(20) not null,
CodTelefoneFornecedor Integer auto_increment not null PRIMARY KEY,
FOREIGN KEY(fkCNPJ) REFERENCES Fornecedor (CNPJ)
);

CREATE TABLE IF NOT EXISTS TelefonesEntidade (
Telefone Varchar(10) not null,
DDD Integer not null,
fkCNPJ_CPF Varchar(20) not null,
CodTelefoneEntidade Integer auto_increment not null PRIMARY KEY,
FOREIGN KEY(fkCNPJ_CPF) REFERENCES Entidade (CNPJ_CPF)
);


