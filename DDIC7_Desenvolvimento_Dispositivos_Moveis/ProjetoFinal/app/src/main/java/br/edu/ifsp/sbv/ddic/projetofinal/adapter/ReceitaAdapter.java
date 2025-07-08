package br.edu.ifsp.sbv.ddic.projetofinal.adapter;

import android.content.Context;
import android.view.*;
import android.widget.*;

import androidx.recyclerview.widget.RecyclerView;

import com.bumptech.glide.Glide;

import java.util.List;

import br.edu.ifsp.sbv.ddic.projetofinal.R;
import br.edu.ifsp.sbv.ddic.projetofinal.dao.ReceitaDAO;
import br.edu.ifsp.sbv.ddic.projetofinal.modelo.Receita;

public class ReceitaAdapter extends RecyclerView.Adapter<ReceitaAdapter.ViewHolder> {

    private List<Receita> receitas;
    private Context context;

    public ReceitaAdapter(Context context, List<Receita> receitas) {
        this.context = context;
        this.receitas = receitas;
    }

    @Override
    public ViewHolder onCreateViewHolder(ViewGroup parent, int viewType) {
        View view = LayoutInflater.from(context).inflate(R.layout.item_receita, parent, false);
        return new ViewHolder(view);
    }

    @Override
    public void onBindViewHolder(ViewHolder holder, int position) {
        Receita receita = receitas.get(position);
        holder.nome.setText(receita.getNome());
        holder.categoria.setText("Categoria: " + receita.getCategoria());

        Glide.with(context).load(receita.getImagem()).into(holder.imagem);

        holder.btnFavoritar.setOnClickListener(v -> {
            ReceitaDAO dao = new ReceitaDAO(context);
            if (dao.salvar(receita)) {
                Toast.makeText(context, "Favoritada!", Toast.LENGTH_SHORT).show();
            } else {
                Toast.makeText(context, "Já favoritada", Toast.LENGTH_SHORT).show();
            }
        });
    }

    @Override
    public int getItemCount() {
        return receitas.size();
    }

    public static class ViewHolder extends RecyclerView.ViewHolder {
        TextView nome, categoria;
        ImageView imagem;
        Button btnFavoritar;

        public ViewHolder(View itemView) {
            super(itemView);
            nome = itemView.findViewById(R.id.txtNome);
            categoria = itemView.findViewById(R.id.txtCategoria);
            imagem = itemView.findViewById(R.id.imgReceita);
            btnFavoritar = itemView.findViewById(R.id.btnFavoritar);
        }
    }
}
