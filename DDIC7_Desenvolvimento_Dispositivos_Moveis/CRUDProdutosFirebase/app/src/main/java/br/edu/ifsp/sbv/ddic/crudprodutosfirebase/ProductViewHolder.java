package br.edu.ifsp.sbv.ddic.crudprodutosfirebase;

import android.view.View;
import android.widget.TextView;

import androidx.annotation.NonNull;
import androidx.recyclerview.widget.RecyclerView;

public class ProductViewHolder extends RecyclerView.ViewHolder {
    private TextView tvDescription;
    private TextView tvValue;
    private TextView tvKey;
    public ProductViewHolder(@NonNull View itemView) {
        super(itemView);
        tvDescription = (TextView) itemView.findViewById(R.id.tvDescription);
        tvValue = (TextView) itemView.findViewById(R.id.tvValue);
        tvKey = (TextView) itemView.findViewById(R.id.tvKey);
    }

    public void bind(Product product, View.OnClickListener onClickListener
            , View.OnLongClickListener OnLongClickListener) {
        tvDescription.setText("Descrição: " + product.getDescription());
        tvValue.setText("Valor: " + String.valueOf(product.getValue()));
        tvKey.setText("ID: " + product.getKey());

        itemView.setOnClickListener(onClickListener);
        itemView.setOnLongClickListener(OnLongClickListener);
    }
}
