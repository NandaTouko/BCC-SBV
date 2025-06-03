package br.edu.ifsp.sbv.ddic.crudprodutosfirebase;

import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

import androidx.annotation.NonNull;
import androidx.appcompat.app.AppCompatActivity;

import com.google.android.gms.tasks.OnCompleteListener;
import com.google.android.gms.tasks.Task;
import com.google.firebase.database.DatabaseReference;
import com.google.firebase.database.FirebaseDatabase;

import java.util.HashMap;

public class AddProductActivity extends AppCompatActivity {

    private EditText edtDescription;
    private EditText edtValue;
    private Button btnAdd;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_add_product);

        edtDescription = (EditText) findViewById(R.id.edtDescription);
        edtValue = (EditText) findViewById(R.id.edtValue);
        btnAdd = (Button) findViewById(R.id.btnAdd);

        btnAdd.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                String description = edtDescription.getText().toString();
                String valueString = edtValue.getText().toString();

                if(description.isEmpty()) {
                    edtDescription.setError("Este campo não pode estar vazio!");
                    return;
                }

                if(valueString.isEmpty()) {
                    edtValue.setError("Este campo não pode estar vazio!");
                    return;
                }

                double value = Double.parseDouble(valueString);
                addProductToDB(description, value);
            }
        });
    }

    private void addProductToDB(String description, double value) {
        HashMap<String, Object> productHashMap = new HashMap<>();
        productHashMap.put("description", description);
        productHashMap.put("value", value);

        FirebaseDatabase database = FirebaseDatabase.getInstance();
        DatabaseReference productsRef = database.getReference("products");

        String key = productsRef.push().getKey();
        productHashMap.put("key", key);

        productsRef.child(key).setValue(productHashMap).addOnCompleteListener(new OnCompleteListener<Void>() {
            @Override
            public void onComplete(@NonNull Task<Void> task) {
                Toast.makeText(AddProductActivity.this, "Cadastrado!", Toast.LENGTH_SHORT).show();
                edtDescription.getText().clear();
                edtValue.getText().clear();
                finish();
            }
        });
    }
}