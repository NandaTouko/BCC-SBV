package br.edu.ifsp.sbv.ddic.dialogalertcores;

import android.graphics.Color;
import android.os.Bundle;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.Spinner;

import androidx.activity.EdgeToEdge;
import androidx.appcompat.app.AlertDialog;
import androidx.appcompat.app.AppCompatActivity;

public class MainActivity extends AppCompatActivity {
    private View mainLayout;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        EdgeToEdge.enable(this);
        setContentView(R.layout.activity_main);

        mainLayout = (View) findViewById(R.id.main);
    }

    public void showColorDialog(View v) {
        AlertDialog.Builder builder = new AlertDialog.Builder(this);
        builder.setTitle("Selecione uma cor de fundo");

        Spinner colorSpinner = new Spinner(this);
        colorSpinner.setPadding(50,50,50,50);
        String[] colors = {"Branco", "Creme", "Coral", "Verde"};

        ArrayAdapter<String> adapter = new ArrayAdapter<>(this, android.R.layout.simple_spinner_dropdown_item, colors);
        colorSpinner.setAdapter(adapter);

        colorSpinner.setOnItemSelectedListener(new AdapterView.OnItemSelectedListener() {
            @Override
            public void onItemSelected(AdapterView<?> parent, View view, int position, long id) {
                switch (position) {
                    case 0:
                        mainLayout.setBackgroundColor(Color.WHITE);
                        break;
                    case 1:
                        mainLayout.setBackgroundColor(Color.parseColor("#fffdd0"));
                        break;
                    case 2:
                        mainLayout.setBackgroundColor(Color.parseColor("#ff7f50"));
                        break;
                    case 3:
                        mainLayout.setBackgroundColor(Color.parseColor("#abf400"));
                        break;
                }
            }

            @Override
            public void onNothingSelected(AdapterView<?> parent) {
            }
        });

        builder.setView(colorSpinner);
        builder.setPositiveButton("OK", (dialog, which) -> dialog.dismiss());

        AlertDialog dialog = builder.create();
        dialog.show();
    }
}