package locacaodvds.jdbc;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

public class ConnectionFactory {
    public static Connection getConnection() throws SQLException {
        /* O método getConnection de DriverManagaer recebe como parâmetro
        * a URL da base de dados, o usuário usado para conectar na base
        * e a senha deste usuário. O Driver JDBC apropriado será
        * carregado com base na biblioteca configurada.
       */
        return DriverManager.getConnection(
            "jdbc:mariadb://localhost/locacao_dvds",
            "root",
            "" );
    }

}
