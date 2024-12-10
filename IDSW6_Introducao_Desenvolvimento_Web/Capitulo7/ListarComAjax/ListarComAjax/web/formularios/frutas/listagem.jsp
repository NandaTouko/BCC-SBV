<%@page contentType="text/html" pageEncoding="UTF-8"%>
<%@taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<c:set var="cp" value="${pageContext.request.contextPath}"/>
<!DOCTYPE html>

<html>
  <head>
    <title>Listagem de Frutas</title>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="stylesheet" href="${cp}/css/estilos.css"/>
    <script src="${cp}/js/libs/jquery/jquery.min.js"></script>
    <script src="${cp}/js/listarDados.js"></script>
  </head>

  <body onload="listarFrutas()">

    <h1>Frutas</h1>

    <p>
      <a href="${cp}/formularios/frutas/novo.jsp">
        Nova Fruta
      </a>
    </p>

    <table class="tabelaListagem">
      <thead>
        <tr>
          <th>ID</th>
          <th>Nome</th>
          <th>Cor</th>
        </tr>
      </thead>
      <tbody id="tbodyFrutas"></tbody>      
    </table>

    <p>
      <a href="${cp}/formularios/frutas/novo.jsp">
        Nova Fruta
      </a>
    </p>

    <p><a href="${cp}/index.jsp">Tela Principal</a></p>

  </body>

</html>
