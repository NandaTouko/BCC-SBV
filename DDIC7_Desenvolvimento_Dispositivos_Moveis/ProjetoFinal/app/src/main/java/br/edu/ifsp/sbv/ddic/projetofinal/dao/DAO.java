package br.edu.ifsp.sbv.ddic.projetofinal.dao;

import android.content.Context;
import android.database.sqlite.*;

public class DAO<T> extends SQLiteOpenHelper {

    private static final String DATABASE_NAME = "receitas.sqlite3";
    private static final int DATABASE_VERSION = 1;

    public static final String TABLE_RECEITAS = "receitas";

    private static final String CREATE_TABLE_RECEITAS = "CREATE TABLE receitas ("
            + "id TEXT PRIMARY KEY, "
            + "nome TEXT, "
            + "modo_preparo TEXT, "
            + "imagem TEXT, "
            + "categoria TEXT);";

    public DAO(Context context) {
        super(context, DATABASE_NAME, null, DATABASE_VERSION);
    }

    @Override
    public void onCreate(SQLiteDatabase db) {
        db.execSQL(CREATE_TABLE_RECEITAS);
    }

    @Override
    public void onUpgrade(SQLiteDatabase db, int oldVersion, int newVersion) {
        db.execSQL("DROP TABLE IF EXISTS " + TABLE_RECEITAS);
        onCreate(db);
    }
}
