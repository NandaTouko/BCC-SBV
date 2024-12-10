<%@page contentType="text/html" pageEncoding="UTF-8"%>
<%@taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<c:set var="cp" value="${pageContext.request.contextPath}"/>
<!DOCTYPE html>

<html>
  <head>
    <title>Novo Carro</title>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="stylesheet" href="${cp}/css/estilos.css"/>
  </head>

  <body>

    <h1>Novo Carro</h1>

    <form method="post" action="${cp}/CarroServlet">

      <input name="acao" type="hidden" value="inserir"/>

      <table>
        <tr>
          <td class="alinharDireita">Nome:</td>
          <td>
            <input name="nome"
                   type="text"
                   size="20"
                   maxlength="60"
                   required />
          </td>
        </tr>
        
        <tr>
          <td class="alinharDireita">Modelo:</td>
          <td>
            <input name="modelo"
                   type="text"
                   size="20"
                   maxlength="60"
                   required />
          </td>
        </tr>
        
        <tr>
          <td class="alinharDireita">Ano:</td>
          <td>
            <input name="ano"
                   type="number"
                   min="1900"
                   max="2024"
                   required />
          </td>
        </tr>
        
        <tr>
          <td>
            <a href="${cp}/formularios/carros/listagem.jsp">
              Voltar
            </a>
          </td>
          <td class="alinharDireita">
            <input type="submit" value="Salvar"/>
          </td>
        </tr>
      </table>

    </form>

  </body>

</html>
