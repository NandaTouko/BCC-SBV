<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>Exibe Dados do Cliente</title>
    </head>
    <body>
        <h1>Dados do Cliente</h1>
        
        <p>
            <strong>Nome: </strong> ${requestScope.cliente.nome}
        </p>
        
        <p>
            <strong>Sobrenome: </strong> ${requestScope.cliente.sobrenome}
        </p>
        
        <p>
            <strong>CPF: </strong> ${requestScope.cliente.cpf}
        </p>
        
        <p>
            <strong>Data de Nascimento: </strong> ${requestScope.cliente.dataNasc}
        </p>
        
        <p>
            <strong>Sexo: </strong> ${requestScope.cliente.sexo}
        </p>
        
        <p>
            <strong>E-mail: </strong> ${requestScope.cliente.email}
        </p>
        
        <p>
            <strong>Observações: </strong> ${requestScope.cliente.observacoes}
        </p>
        
        <p>
            <strong>Endereço: </strong> 
            ${requestScope.cliente.logradouro}, ${requestScope.cliente.numero}
            - ${requestScope.cliente.cidade}, ${requestScope.cliente.estado} - ${requestScope.cliente.cep}
        </p>
        
        <p>
            <strong>Complemento: </strong> ${requestScope.cliente.complemento}
        </p>
        
        <p>
            <strong>Possui filhos? </strong> ${requestScope.cliente.filhos}
        </p>
        
        <p>
            <a href="index.html">Voltar</a>
        </p>
    </body>
</html>
