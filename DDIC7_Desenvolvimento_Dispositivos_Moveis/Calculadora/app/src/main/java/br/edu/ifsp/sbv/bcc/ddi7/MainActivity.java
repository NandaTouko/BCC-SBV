package br.edu.ifsp.sbv.bcc.ddi7;

import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.EditText;
import android.widget.Toast;

import androidx.activity.EdgeToEdge;
import androidx.appcompat.app.AppCompatActivity;
import androidx.core.graphics.Insets;
import androidx.core.view.ViewCompat;
import androidx.core.view.WindowInsetsCompat;

public class MainActivity extends AppCompatActivity {
    private EditText edtN01;

    private EditText edtN02;

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

        edtN01 = (EditText) findViewById(R.id.edtNumero01);
        edtN02 = (EditText) findViewById(R.id.edtNumero02);
    }

    public void calcular(View v) {
        if (edtN01.getText().toString().isEmpty() || edtN02.getText().toString().isEmpty()) {
            Toast.makeText(this, "Por favor, insira valores nos dois campos!", Toast.LENGTH_SHORT).show();
            return;
        }

        int n01 = Integer.parseInt(edtN01.getText().toString());
        int n02 = Integer.parseInt(edtN02.getText().toString());
        int resultado = 0;

        if(v.getId() == R.id.btnSomar) {
            resultado = n01+n02;
        } else if (v.getId() == R.id.btnSubtrair) {
            resultado = n01-n02;
        } else if (v.getId() == R.id.btnMultiplicar) {
            resultado = n01*n02;
        } else if (v.getId() == R.id.btnDividir) {
            if (n02 != 0) {
                resultado = n01 / n02;
            } else {
                Toast.makeText(this, "Erro: Divisão por zero", Toast.LENGTH_LONG).show();
                return;
            }
        } else {
            Toast.makeText(this, "Operação não reconhecida!", Toast.LENGTH_SHORT).show();
            return;
        }

        Toast.makeText(this, "Resultado: " + resultado, Toast.LENGTH_LONG).show();
    }
}