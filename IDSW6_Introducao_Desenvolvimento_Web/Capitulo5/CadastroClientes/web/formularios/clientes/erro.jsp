<%@page contentType="text/html" pageEncoding="UTF-8"%>
<%@taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%@taglib prefix="fn" uri="http://java.sun.com/jsp/jstl/functions" %>
<c:set var="cp" value="${pageContext.request.contextPath}"/>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>Página de Erro | Cliente</title>
        <link rel="stylesheet" href="${cp}/css/estilos.css"/>
    </head>
    
    <body>
        <div class="errorPageCard">
            <h3>Erros ao Inserir ou Atualizar Cliente</h3>

            <ul>
                <c:if test="${fn:length(requestScope.cliente.nome) > 45}">
                    <li>O nome "${requestScope.cliente.nome}" tem mais de 45 caracteres.</li>
                </c:if>

                <c:if test="${requestScope.cliente.nome eq ''}">
                    <li>O nome não pode ser vazio.</li>
                </c:if>

                <c:if test="${fn:length(requestScope.cliente.sobrenome) > 45}">
                    <li>O sobrenome "${requestScope.cliente.sobrenome}" tem mais de 45 caracteres.</li>
                </c:if>

                <c:if test="${requestScope.cliente.sobrenome eq ''}">
                    <li>O sobrenome não pode ser vazio.</li>
                </c:if>
                    
                <c:if test="${requestScope.cliente.dataNascimento eq null}">
                    <li>A data de nascimento não pode ser vazia.</li>
                </c:if>
                    
                <c:if test="${requestScope.cliente.cpf eq ''}">
                    <li>O CPF não pode ser vazio.</li>
                </c:if>
                    
                <c:if test="${requestScope.cpfInvalido}">
                    <li>O CPF ${requestScope.cliente.cpf} é inválido, pois 
                        precisa estar no formato XXX.XXX.XXX-XX e todos os dígitos precisam ser números.</li>
                </c:if>
                    
                <c:if test="${requestScope.cliente.email eq ''}">
                    <li>O e-mail não pode ser vazio.</li>
                </c:if>
                    
                <c:if test="${fn:length(requestScope.cliente.email) > 60}">
                    <li>O e-mail "${requestScope.cliente.email}" tem mais de 60 caracteres.</li>
                </c:if>
                    
                <c:if test="${requestScope.emailInvalido}">
                    <li>O e-mail ${requestScope.cliente.email} é inválido, pois 
                        precisa começar com letras ou números, ter um 
                        "@" no meio, seguido por um nome de domínio e terminar 
                        com um ponto e pelo menos duas letras (como .com ou .org).</li>
                </c:if>
                    
                <c:if test="${requestScope.cliente.logradouro eq ''}">
                    <li>O logradouro não pode ser vazio.</li>
                </c:if>
                    
                <c:if test="${fn:length(requestScope.cliente.logradouro) > 50}">
                    <li>O logradouro "${requestScope.cliente.logradouro}" tem mais de 50 caracteres.</li>
                </c:if>
                    
                <c:if test="${requestScope.cliente.numero eq ''}">
                    <li>O número não pode ser vazio.</li>
                </c:if>
                    
                <c:if test="${fn:length(requestScope.cliente.numero) > 6}">
                    <li>O número "${requestScope.cliente.numero}" tem mais de 6 caracteres.</li>
                </c:if>
                    
                <c:if test="${requestScope.cliente.bairro eq ''}">
                    <li>O bairro não pode ser vazio.</li>
                </c:if>
                    
                <c:if test="${fn:length(requestScope.cliente.bairro) > 30}">
                    <li>O bairro "${requestScope.cliente.bairro}" tem mais de 30 caracteres.</li>
                </c:if>
                    
                <c:if test="${requestScope.cliente.cep eq ''}">
                    <li>O CEP não pode ser vazio.</li>
                </c:if>
                    
                <c:if test="${requestScope.cepInvalido}">
                    <li>O CEP ${requestScope.cliente.cep} é inválido, pois 
                        precisa estar no formato XXXXX-XXX e todos os dígitos precisam ser números.</li>
                </c:if>
            </ul>

            <a href="${cp}/formularios/clientes/listagem.jsp">
                Voltar
            </a>
        </div>
    </body>
</html>
