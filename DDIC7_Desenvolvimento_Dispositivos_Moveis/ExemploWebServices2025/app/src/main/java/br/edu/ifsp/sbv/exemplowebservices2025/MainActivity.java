package br.edu.ifsp.sbv.exemplowebservices2025;

import androidx.appcompat.app.AppCompatActivity;

import android.app.ProgressDialog;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.os.AsyncTask;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.webkit.WebView;
import android.widget.EditText;
import android.widget.ImageView;
import android.widget.TextView;
import android.widget.Toast;

import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.net.HttpURLConnection;
import java.net.URL;

import br.edu.ifsp.sbv.exemplowebservices2025.modelo.Pokemon;


public class MainActivity extends AppCompatActivity {


    private EditText nomePokemon;
    private TextView dadosPokemon;
    private Pokemon pokemon;
    private ImageView imgPoke;
    private ProgressDialog load;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.pokemon);
        nomePokemon = (EditText) findViewById(R.id.edNomePokemon);
        dadosPokemon = (TextView) findViewById(R.id.txtDadosPokemon);
        imgPoke = (ImageView) findViewById(R.id.ivPokemon);
    }

    public void pesquisar(View v) {
        //ps = new PokemonService();
        //ps.execute(nomePokemon.getText().toString());
        new FetchPokemonTask().execute(nomePokemon.getText().toString());
    }

    public class FetchPokemonTask extends AsyncTask<String, Void, Pokemon> {
        private static final String TAG = "FetchPokemonTask";

        protected void onPreExecute() {
            load = ProgressDialog.show(MainActivity.this, "Por favor Aguarde ...",
                    "Procurando Dados ...");
        }

        @Override
        protected Pokemon doInBackground(String... params) {

            String nomePokemonBusca = params[0].toLowerCase();
            String urlString = new String("https://pokeapi.co/api/v2/pokemon/"+nomePokemonBusca);
            try {

                String jsonString = HttpUtils.get(urlString);
                JSONObject jsonObject = new JSONObject(jsonString);
                return new Pokemon(jsonObject);
            } catch (Exception e) {
                Log.e(TAG, "Erro na requisição: ", e);
                return null;
            }
        }

        @Override
        protected void onPostExecute(Pokemon pokemon) {

            if(pokemon !=null)
            {
                Toast.makeText(MainActivity.this,String.valueOf(pokemon.getNome()),Toast.LENGTH_LONG).show();
                dadosPokemon.setText(pokemon.getNome()+"\n"+pokemon.getPeso());
                if(pokemon.getImage()!=null)
                {
                    new DownloadImageTask(imgPoke)
                            .execute(pokemon.getImage());
                }

            }
            else {
                Toast.makeText(MainActivity.this,"Nenhum pokemon encontrado!",Toast.LENGTH_LONG).show();
                dadosPokemon.setText("");
                imgPoke.setImageDrawable(null);
            }



            load.dismiss();
        }
    }

    private class DownloadImageTask extends AsyncTask<String, Void, Bitmap> {
        ImageView bmImage;

        public DownloadImageTask(ImageView bmImage) {
            this.bmImage = bmImage;
        }

        protected Bitmap doInBackground(String... urls) {
            String urldisplay = urls[0];
            Bitmap mIcon11 = null;
            try {
                InputStream in = new URL(urldisplay).openStream();
                mIcon11 = BitmapFactory.decodeStream(in);
            } catch (Exception e) {
                Log.e("Error", e.getMessage());
                e.printStackTrace();
            }
            return mIcon11;
        }

        protected void onPostExecute(Bitmap result) {
            bmImage.setImageBitmap(result);
        }
    }
}