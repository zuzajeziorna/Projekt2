package com.example.budget2;

import androidx.appcompat.app.AppCompatActivity;

import android.database.Cursor;
import android.os.Bundle;
import android.view.View;
import android.view.ViewGroup;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Spinner;
import android.widget.TableLayout;
import android.widget.TableRow;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity implements AdapterView.OnItemSelectedListener {

    private EditText kwotaEditText;
    private Spinner kategorieSpinner;
    private Button dodajButton;
    private Spinner okres_czasuSpinner;
    private TableLayout tabela_tablelayout;
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

        okres_czasuSpinner.setOnItemSelectedListener(this);

        tabela_tablelayout = (TableLayout) findViewById(R.id.tabela);
        //TODO:opcjonalnie ustawić  wartość wstępną

        dbManager = new DBManager(this);
        dbManager.open();
    }


    @Override
    public void onItemSelected(AdapterView<?> parent, View view, int position, long id) {
        String doWyswietlenia = "";
        String okresCzasu = okres_czasuSpinner.getSelectedItem().toString();

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

        int count = tabela_tablelayout.getChildCount(); //czyszczenie poprzednich rekordów
        for (int i = 0; i < count; i++) {
            View child = tabela_tablelayout.getChildAt(i);
            if (child instanceof TableRow) ((ViewGroup) child).removeAllViews();
        }

        while (cursor.moveToNext()) {
            String kategoria = cursor.getString(1);
            Integer kwota = cursor.getInt(2);
            String data = cursor.getString(0);

            final TableRow tableRow = new TableRow(this);
            tableRow.setLayoutParams(new TableLayout.LayoutParams(TableLayout.LayoutParams.WRAP_CONTENT, TableLayout.LayoutParams.WRAP_CONTENT));

            // Creation textView
            final TextView data_textview = new TextView(this);
            data_textview.setText(data);
            data_textview.setLayoutParams(new TableRow.LayoutParams(TableRow.LayoutParams.WRAP_CONTENT, TableRow.LayoutParams.WRAP_CONTENT));

            final TextView kategoria_textview = new TextView(this);
            kategoria_textview.setText(kategoria);
            kategoria_textview.setLayoutParams(new TableRow.LayoutParams(TableRow.LayoutParams.WRAP_CONTENT, TableRow.LayoutParams.WRAP_CONTENT));

            final TextView kwota_textview = new TextView(this);
            kwota_textview.setText(kwota.toString());
            kwota_textview.setLayoutParams(new TableRow.LayoutParams(TableRow.LayoutParams.WRAP_CONTENT, TableRow.LayoutParams.WRAP_CONTENT));

            tableRow.addView(data_textview);
            tableRow.addView(kategoria_textview);
            tableRow.addView(kwota_textview);

            tabela_tablelayout.addView(tableRow);

        }

    }

    @Override
    public void onNothingSelected(AdapterView<?> parent) {
        return;
    }
}
