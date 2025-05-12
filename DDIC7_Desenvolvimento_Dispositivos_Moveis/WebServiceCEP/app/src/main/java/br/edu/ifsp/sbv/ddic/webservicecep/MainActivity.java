package br.edu.ifsp.sbv.ddic.webservicecep;

import android.app.ProgressDialog;
import android.graphics.Color;
import android.os.AsyncTask;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.Toast;

import androidx.activity.EdgeToEdge;
import androidx.appcompat.app.AppCompatActivity;
import androidx.core.graphics.Insets;
import androidx.core.view.ViewCompat;
import androidx.core.view.WindowInsetsCompat;

import org.json.JSONObject;

import br.edu.ifsp.sbv.ddic.webservicecep.modelo.CEP;

public class MainActivity extends AppCompatActivity {
    private EditText edtCEP;
    private TextView tvResposta;
    private ProgressDialog load;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        edtCEP = (EditText) findViewById(R.id.edtCEP);
        tvResposta = (TextView) findViewById(R.id.tvResposta);
    }

    public void pesquisar(View v) {
        new FetchCEPTask().execute(edtCEP.getText().toString());
    }

    public class FetchCEPTask extends AsyncTask<String, Void, CEP> {
        private static final String TAG = "FetchCEPTask";

        protected void onPreExecute() {
            load = ProgressDialog.show(MainActivity.this, "Por favor, aguarde...",
                    "Procurando dados...");
        }

        @Override
        protected CEP doInBackground(String... params) {
            String cep = params[0];

            if (!cep.matches("^\\d{8}$")) {
                return null;
            }

            String urlString = new String("https://viacep.com.br/ws/" + cep + "/json/");

            try {
                String jsonString = HttpUtils.get(urlString);
                JSONObject jsonObject = new JSONObject(jsonString);
                return new CEP(jsonObject);
            } catch (Exception e) {
                Log.e(TAG, "Erro na requisição: ", e);
                return null;
            }
        }

        @Override
        protected void onPostExecute(CEP cep) {
            String cepDigitado = edtCEP.getText().toString();

            if(cep != null) {
                tvResposta.setText("CEP: " + cep.getCep());
                tvResposta.append("\nLogradouro: " + cep.getLogradouro());
                tvResposta.append("\nBairro: " + cep.getBairro());
                tvResposta.append("\nCidade: " + cep.getCidade());
                tvResposta.append("\nEstado: " + cep.getEstado());
                tvResposta.append("\nUF: " + cep.getUf());
            } else if(!cepDigitado.matches("^\\d{8}$")) {
                Toast.makeText(MainActivity.this,"O CEP precisa ter 8 digitos numéricos!"
                        ,Toast.LENGTH_LONG).show();
                tvResposta.setText("");
            } else {
                Toast.makeText(MainActivity.this,"Nenhum CEP encontrado!",Toast.LENGTH_LONG).show();
                tvResposta.setText("");
            }

            load.dismiss();
        }
    }
}