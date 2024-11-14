<%@page contentType="text/html" pageEncoding="UTF-8"%>
<%@taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<c:set var="cp" value="${pageContext.request.contextPath}"/>
<!DOCTYPE html>

<html>
  <head>
    <title>Alterar DVD</title>
    <meta charset="UTF-8">
    <meta name="viewport"
          content="width=device-width, initial-scale=1.0">
    <link rel="stylesheet"
          href="${cp}/css/estilos.css"/>
  </head>

  <body>

    <h1>Alterar DVD</h1>

    <form method="post" action="${cp}/DvdServlet">

      <input name="acao" type="hidden" value="alterar"/>
      <input name="id" type="hidden" value="${requestScope.dvd.id}"/>

      <table>
        <tr>
          <td class="alinharDireita">Título:</td>
          <td>
            <input name="titulo"
                   type="text"
                   size="50"
                   maxlength="100"
                   value="${requestScope.dvd.titulo}"
                   required />
          </td>
        </tr>
        
        <tr>
          <td class="alinharDireita">Ano de Lançamento:</td>
          <td>
            <input name="anoLancamento"
                   type="number"
                   min="1800"
                   value="${requestScope.dvd.anoLancamento}"
                   required />
          </td>
        </tr>
        
        <tr>
          <td class="alinharDireita">Ator Principal:</td>
          <td>
            <jsp:useBean 
                id="servicos" 
                scope="page" 
                class="locacaodvds.servicos.AtorServices"/>
            
            <select name="atorPrincipalId" required>
              <c:forEach items="${servicos.todos}" var="ator">
                <c:choose>
                  <c:when test="${requestScope.dvd.atorPrincipal.id eq ator.id}">
                    <option value="${ator.id}" selected>
                      ${ator.nome}
                    </option>
                  </c:when>
                  <c:otherwise>
                    <option value="${ator.id}">
                      ${ator.nome}
                    </option>
                  </c:otherwise>
                </c:choose>
              </c:forEach>
            </select>
          </td>
        </tr>
        
        <tr>
          <td class="alinharDireita">Ator Coadjuvante:</td>
          <td>              
            <select name="atorCoadjuvanteId" required>
              <c:forEach items="${servicos.todos}" var="ator">
                <c:choose>
                  <c:when test="${requestScope.dvd.atorCoadjuvante.id eq ator.id}">
                    <option value="${ator.id}" selected>
                      ${ator.nome}
                    </option>
                  </c:when>
                  <c:otherwise>
                    <option value="${ator.id}">
                      ${ator.nome}
                    </option>
                  </c:otherwise>
                </c:choose>
              </c:forEach>
            </select>
          </td>
        </tr>
        
        <tr>
          <td class="alinharDireita">Data de Lançamento:</td>
          <td>
            <input name="dataLancamento"
                   type="date"
                   size="8"
                   placeholder="dd/mm/yyyy"
                   value="${requestScope.dvd.dataLancamento}"
                   required />
          </td>
        </tr>
        
        <tr>
          <td class="alinharDireita">Duração em Minutos:</td>
          <td>
            <input name="duracaoMinutos"
                   type="number"
                   min="60"
                   value="${requestScope.dvd.duracaoMinutos}"
                   required />
          </td>
        </tr>
        
        <tr>
          <td class="alinharDireita">Classificação Etária:</td>
          <td>
            <jsp:useBean 
                id="ceServicos" 
                scope="page" 
                class="locacaodvds.servicos.ClassificacaoEtariaServices"/>
            
            <select name="classificacaoEtariaId" required>
              <c:forEach items="${ceServicos.todos}" var="ce">
                <c:choose>
                  <c:when test="${requestScope.dvd.classificacaoEtaria.id eq ce.id}">
                    <option value="${ce.id}" selected>
                      ${ce.descricao}
                    </option>
                  </c:when>
                  <c:otherwise>
                    <option value="${ce.id}">
                      ${ce.descricao}
                    </option>
                  </c:otherwise>
                </c:choose>
              </c:forEach>
            </select>
          </td>
        </tr>
        
        <tr>
          <td class="alinharDireita">Gênero:</td>
          <td>
            <jsp:useBean 
                id="gServicos" 
                scope="page" 
                class="locacaodvds.servicos.GeneroServices"/>
            
            <select name="generoId" required>
              <c:forEach items="${gServicos.todos}" var="g">
                <c:choose>
                  <c:when test="${requestScope.dvd.genero.id eq g.id}">
                    <option value="${g.id}" selected>
                      ${g.descricao}
                    </option>
                  </c:when>
                  <c:otherwise>
                    <option value="${g.id}">
                      ${g.descricao}
                    </option>
                  </c:otherwise>
                </c:choose>
              </c:forEach>
            </select>
          </td>
        </tr>
        
        <tr>
          <td>
            <a href="${cp}/formularios/dvds/listagem.jsp">Voltar</a>
          </td>
          <td class="alinharDireita">
            <input type="submit" value="Alterar"/>
          </td>
        </tr>
      </table>

    </form>

  </body>

</html>
