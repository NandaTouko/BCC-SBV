package br.edu.ifsp.sbv.ddic.crudprodutos;

import android.app.AlertDialog;
import android.content.DialogInterface;
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

import br.edu.ifsp.sbv.ddic.crudprodutos.dao.ProdutoDAO;
import br.edu.ifsp.sbv.ddic.crudprodutos.modelo.Produto;

public class MainActivity extends AppCompatActivity {
    private Produto p;
    private List<Produto> produtos;
    private EditText edtID;
    private EditText edtDescricao;
    private EditText edtValor;
    private ListView lvProdutos;
    private String operacao;
    private ProdutoDAO dao;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        edtID = (EditText) findViewById(R.id.edtID);
        edtDescricao = (EditText) findViewById(R.id.edtDescricao);
        edtValor = (EditText) findViewById(R.id.edtValor);
        lvProdutos = (ListView) findViewById(R.id.lvProdutos);
        lvProdutos.setOnItemClickListener(selecionarProduto);
        lvProdutos.setOnItemLongClickListener(excluirProduto);
        produtos = new ArrayList<Produto>();
        operacao = new String("Novo");
        dao = new ProdutoDAO(getApplicationContext());
        atualizarLista();
    }

    private void excluirProduto(final int idProduto) {
        AlertDialog.Builder builder = new AlertDialog.Builder(this);
        builder.setTitle("Excluir produto?")
            .setMessage("Deseja excluir esse produto?")
            .setCancelable(false)
            .setPositiveButton(getString(R.string.sim),
                new DialogInterface.OnClickListener() {
                    public void onClick(DialogInterface dialog, int id) {
                        if (dao.deletar(idProduto)) {
                            atualizarLista();
                            exibirMensagem(getString(R.string.msgExclusao));
                        } else {
                            exibirMensagem(getString(R.string.msgFalhaExclusao));
                        }

                    }
                })
            .setNegativeButton(getString(R.string.nao),
                new DialogInterface.OnClickListener() {
                    public void onClick(DialogInterface dialog, int id) {
                        dialog.cancel();
                    }
                });
        builder.create();
        builder.show();
    }

    public void salvar(View v) {
        if (operacao.equalsIgnoreCase("Novo")) {
            p = new Produto();
        }

        p.setDescricao(edtDescricao.getText().toString());
        p.setValor(Double.valueOf(edtValor.getText().toString()));

        if (operacao.equalsIgnoreCase("Novo")) {
            dao.salvar(p);
            exibirMensagem("Produto cadastrado com sucesso!");
        } else {
            dao.atualizar(p);
            exibirMensagem("Produto atualizado com sucesso!");
        }

        atualizarLista();
        limparDados();
    }

    public void novo(View v) {
        operacao = new String("Novo");
        limparDados();
    }

    private void limparDados() {
        edtID.setText("");
        edtDescricao.setText("");
        edtDescricao.requestFocus();
        edtValor.setText("");
    }

    private void atualizarLista() {
        produtos = dao.listAll();
        if (produtos != null) {
            if (produtos.size() >= 0) {
                ProdutoListAdapter pla = new ProdutoListAdapter(getApplicationContext(), produtos);
                lvProdutos.setAdapter(pla);
            }
        }
    }

    private AdapterView.OnItemClickListener selecionarProduto = new AdapterView.OnItemClickListener() {
        public void onItemClick(AdapterView<?> arg0, View arg1, int pos, long id) {
            operacao = new String("Atualizar");
            p = produtos.get(pos);
            preecherDados(p);
        }
    };

    private AdapterView.OnItemLongClickListener excluirProduto = new AdapterView.OnItemLongClickListener() {
        public boolean onItemLongClick(AdapterView<?> arg0, View arg1, int pos, long arg3) {
            excluirProduto(produtos.get(pos).getID());
            return true;
        }
    };

    private void preecherDados(Produto produto) {
        edtID.setText(String.valueOf(produto.getID()));
        edtDescricao.setText(produto.getDescricao());
        edtValor.setText(String.valueOf(produto.getValor()));
    }

    private void exibirMensagem(String msg) {
        Toast.makeText(getApplicationContext(), msg, Toast.LENGTH_LONG).show();
    }
}