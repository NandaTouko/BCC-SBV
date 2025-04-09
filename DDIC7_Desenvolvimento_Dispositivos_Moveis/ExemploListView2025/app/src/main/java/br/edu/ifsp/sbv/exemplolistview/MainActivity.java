package br.edu.ifsp.sbv.exemplolistview;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.EditText;
import android.widget.ListView;
import android.widget.Spinner;
import android.widget.Toast;

import java.util.ArrayList;
import java.util.List;

import br.edu.ifsp.sbv.exemplolistview.modelo.Pessoa;


public class MainActivity extends AppCompatActivity {

    private Pessoa p;
    private List<Pessoa> pessoas;
    private EditText edNome;
    private EditText edIdade;
    private ListView lvPessoas;

    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        edNome = (EditText) findViewById(R.id.edNome);
        edIdade = (EditText) findViewById(R.id.edIdade);
        lvPessoas = (ListView) findViewById(R.id.lvPessoas);
        lvPessoas.setOnItemClickListener(selecionarPessoa);
        pessoas = new ArrayList<Pessoa>();

    }



    public void salvar(View v) {
        p = new Pessoa();
        p.setNome(edNome.getText().toString());
        p.setIdade(Integer.valueOf(edIdade.getText().toString()));
        pessoas.add(p);
        atulizarLista();
        limparDados();
        exibirMensagem("Pessoa cadastrada com sucesso!");

    }

    private void limparDados() {
        edNome.setText("");
        edNome.requestFocus();
        edIdade.setText("");

    }

    private void atulizarLista() {
        PessoaListAdapter pla = new PessoaListAdapter(getApplicationContext(),
                pessoas);
        lvPessoas.setAdapter(pla);

    }

    private AdapterView.OnItemClickListener selecionarPessoa = new AdapterView.OnItemClickListener() {

        public void onItemClick(AdapterView<?> arg0, View arg1, int pos, long id) {
            Pessoa pessoa = pessoas.get(pos);
            preecherDados(pessoa);

        }

        private void preecherDados(Pessoa pessoa) {
            edNome.setText(pessoa.getNome());
            edIdade.setText(String.valueOf(pessoa.getIdade()));

        }

    };

    private void exibirMensagem(String msg) {
        Toast.makeText(getApplicationContext(), msg, Toast.LENGTH_LONG).show();
    }
}