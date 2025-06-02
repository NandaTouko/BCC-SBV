package br.edu.ifsp.sbv.ddic.crudprodutosfirebase;

import android.view.View;
import android.widget.TextView;

import androidx.annotation.NonNull;
import androidx.recyclerview.widget.RecyclerView;

public class ProductViewHolder extends RecyclerView.ViewHolder {
    public TextView tvDescription;
    public TextView tvValue;
    public ProductViewHolder(@NonNull View itemView) {
        super(itemView);
        tvDescription = (TextView) itemView.findViewById(R.id.tvDescription);
        tvValue = (TextView) itemView.findViewById(R.id.tvValue);
    }
}
