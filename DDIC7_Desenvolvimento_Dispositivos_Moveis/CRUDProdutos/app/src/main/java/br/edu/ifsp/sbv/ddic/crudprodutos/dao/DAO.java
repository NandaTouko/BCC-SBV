package br.edu.ifsp.sbv.ddic.crudprodutos.dao;


import android.content.Context;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteOpenHelper;

public class DAO <T extends Object> extends SQLiteOpenHelper {

    private static final String DATABASE_NAME = "sgcp.sqlite3";
    private static final int DATABASE_VERSION = 1;
    public static final String TABLE_PRODUTO = "produto";

    protected Context context;
    protected String[] campos;
    protected String tableName;

    private static final String CREATE_TABLE_PRODUTO = "CREATE TABLE produto ( "
            + " id integer primary key autoincrement NOT NULL,"
            + " valor double,"
            + " descricao varchar(75));";

    public DAO(Context context) {

        super(context, DATABASE_NAME, null, DATABASE_VERSION);

    }

    @Override
    public void onCreate(SQLiteDatabase database) {
        database.execSQL(CREATE_TABLE_PRODUTO);
    }

    @Override
    public void onUpgrade(SQLiteDatabase db, int oldVersion, int newVersion) {
        db.execSQL(" DROP TABLE IF EXISTS " + TABLE_PRODUTO);
        onCreate(db);
    }

    protected void closeDatabase(SQLiteDatabase db)
    {
        if(db.isOpen())
            db.close();
    }

}


