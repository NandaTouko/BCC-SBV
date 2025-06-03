package br.edu.ifsp.sbv.ddic.crudprodutosfirebase;

import android.app.AlertDialog;
import android.content.Intent;
import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Toast;

import androidx.annotation.NonNull;
import androidx.appcompat.app.AppCompatActivity;
import androidx.recyclerview.widget.LinearLayoutManager;
import androidx.recyclerview.widget.RecyclerView;

import com.firebase.ui.database.FirebaseRecyclerAdapter;
import com.firebase.ui.database.FirebaseRecyclerOptions;
import com.google.android.material.floatingactionbutton.FloatingActionButton;
import com.google.firebase.database.DatabaseReference;
import com.google.firebase.database.FirebaseDatabase;

public class MainActivity extends AppCompatActivity {
    private FloatingActionButton floatingBtnAdd;
    private RecyclerView rvProducts;
    private FirebaseRecyclerAdapter<Product, ProductViewHolder> adapter;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        floatingBtnAdd = (FloatingActionButton) findViewById(R.id.floatingBtnAdd);
        rvProducts = (RecyclerView) findViewById(R.id.rvProducts);
        rvProducts.setLayoutManager(new LinearLayoutManager(this));

        floatingBtnAdd.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Intent intent = new Intent(MainActivity.this, AddProductActivity.class);
                startActivity(intent);
            }
        });

        DatabaseReference refProducts = FirebaseDatabase.getInstance().getReference("products");
        FirebaseRecyclerOptions<Product> options =
                new FirebaseRecyclerOptions.Builder<Product>()
                        .setQuery(refProducts, Product.class)
                        .build();

        adapter = new FirebaseRecyclerAdapter<Product, ProductViewHolder>(options) {
            @Override
            protected void onBindViewHolder(@NonNull ProductViewHolder holder, int position, @NonNull Product model) {
                holder.bind(model, v -> {
                    Intent intent = new Intent(v.getContext(), EditProductActivity.class);
                    intent.putExtra("productKey", model.getKey());
                    v.getContext().startActivity(intent);
                },v -> {
                    alertDelete(model.getKey());
                    return true;
                });
            }

            @NonNull
            @Override
            public ProductViewHolder onCreateViewHolder(@NonNull ViewGroup parent, int viewType) {
                View view = LayoutInflater.from(parent.getContext()).inflate(R.layout.product_item, parent, false);
                return new ProductViewHolder(view);
            }
        };

        rvProducts.setAdapter(adapter);
    }

    @Override
    protected void onStart() {
        super.onStart();
        adapter.startListening();
    }

    @Override
    protected void onStop() {
        super.onStop();
        adapter.stopListening();
    }

    @Override
    protected void onResume() {
        super.onResume();
        if (adapter != null) {
            adapter.notifyDataSetChanged();
        }
    }

    public void alertDelete(String productKey) {
        new AlertDialog.Builder(this)
                .setTitle("Excluir Produto")
                .setMessage("Tem certeza que deseja excluir este produto?")
                .setPositiveButton("Sim", (dialog, which) -> deleteProduct(productKey))
                .setNegativeButton("Cancelar", (dialog, which) -> dialog.dismiss())
                .show();
    }

    private void deleteProduct(String productKey) {
        DatabaseReference refProducts = FirebaseDatabase.getInstance().getReference("products").child(productKey);

        refProducts.removeValue()
                .addOnSuccessListener(aVoid -> Toast.makeText(this, "Produto excluído!", Toast.LENGTH_SHORT).show())
                .addOnFailureListener(e -> Toast.makeText(this, "Erro ao excluir", Toast.LENGTH_SHORT).show());
    }
}