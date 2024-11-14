<%@page contentType="text/html" pageEncoding="UTF-8"%>
<%@taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<c:set var="cp" value="${pageContext.request.contextPath}"/>
<c:set var="prefixo" value="GeneroServlet?acao=preparar"/>
<!DOCTYPE html>

<html>
  <head>
    <title>Gêneros</title>
    <meta charset="UTF-8">
    <meta name="viewport"
          content="width=device-width, initial-scale=1.0">
    <link rel="stylesheet"
          href="${cp}/css/estilos.css"/>
  </head>

  <body>

    <h1>Gêneros</h1>

    <p>
      <a href="${cp}/formularios/generos/novo.jsp">
        Novo Gênero
      </a>
    </p>

    <table class="tabelaListagem">
      <thead>
        <tr>
          <th>ID</th>
          <th>Descrição</th>
          <th>Alterar</th>
          <th>Excluir</th>
        </tr>
      </thead>
      <tbody>

        <jsp:useBean 
            id="servicos"
            scope="page"
            class="locacaodvds.servicos.GeneroServices"/>

        <c:forEach items="${servicos.todos}" var="g">
          <tr>
            <td>${g.id}</td>
            <td>${g.descricao}</td>
            <td>
              <a href="${cp}/${prefixo}Alteracao&id=${g.id}">
                Alterar
              </a>
            </td>
            <td>
              <a href="${cp}/${prefixo}Exclusao&id=${g.id}">
                Excluir
              </a>
            </td>
          </tr>
        </c:forEach>
      </tbody>
      
    </table>

    <p>
      <a href="${cp}/formularios/generos/novo.jsp">
        Novo Gênero
      </a>
    </p>

    <p><a href="${cp}/index.jsp">Tela Principal</a></p>

  </body>

</html>
