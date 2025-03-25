package br.edu.ifsp.sbv.ddic.areatriangulo;

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
    private EditText edtAltura;
    private EditText edtBase;
    private TextView textResponse;

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

        edtAltura = (EditText) findViewById(R.id.edtAltura);
        edtBase = (EditText) findViewById(R.id.edtBase);
        textResponse = (TextView) findViewById(R.id.textResponse);
    }

    public void calcularArea(View v) {
        if(edtAltura.getText().toString().isEmpty() || edtBase.getText().toString().isEmpty()) {
            textResponse.setText("Preencha todos os campos!");
            return;
        }

        double altura = Double.parseDouble(edtAltura.getText().toString());
        double base = Double.parseDouble(edtBase.getText().toString());
        double area = (base * altura)/2;

        textResponse.setText("A área do triângulo é: " + area);
    }
}