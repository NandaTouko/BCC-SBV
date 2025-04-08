package br.edu.ifsp.sbv.ddic.cadastraclienteintent;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;

import androidx.activity.EdgeToEdge;
import androidx.activity.result.ActivityResult;
import androidx.activity.result.ActivityResultCallback;
import androidx.activity.result.ActivityResultLauncher;
import androidx.activity.result.contract.ActivityResultContracts;
import androidx.appcompat.app.AppCompatActivity;
import androidx.core.graphics.Insets;
import androidx.core.view.ViewCompat;
import androidx.core.view.WindowInsetsCompat;

public class MainActivity extends AppCompatActivity {
    private Button btnNovoCliente;
    private TextView tvNovoCliente;

    ActivityResultLauncher<Intent> mStartForResult = registerForActivityResult(new ActivityResultContracts.StartActivityForResult(),
    new ActivityResultCallback<ActivityResult>() {
        @Override
        public void onActivityResult(ActivityResult result) {
            Bundle params = result.getData() != null ? result.getData().getExtras() : null;

            if (params != null) {
                if (result.getResultCode() == 1) {
                    Cliente cliente = params.getParcelable("cliente");
                    tvNovoCliente.setText("Cliente: " + cliente.getNome() + "\nID: " + cliente.getID() + "\nIdade: "
                    + cliente.getIdade());
                } else {
                    String msg = params.getString("msg");
                    tvNovoCliente.setText(msg);
                }
            }
        }

    });

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        EdgeToEdge.enable(this);
        setContentView(R.layout.activity_main);
        ViewCompat.setOnApplyWindowInsetsListener(findViewById(R.id.main), (v, insets) -> {
            Insets systemBars = insets.getInsets(WindowInsetsCompat.Type.systemBars());
            v.setPadding(systemBars.left, systemBars.top, systemBars.right, systemBars.bottom);
            return insets;
        });

        btnNovoCliente = (Button) findViewById(R.id.btnNovoCliente);
        tvNovoCliente = (TextView) findViewById(R.id.tvNovoCliente);

        btnNovoCliente.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View arg0) {
                Intent it = new Intent(getApplicationContext(), NovoCliente.class);
                mStartForResult .launch(it);
            }
        });
    }
}