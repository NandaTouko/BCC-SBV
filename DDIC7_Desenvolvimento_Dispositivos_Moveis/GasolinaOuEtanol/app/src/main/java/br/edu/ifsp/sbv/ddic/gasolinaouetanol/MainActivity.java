package br.edu.ifsp.sbv.ddic.gasolinaouetanol;

import android.os.Bundle;
import android.view.View;
import android.widget.EditText;
import android.widget.TextView;

import androidx.activity.EdgeToEdge;
import androidx.appcompat.app.AppCompatActivity;
import androidx.core.graphics.Insets;
import androidx.core.view.ViewCompat;
import androidx.core.view.WindowInsetsCompat;

public class MainActivity extends AppCompatActivity {
    private EditText edtGasolina;
    private EditText edtEtanol;
    private TextView textResposta;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        EdgeToEdge.enable(this);
        setContentView(R.layout.activity_main);
        ViewCompat.setOnApplyWindowInsetsListener(findViewById(R.id.main), (v, insets) -> {
            Insets systemBars = insets.getInsets(WindowInsetsCompat.Type.systemBars());
            v.setPadding(systemBars.left, systemBars.top, systemBars.right, systemBars.bottom);
            return insets;
        });

        edtGasolina = (EditText) findViewById(R.id.edtGasolina);
        edtEtanol = (EditText) findViewById(R.id.edtEtanol);
        textResposta = (TextView) findViewById(R.id.textResposta);
    }

    public void verificar(View v) {
        if(edtGasolina.getText().toString().isEmpty() || edtEtanol.getText().toString().isEmpty()) {
            textResposta.setText("Preencha todos os campos!");
            return;
        }

        double gasolina = Double.parseDouble(edtGasolina.getText().toString());
        double etanol = Double.parseDouble(edtEtanol.getText().toString());
        double diferencaPercentual = 0;
        String qualCompensa = "";

        if (gasolina > etanol) {
            diferencaPercentual = ((gasolina - etanol) / etanol) * 100;
            qualCompensa = "Etanol";
        } else {
            diferencaPercentual = ((etanol - gasolina) / gasolina) * 100;
            qualCompensa = "Gasolina";
        }

        textResposta.setText(qualCompensa + " compensa mais. Diferença percentual: " + diferencaPercentual + "%");
    }
}