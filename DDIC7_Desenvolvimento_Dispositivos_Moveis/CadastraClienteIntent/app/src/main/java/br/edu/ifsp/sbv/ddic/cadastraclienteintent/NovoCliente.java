package br.edu.ifsp.sbv.ddic.cadastraclienteintent;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;

import androidx.activity.EdgeToEdge;
import androidx.appcompat.app.AppCompatActivity;
import androidx.core.graphics.Insets;
import androidx.core.view.ViewCompat;
import androidx.core.view.WindowInsetsCompat;

public class NovoCliente extends Activity {
    private EditText edtId;
    private EditText edtNome;
    private EditText edtIdade;
    private Button btnSalvar;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_novo_cliente);

        edtId = (EditText) findViewById(R.id.edtId);
        edtNome = (EditText) findViewById(R.id.edtNome);
        edtIdade = (EditText) findViewById(R.id.edtIdade);

        btnSalvar = (Button) findViewById(R.id.btnSalvar);
        btnSalvar.setOnClickListener(new View.OnClickListener() {

            @Override
            public void onClick(View v) {
                int id = Integer.parseInt(edtId.getText().toString());
                String nome = edtNome.getText().toString();
                int idade = Integer.parseInt(edtIdade.getText().toString());

                Cliente cliente = new Cliente();
                cliente.setNome(nome);
                cliente.setID(id);
                cliente.setIdade(idade);

                Intent it = new Intent();
                it.putExtra("cliente", cliente);
                setResult(1, it);
                finish();
            }
        });
    }

    @Override
    public void onBackPressed() {
        Intent it = new Intent();
        it.putExtra("msg", "Não cadastrou um cliente!");
        setResult(2, it);
        finish();
    }
}