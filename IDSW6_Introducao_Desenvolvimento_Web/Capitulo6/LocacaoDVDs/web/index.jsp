<%@page contentType="text/html" pageEncoding="UTF-8"%>
<%@taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<c:set var="cp" value="${pageContext.request.contextPath}"/>
<!DOCTYPE html>

<html>
  <head>
    <title>Locação de DVDs</title>
    <meta charset="UTF-8">
    <meta name="viewport"
          content="width=device-width, initial-scale=1.0">
    <link rel="stylesheet"
          href="${cp}/css/estilos.css"/>
  </head>

  <body>

    <h1>Locação de DVDs</h1>

    <p>
      <a href="${cp}/formularios/atores/listagem.jsp">Atores</a>
    </p>
    <p>
      <a href="${cp}/formularios/classificacoesEtarias/listagem.jsp">
          Classificações Etárias
      </a>
    </p>
    <p>
      <a href="${cp}/formularios/dvds/listagem.jsp">DVDs</a>
    </p>
    <p>
      <a href="${cp}/formularios/generos/listagem.jsp">Gêneros</a>
    </p>

  </body>

</html>
