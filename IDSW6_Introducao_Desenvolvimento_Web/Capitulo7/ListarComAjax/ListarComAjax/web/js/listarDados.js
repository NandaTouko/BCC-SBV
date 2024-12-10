function listarFrutas() {
    $.ajax("/ListarComAjax/FrutaServlet", {
        data: { acao: "listar"},
        dataType: "json"
    }).done((data) => {
        let tbody = $( "#tbodyFrutas" );
        tbody.html( "" );
        
        data.forEach( fruta => {
            tbody.append(
                `<tr>
                    <td>${fruta.id}</td>
                    <td>${fruta.nome}</td>
                    <td>${fruta.cor}</td>
                </tr>`
            );
        });
    }).fail( ( jqXHR, textStatus, errorThrown ) => {
        alert( "Erro: " + errorThrown + "\n" +
               "Status: " + textStatus );
    });
}

function listarCarros() {
    $.ajax("/ListarComAjax/CarroServlet", {
        data: { acao: "listar"},
        dataType: "json"
    }).done((data) => {
        let tbody = $( "#tbodyCarros" );
        tbody.html( "" );
        
        data.forEach( carro => {
            tbody.append(
                `<tr>
                    <td>${carro.id}</td>
                    <td>${carro.nome}</td>
                    <td>${carro.modelo}</td>
                    <td>${carro.ano}</td>
                </tr>`
            );
        });
    }).fail( ( jqXHR, textStatus, errorThrown ) => {
        alert( "Erro: " + errorThrown + "\n" +
               "Status: " + textStatus );
    });
}

function listarProdutos() {
    $.ajax("/ListarComAjax/ProdutoServlet", {
        data: { acao: "listar"},
        dataType: "json"
    }).done((data) => {
        let tbody = $( "#tbodyProdutos" );
        tbody.html( "" );
        
        data.forEach( produto => {
            tbody.append(
                `<tr>
                    <td>${produto.id}</td>
                    <td>${produto.descricao}</td>
                    <td>${produto.qtdEstoque}</td>
                </tr>`
            );
        });
    }).fail( ( jqXHR, textStatus, errorThrown ) => {
        alert( "Erro: " + errorThrown + "\n" +
               "Status: " + textStatus );
    });
}


