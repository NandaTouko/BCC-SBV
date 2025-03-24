package br.edu.ifsp.sbv.ddic.mediaescolar;

import android.os.Bundle;
import android.view.View;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.Toast;

import androidx.activity.EdgeToEdge;
import androidx.appcompat.app.AppCompatActivity;
import androidx.core.graphics.Insets;
import androidx.core.view.ViewCompat;
import androidx.core.view.WindowInsetsCompat;

public class MainActivity extends AppCompatActivity {
    private EditText nota1;
    private EditText nota2;
    private EditText nota3;
    private EditText nota4;
    private TextView textResultado;

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

        nota1 = (EditText) findViewById(R.id.edtNota1);
        nota2 = (EditText) findViewById(R.id.edtNota2);
        nota3 = (EditText) findViewById(R.id.edtNota3);
        nota4 = (EditText) findViewById(R.id.edtNota4);
        textResultado = (TextView) findViewById(R.id.textResultado);
    }

    public void calcularMedia(View v) {
        if(nota1.getText().toString().isEmpty() || nota2.getText().toString().isEmpty()
                || nota3.getText().toString().isEmpty() || nota4.getText().toString().isEmpty()) {
            Toast.makeText(this, "Digite as 4 notas!", Toast.LENGTH_SHORT).show();
            return;
        }

        double n1 = Double.parseDouble(nota1.getText().toString());
        double n2 = Double.parseDouble(nota2.getText().toString());
        double n3 = Double.parseDouble(nota3.getText().toString());
        double n4 = Double.parseDouble(nota4.getText().toString());

        double media = (n1 + n2 + n3 + n4) / 4;
        String resultado = "";

        if(media >= 6) {
            resultado = "Aprovado";
        } else if (media < 4) {
            resultado = "Reprovado";
        } else {
            resultado = "Exame";
        }

        textResultado.setText("Média: " + media + " - Resultado: " + resultado);
    }
}