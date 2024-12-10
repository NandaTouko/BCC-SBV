<%@page contentType="text/html" pageEncoding="UTF-8"%>
<%@taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<c:set var="cp" value="${pageContext.request.contextPath}"/>
<!DOCTYPE html>

<html>
  <head>
    <title>Listagem de Produtos</title>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="stylesheet" href="${cp}/css/estilos.css"/>
    <script src="${cp}/js/libs/jquery/jquery.min.js"></script>
    <script src="${cp}/js/listarDados.js"></script>
  </head>

  <body onload="listarProdutos()">

    <h1>Produtos</h1>

    <p>
      <a href="${cp}/formularios/produtos/novo.jsp">
        Novo Produto
      </a>
    </p>

    <table class="tabelaListagem">
      <thead>
        <tr>
          <th>ID</th>
          <th>Descrição</th>
          <th>Quantidade em Estoque</th>
        </tr>
      </thead>
      <tbody id="tbodyProdutos"></tbody>      
    </table>

    <p>
      <a href="${cp}/formularios/produtos/novo.jsp">
        Novo Produto
      </a>
    </p>

    <p><a href="${cp}/index.jsp">Tela Principal</a></p>

  </body>

</html>
