module br.edu.ifsp.sbv.hellofxml {
    requires javafx.controls;
    requires javafx.fxml;
    requires java.base;

    opens br.edu.ifsp.sbv.hellofxml to javafx.fxml;
    opens br.edu.ifsp.sbv.gui to javafx.fxml;
    exports br.edu.ifsp.sbv.hellofxml;
}
