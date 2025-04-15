package br.edu.ifsp.sbv.ddic.listarclientes;

import android.content.Context;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.BaseAdapter;
import android.widget.TextView;

import java.util.List;

import br.edu.ifsp.sbv.ddic.listarclientes.Modelo.Produto;

public class ProdutoListAdapter extends BaseAdapter {
    private Context context;
    private List<Produto> lista;

    public ProdutoListAdapter(Context context, List<Produto> lista) {
        this.context = context;
        this.lista = lista;
    }

    public int getCount() {
        return lista.size();
    }

    public Object getItem(int position) {
        return lista.get(position);
    }

    public long getItemId(int position) {
        return position;
    }

    public View getView(int position, View convertView, ViewGroup parent) {
        Produto p = lista.get(position);
        LayoutInflater inflater = (LayoutInflater) context.getSystemService(Context.LAYOUT_INFLATER_SERVICE);
        View view = inflater.inflate(R.layout.produtos, null);

        TextView id = (TextView) view.findViewById(R.id.textId);
        id.setText(String.valueOf(p.getID()));

        TextView descricao = (TextView) view.findViewById(R.id.textDescricao);
        descricao.setText(p.getDescricao());

        TextView valor = (TextView) view.findViewById(R.id.textValor);
        valor.setText(String.valueOf(p.getValor()));

        return view;
    }
}
