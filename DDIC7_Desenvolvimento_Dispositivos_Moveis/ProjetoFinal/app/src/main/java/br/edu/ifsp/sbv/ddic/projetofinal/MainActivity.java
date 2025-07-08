package br.edu.ifsp.sbv.ddic.projetofinal;

import android.os.Bundle;
import android.widget.Toast;

import androidx.appcompat.app.AppCompatActivity;
import androidx.recyclerview.widget.*;

import java.util.*;

import br.edu.ifsp.sbv.ddic.projetofinal.adapter.ReceitaAdapter;
import br.edu.ifsp.sbv.ddic.projetofinal.modelo.Receita;
import br.edu.ifsp.sbv.ddic.projetofinal.network.ReceitaResponse;
import br.edu.ifsp.sbv.ddic.projetofinal.network.ReceitaService;
import retrofit2.*;
import retrofit2.converter.gson.GsonConverterFactory;

public class MainActivity extends AppCompatActivity {

    private RecyclerView recyclerView;
    private ReceitaAdapter adapter;
    private List<Receita> listaReceitas = new ArrayList<>();

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        recyclerView = findViewById(R.id.recyclerReceitas);
        recyclerView.setLayoutManager(new LinearLayoutManager(this));
        adapter = new ReceitaAdapter(this, listaReceitas);
        recyclerView.setAdapter(adapter);

        Retrofit retrofit = new Retrofit.Builder()
                .baseUrl("https://www.themealdb.com/api/json/v1/1/")
                .addConverterFactory(GsonConverterFactory.create())
                .build();

        ReceitaService service = retrofit.create(ReceitaService.class);
        service.buscarReceitas("chicken").enqueue(new Callback<ReceitaResponse>() {
            @Override
            public void onResponse(Call<ReceitaResponse> call, Response<ReceitaResponse> response) {
                if (response.isSuccessful() && response.body() != null) {
                    listaReceitas.clear();
                    listaReceitas.addAll(response.body().meals);
                    adapter.notifyDataSetChanged();
                } else {
                    Toast.makeText(MainActivity.this, "Erro ao carregar receitas", Toast.LENGTH_SHORT).show();
                }
            }

            @Override
            public void onFailure(Call<ReceitaResponse> call, Throwable t) {
                Toast.makeText(MainActivity.this, "Falha: " + t.getMessage(), Toast.LENGTH_SHORT).show();
            }
        });
    }
}
