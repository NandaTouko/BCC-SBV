<%@page contentType="text/html" pageEncoding="UTF-8"%>
<%@taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>Gerar Tabela</title>
        <style>
            #table, td {
                border-collapse: collapse;
                border: 1px solid black;
            }
            
            #table td {
                padding: 30px;
            }
        </style>
    </head>
    <body>
        <h2>Tabela Gerada</h2>
        
         <c:choose>
            <c:when test="${(param.qtdLinhas gt 0) and (param.qtdColunas gt 0)}">
                <table id="table">
                    <c:forEach begin="1" end="${param.qtdLinhas}">
                        <tr>
                            <c:forEach begin="1" end="${param.qtdColunas}" varStatus="i">
                                <td>${i.count}</td>
                            </c:forEach>
                        </tr>
                    </c:forEach>
                </table>
            </c:when>
            <c:otherwise>
                <h3 style="color: red">
                    A quantidade de linhas e colunas precisam ser maiores que 0!!
                </h3>
            </c:otherwise>
        </c:choose>
                
        <p>
            <a href="index.html">Voltar</a>
        </p>
    </body>
</html>
