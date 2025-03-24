package br.edu.ifsp.sbv.ddic7;

import android.os.Bundle;
import android.view.View;
import android.widget.EditText;
import android.widget.Toast;

import androidx.activity.EdgeToEdge;
import androidx.appcompat.app.AppCompatActivity;
import androidx.core.graphics.Insets;
import androidx.core.view.ViewCompat;
import androidx.core.view.WindowInsetsCompat;

public class MainActivity extends AppCompatActivity {
    private EditText edtPeso;
    private EditText edtAltura;

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

        edtPeso = (EditText) findViewById(R.id.edtPeso);
        edtAltura = (EditText) findViewById(R.id.edtAltura);
    }

    public void calcular(View v) {
        if (edtPeso.getText().toString().isEmpty() || edtAltura.getText().toString().isEmpty()) {
            Toast.makeText(this, "Para calcular o IMC é preciso digitar o Peso e a Altura!",
                    Toast.LENGTH_SHORT).show();
            return;
        }

        double peso = Double.parseDouble(edtPeso.getText().toString());
        double altura = Double.parseDouble(edtAltura.getText().toString());
        double imc = peso / (altura * altura);

        String classificacao = "";
        if (imc < 18.5) {
            classificacao = "MAGREZA";
        } else if (imc >= 18.5 && imc <= 24.9) {
            classificacao = "NORMAL";
        } else if (imc > 25 && imc <= 29.9) {
            classificacao = "SOBREPESO";
        } else if (imc > 30 && imc <= 39.9) {
            classificacao = "OBESIDADE";
        } else {
            classificacao = "OBESIDADE GRAVE";
        }

        Toast.makeText(this, "Resultado: " + classificacao,
                Toast.LENGTH_SHORT).show();
    }
}