package br.edu.ifsp.sbv.exemplointent;

import androidx.activity.result.ActivityResult;
import androidx.activity.result.ActivityResultCallback;
import androidx.activity.result.ActivityResultLauncher;
import androidx.activity.result.contract.ActivityResultContracts;
import androidx.appcompat.app.AppCompatActivity;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {

    ActivityResultLauncher<Intent> mStartForResult = registerForActivityResult(new ActivityResultContracts.StartActivityForResult(),
            new ActivityResultCallback<ActivityResult>() {
                @Override
                public void onActivityResult(ActivityResult result) {


                    Bundle params = result.getData() != null ? result.getData().getExtras() : null;

                    if (params != null) {
                        String msg = params.getString("msg");

                        if (result.getResultCode() == 1) {
                            Toast.makeText(getApplicationContext(), "Escolheu sim:" + msg, Toast.LENGTH_LONG).show();
                        } else if (result.getResultCode() == 2) {
                            Toast.makeText(getApplicationContext(), "Escolheu não:" + msg, Toast.LENGTH_LONG).show();
                        } else {
                            Toast.makeText(getApplicationContext(), "Não definido:" + msg, Toast.LENGTH_LONG).show();
                        }
                    }
                }

            });

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        // Abrir Tela Sim Não
        Button abrirTela = (Button) findViewById(R.id.btTelaSimNao);
        abrirTela.setText("Abrir Tela Sim/Não");
        abrirTela.setOnClickListener(new View.OnClickListener() {

            @Override
            public void onClick(View arg0) {
                Intent it = new Intent(getApplicationContext(), ExemploTelaSimNao.class);
                mStartForResult .launch(it);


            }
        });
    }




}