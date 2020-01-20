package com.example.budget2;

import androidx.appcompat.app.AppCompatActivity;

import android.database.Cursor;
import android.os.Bundle;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Spinner;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {

    private EditText kwotaEditText;
    private Spinner kategorieSpinner;
    private Button dodajButton;
    private Spinner okres_czasuSpinner;
    private TextView helloTextView;
    private DBManager dbManager;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        kwotaEditText = (EditText) findViewById(R.id.kwota);
        dodajButton = (Button) findViewById(R.id.button_dodaj);
        dodajButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                String kwotaString = kwotaEditText.getText().toString();
                Integer kwota = Integer.parseInt(kwotaString);

                String kategoria = kategorieSpinner.getSelectedItem().toString();
                dbManager.insert(kategoria, kwota);
            }
        });

         kategorieSpinner = (Spinner) findViewById(R.id.kategorie_spinner);
// Create an ArrayAdapter using the string array and a default kategorieSpinner layout
        ArrayAdapter<CharSequence> adapter = ArrayAdapter.createFromResource(this,
                R.array.kategorie, android.R.layout.simple_spinner_item);
// Specify the layout to use when the list of choices appears
        adapter.setDropDownViewResource(android.R.layout.simple_spinner_dropdown_item);
// Apply the adapter to the kategorieSpinner
        kategorieSpinner.setAdapter(adapter);


        okres_czasuSpinner = (Spinner) findViewById(R.id.okres_czasu_spinner);
// Create an ArrayAdapter using the string array and a default kategorieSpinner layout
        ArrayAdapter<CharSequence> adapter2 = ArrayAdapter.createFromResource(this,
                R.array.okres_czasu, android.R.layout.simple_spinner_item);
// Specify the layout to use when the list of choices appears
        adapter2.setDropDownViewResource(android.R.layout.simple_spinner_dropdown_item);
// Apply the adapter to the kategorieSpinner
        okres_czasuSpinner.setAdapter(adapter2);

        okres_czasuSpinner.setOnItemSelectedListener(new AdapterView.OnItemSelectedListener(){
            @Override
            public void onItemSelected(AdapterView<?> parent, View view, int position, long id) {
                String doWyswietlenia = "";
                String okresCzasu = okres_czasuSpinner.getSelectedItem().toString();
                doWyswietlenia += okresCzasu + "\n";
                Cursor cursor;
                switch (okresCzasu){
                    case "tygodnia":
                        cursor = dbManager.fetch("'now', '-7 day'");
                        break;
                    case "miesiąca":
                        cursor = dbManager.fetch("'now', '-1 month'");
                        break;
                    default:
                        cursor = dbManager.fetch("'now'");
                }
                while (cursor.moveToNext()) {
                    String kategoria = cursor.getString(0);
                    Integer kwota = cursor.getInt(1);
                    doWyswietlenia += kategoria + ": " + kwota + "\n";
                }
                helloTextView.setText(doWyswietlenia);

            }

            @Override
            public void onNothingSelected(AdapterView<?> parent) {
                return;
            }
        });

        helloTextView = (TextView) findViewById(R.id.wypisywanie_danych);
        helloTextView.setText("Dane");

        dbManager = new DBManager(this);
        dbManager.open();
    }


}
