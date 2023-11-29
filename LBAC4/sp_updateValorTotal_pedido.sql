USE EmpresaPedidos;

/*
	Utilizando o banco de dados
	empresapedidos, faça a
	instrução SQL para criar uma
	procedure que recebe o
	número do pedido e atualiza o
	valor total (pedido.valortotal)
	do pedido baseado nos itens e
	quantidades cadastradas na
	tabela pedidoitens.
*/

DELIMITER // 

CREATE PROCEDURE sp_updateValorTotal(IN CODPEDIDO INT)
BEGIN
	CALL sp_valorpedido(CODPEDIDO, @VALORTOTAL);
    
	UPDATE PEDIDO SET VALORTOTAL = @VALORTOTAL 
    WHERE IDPEDIDO = CODPEDIDO;
END;

//

DELIMITER ;

CALL sp_updateValorTotal(1); 