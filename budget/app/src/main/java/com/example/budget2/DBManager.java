package com.example.budget2;

import android.content.ContentValues;
import android.content.Context;
import android.database.Cursor;
import android.database.SQLException;
import android.database.sqlite.SQLiteDatabase;

import java.util.Date;

public class DBManager {

    private DatabaseHelper dbHelper;

    private Context context;

    private SQLiteDatabase database;

    public DBManager(Context c) {
        context = c;
    }

    public DBManager open() throws SQLException {
        dbHelper = new DatabaseHelper(context);
        database = dbHelper.getWritableDatabase();
        return this; //this zwraca obiekt DBManager
    }

    public void close() {
        dbHelper.close();
    }

    public void insert(String kategoria, Integer kwota) {
        ContentValues contentValue = new ContentValues();
        contentValue.put(DatabaseHelper.KATEGORIA, kategoria);
        contentValue.put(DatabaseHelper.KWOTA, kwota);
        database.insert(DatabaseHelper.TABLE_NAME, null, contentValue);
    }

    public Cursor fetch(String wybranyCzas) {
        String[] columns = new String[] { DatabaseHelper.KATEGORIA, "SUM(" + DatabaseHelper.KWOTA + ")" };
        String selection = DatabaseHelper.DATA + ">= date(" + wybranyCzas + ")";
        String groupBy = DatabaseHelper.KATEGORIA;
        Cursor cursor = database.query(DatabaseHelper.TABLE_NAME, columns, selection, null, groupBy, null, null);
        if (cursor != null) {
            cursor.moveToFirst();
        }
        return cursor;
    }

}