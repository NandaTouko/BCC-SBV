package br.edu.ifsp.sbv.ddic.listarclientes;

import android.os.Bundle;
import android.view.View;
import android.widget.AdapterView;
import android.widget.EditText;
import android.widget.ListView;
import android.widget.Toast;

import androidx.activity.EdgeToEdge;
import androidx.appcompat.app.AppCompatActivity;
import androidx.core.graphics.Insets;
import androidx.core.view.ViewCompat;
import androidx.core.view.WindowInsetsCompat;

import java.util.ArrayList;
import java.util.List;

import br.edu.ifsp.sbv.ddic.listarclientes.Modelo.Produto;

public class MainActivity extends AppCompatActivity {
    private Produto p;
    private List<Produto> produtos;
    private EditText edtID;
    private EditText edtDescricao;
    private EditText edtValor;
    private ListView lvProdutos;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        edtID = (EditText) findViewById(R.id.edtID);
        edtDescricao = (EditText) findViewById(R.id.edtDescricao);
        edtValor = (EditText) findViewById(R.id.edtValor);
        lvProdutos = (ListView) findViewById(R.id.lvProdutos);
        lvProdutos.setOnItemClickListener(selecionarPessoa);
        produtos = new ArrayList<Produto>();
    }

    public void salvar(View v) {
        p = new Produto();
        p.setID(Integer.parseInt(edtID.getText().toString()));
        p.setDescricao(edtDescricao.getText().toString());
        p.setValor(Double.parseDouble(edtValor.getText().toString()));
        produtos.add(p);
        atulizarLista();
        limparDados();
        exibirMensagem("Produto cadastrado com sucesso!");
    }

    private void limparDados() {
        edtID.setText("");
        edtDescricao.setText("");
        edtValor.setText("");
    }

    private void atulizarLista() {
        ProdutoListAdapter pla = new ProdutoListAdapter(getApplicationContext(), produtos);
        lvProdutos.setAdapter(pla);
    }

    private AdapterView.OnItemClickListener selecionarPessoa = new AdapterView.OnItemClickListener() {
        public void onItemClick(AdapterView<?> arg0, View arg1, int pos, long id) {
            Produto produto = produtos.get(pos);
            preecherDados(produto);
        }

        private void preecherDados(Produto produto) {
            edtID.setText(String.valueOf(produto.getID()));
            edtDescricao.setText(produto.getDescricao());
            edtValor.setText(String.valueOf(produto.getValor()));
        }
    };

    private void exibirMensagem(String msg) {
        Toast.makeText(getApplicationContext(), msg, Toast.LENGTH_LONG).show();
    }
}