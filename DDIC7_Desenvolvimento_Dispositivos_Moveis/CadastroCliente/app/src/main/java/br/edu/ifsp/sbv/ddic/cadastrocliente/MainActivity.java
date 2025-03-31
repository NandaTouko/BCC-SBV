package br.edu.ifsp.sbv.ddic.cadastrocliente;

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
    private EditText edtId;

    private EditText edtNome;

    private EditText edtIdade;

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

        edtId = (EditText) findViewById(R.id.edtId);
        edtNome = (EditText) findViewById(R.id.edtNome);
        edtIdade = (EditText) findViewById(R.id.edtIdade);
        textResposta = (TextView) findViewById(R.id.textResposta);
    }

    public void salvar(View v) {
        int id = Integer.parseInt(edtId.getText().toString());
        String nome = edtNome.getText().toString();
        int idade = Integer.parseInt(edtIdade.getText().toString());

        Cliente cliente = new Cliente();
        cliente.setID(id);
        cliente.setNome(nome);
        cliente.setIdade(idade);

        textResposta.setText("Cliente: " + cliente.getNome() + "\nID: " + cliente.getID() + "\nIdade: " + cliente.getIdade());
    }
}