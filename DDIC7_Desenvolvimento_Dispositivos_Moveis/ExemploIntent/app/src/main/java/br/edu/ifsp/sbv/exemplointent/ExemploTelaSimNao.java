package br.edu.ifsp.sbv.exemplointent;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;

public class ExemploTelaSimNao extends Activity {

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.tela_sim_nao);

		// Sim
		Button sim = (Button) findViewById(R.id.btSim);
		sim.setText("Sim");
		sim.setOnClickListener(new View.OnClickListener() {

			@Override
			public void onClick(View arg0) {
				Intent it = new Intent();
				it.putExtra("msg", "Clicou em sim!");
				setResult(1, it);
				finish();

			}
		});

		// Não
		Button nao = (Button) findViewById(R.id.btNao);
		nao.setText("Não");
		nao.setOnClickListener(new View.OnClickListener() {

			@Override
			public void onClick(View arg0) {
				Intent it = new Intent();
				it.putExtra("msg", "Clicou em não!");
				setResult(2, it);
				finish();

			}
		});

	}

	@Override
	public void onBackPressed() {
		Intent it = new Intent();
		it.putExtra("msg", "Clicou em voltar!");
		setResult(3, it);
		finish();
	}
}
