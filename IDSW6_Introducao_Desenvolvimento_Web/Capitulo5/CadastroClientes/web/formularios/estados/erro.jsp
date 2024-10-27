<%@page contentType="text/html" pageEncoding="UTF-8"%>
<%@taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%@taglib prefix="fn" uri="http://java.sun.com/jsp/jstl/functions" %>
<c:set var="cp" value="${pageContext.request.contextPath}"/>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>Página de Erro | Estado</title>
        <link rel="stylesheet" href="${cp}/css/estilos.css"/>
    </head>
    
    <body>
        <div class="errorPageCard">
            <h3>Erros ao Inserir ou Atualizar Estado</h3>

            <ul>
                <c:if test="${fn:length(requestScope.estado.nome) > 30}">
                    <li>O nome "${requestScope.estado.nome}" tem mais de 30 caracteres.</li>
                </c:if>

                <c:if test="${requestScope.estado.nome eq ''}">
                    <li>O nome não pode ser vazio.</li>
                </c:if>

                <c:if test="${fn:length(requestScope.estado.sigla) > 2}">
                    <li>A sigla "${requestScope.estado.sigla}" tem mais de 2 caracteres.</li>
                </c:if>

                <c:if test="${requestScope.estado.sigla eq ''}">
                    <li>A sigla não pode ser vazia.</li>
                </c:if>
            </ul>

            <a href="${cp}/formularios/estados/listagem.jsp">
                Voltar
            </a>
        </div>
    </body>
</html>
