module project.praticapadroesprojetos {
    requires javafx.controls;
    requires javafx.fxml;

    opens project.praticapadroesprojetos to javafx.fxml;
    exports project.praticapadroesprojetos;
}
