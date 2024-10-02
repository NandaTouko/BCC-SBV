<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>Exibe Dados do DVD</title>
    </head>
    <body>
        <h2>Dados do DVD</h2>
        
        <p>
            <strong>Número: </strong> ${requestScope.dvd.numero}
        </p>
        
        <p>
            <strong>Título: </strong> ${requestScope.dvd.titulo}
        </p>
        
        <p>
            <strong>Ator/atriz Principal: </strong> ${requestScope.dvd.atorPrincipal}
        </p>
        
        <p>
            <strong>Ator/atriz Coadjuvante: </strong> ${requestScope.dvd.atorCoadjuvante}
        </p>
        
        <p>
            <strong>Diretor: </strong> ${requestScope.dvd.diretor}
        </p>
        
        <p>
            <strong>Ano de Lançamento: </strong> ${requestScope.dvd.ano}
        </p>
        
        <p>
            <a href="index.html">Voltar</a>
        </p>
    </body>
</html>
