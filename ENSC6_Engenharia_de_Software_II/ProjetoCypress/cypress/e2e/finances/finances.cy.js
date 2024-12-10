/// <reference types="cypress" />

describe("Transações", () => {
	// Antes de cada teste
	beforeEach(() => {
		// Definindo a página a ser testada
		cy.visit('https://dev-finance.netlify.app/');
	});

	it('Cadastrar Nova Transação - Entrada', () => {
		// Selecionando a opção para se Cadastrar Nova Transação - Entrada
		cy.contains('Nova Transação').click();

		// Inserindo o conteúdo da descrição
		cy.get('#description').type('Manutenção do Site do IFSP-SBV');

		// Inserindo o conteúdo do valor
		cy.get('#amount').type('500');

		// Inserindo o conteúdo da data -> Máscara obrigatória: yyyy-mm-dd
		cy.get('#date').type('2023-10-20');

		// Selecionando a opção para Salvar a Transação
		cy.contains('button', 'Salvar').click();

		// Assertion para verificar se tivemos sucesso ou falha
		cy.get('tbody tr td.description').should('have.text', 'Manutenção do Site do IFSP-SBV');
	});

	it('Cadastrar Nova Transação - Saída', () => {
		// Selecionando a opção para se Cadastrar Nova Transação - Saída
		cy.contains('Nova Transação').click();

		// Inserindo o conteúdo da descrição
		cy.get('#description').type('Pagamento da Infraestrutura');

		// Inserindo o conteúdo do valor
		cy.get('#amount').type('-270');

		// Inserindo o conteúdo da data -> Máscara obrigatória: yyyy-mm-dd
		cy.get('#date').type('2023-10-21');

		// Selecionando a opção para Salvar a Transação
		cy.contains('button', 'Salvar').click();

		// Assertion para verificar se tivemos sucesso ou falha
		cy.get('tbody tr td.description').should('have.text', 'Pagamento da Infraestrutura');
	});

	it('Cadastrar Nova Transação - Saída Refatorada - Function', () => {
		// Preenchendo o formulário de transação utilizando a function definida
		criarTransacao('Pagamento do Curso de Frontend', -50, '2023-10-22');

		// Assertion para verificar se tivemos sucesso ou falha
		cy.get('tbody tr td.description').should('have.text', 'Pagamento do Curso de Frontend');
	});

	it('Excluir Transação - Opção 1', () => {
		// Preenchendo o formulário de transação utilizando a function definida
		criarTransacao('Refatoração da Aplicação XPTO', 170, '2023-10-23');
		criarTransacao('Terceirizando o serviço de Backend', -100, '2023-10-23');

		cy.contains('.description', 'Refatoração da Aplicação XPTO') // Identificando o conteúdo que queremos excluir
			.parent()	// Selecionando a linha por completo (elemento nível HTML acima)
			.find('img') // Buscando onde está o comando de exclusão																			
			.click(); // Executando a ação do click da imagem que realiza a ação de exclusão

		// Assertion para verificar se tivemos sucesso ou falha
		cy.get('tbody tr').should('have.length', 1); // Verificando se restou apenas 1 item na tabela
	});

	it('Excluir Transação - Opção 2', () => {
		// Preenchendo o formulário de transação utilizando a function definida
		criarTransacao('Refatoração da Aplicação XPTO', 170, '2023-10-23');
		criarTransacao('Terceirizando o serviço de Backend', -100, '2023-10-23');

		cy.contains('.description', 'Refatoração da Aplicação XPTO') // Identificando o conteúdo que queremos excluir
			.siblings()	// Selecionando os elementos irmãos do elemento selecionado
			.children('img') // Buscando os filhos dos irmãos que tem o img																		
			.click(); // Executando a ação do click da imagem que realiza a ação de exclusão

		// Assertion para verificar se tivemos sucesso ou falha
		cy.get('tbody tr').should('have.length', 1); // Verificando se restou apenas 1 item na tabela
	});
});

function criarTransacao(descricao, valor, data_transacao) {
	// Selecionando a opção para se Cadastrar Nova Transação - Saída
	cy.contains('Nova Transação').click();

	// Inserindo o conteúdo da descrição
	cy.get('#description').type(descricao);

	// Inserindo o conteúdo do valor
	cy.get('#amount').type(valor);

	// Inserindo o conteúdo da data -> Máscara obrigatória: yyyy-mm-dd
	cy.get('#date').type(data_transacao);

	// Selecionando a opção para Salvar a Transação
	cy.contains('button', 'Salvar').click();
}