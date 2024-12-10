<%@page contentType="text/html" pageEncoding="UTF-8"%>
<%@taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<c:set var="cp" value="${pageContext.request.contextPath}"/>
<!DOCTYPE html>

<html>
  <head>
    <title>Listagem de Carros</title>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="stylesheet" href="${cp}/css/estilos.css"/>
    <script src="${cp}/js/libs/jquery/jquery.min.js"></script>
    <script src="${cp}/js/listarDados.js"></script>
  </head>

  <body onload="listarCarros()">

    <h1>Carros</h1>

    <p>
      <a href="${cp}/formularios/carros/novo.jsp">
        Novo Carro
      </a>
    </p>

    <table class="tabelaListagem">
      <thead>
        <tr>
          <th>ID</th>
          <th>Nome</th>
          <th>Modelo</th>
          <th>Ano</th>
        </tr>
      </thead>
      <tbody id="tbodyCarros"></tbody>      
    </table>

    <p>
      <a href="${cp}/formularios/carros/novo.jsp">
        Novo Carro
      </a>
    </p>

    <p><a href="${cp}/index.jsp">Tela Principal</a></p>

  </body>

</html>
