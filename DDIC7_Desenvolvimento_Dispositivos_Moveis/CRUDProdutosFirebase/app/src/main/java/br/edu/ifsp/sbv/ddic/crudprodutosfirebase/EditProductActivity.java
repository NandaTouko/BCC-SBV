package br.edu.ifsp.sbv.ddic.crudprodutosfirebase;

import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

import androidx.annotation.NonNull;
import androidx.appcompat.app.AppCompatActivity;

import com.google.firebase.database.DataSnapshot;
import com.google.firebase.database.DatabaseError;
import com.google.firebase.database.DatabaseReference;
import com.google.firebase.database.FirebaseDatabase;
import com.google.firebase.database.ValueEventListener;

public class EditProductActivity extends AppCompatActivity {
    private EditText edtEditDescription;
    private EditText edtEditValue;
    private Button btnEdit;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_edit_product);

        edtEditDescription = (EditText) findViewById(R.id.edtEditDescription);
        edtEditValue = (EditText) findViewById(R.id.edtEditValue);
        btnEdit = (Button) findViewById(R.id.btnEdit);

        String productKey = getIntent().getStringExtra("productKey");

        DatabaseReference refProduct = FirebaseDatabase.getInstance().getReference("products").child(productKey);

        refProduct.addListenerForSingleValueEvent(new ValueEventListener() {
            @Override
            public void onDataChange(@NonNull DataSnapshot snapshot) {
                Product product = snapshot.getValue(Product.class);
                if (product != null) {
                    edtEditDescription.setText(product.getDescription());
                    edtEditValue.setText(String.valueOf(product.getValue()));
                }
            }

            @Override
            public void onCancelled(@NonNull DatabaseError error) {
                Log.e("Firebase", "Erro ao carregar produto!", error.toException());
            }
        });

        btnEdit.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                String description = edtEditDescription.getText().toString();
                String valueString = edtEditValue.getText().toString();

                if(description.isEmpty()) {
                    edtEditDescription.setError("Este campo não pode estar vazio!");
                    return;
                }

                if(valueString.isEmpty()) {
                    edtEditValue.setError("Este campo não pode estar vazio!");
                    return;
                }

                double value = Double.parseDouble(valueString);
                Product product = new Product(description, value, productKey);
                editProductToDB(product, refProduct);
            }
        });
    }

    private void editProductToDB(Product product, DatabaseReference refProduct) {
        refProduct.setValue(product)
            .addOnSuccessListener(aVoid -> {
                Toast.makeText(EditProductActivity.this, "Produto atualizado!", Toast.LENGTH_SHORT).show();
                edtEditDescription.getText().clear();
                edtEditValue.getText().clear();
                finish();
            })
            .addOnFailureListener(e -> {
                Log.e("Firebase", "Erro ao atualizar produto", e);
                Toast.makeText(EditProductActivity.this, "Erro ao atualizar!", Toast.LENGTH_SHORT).show();
            });
    }
}