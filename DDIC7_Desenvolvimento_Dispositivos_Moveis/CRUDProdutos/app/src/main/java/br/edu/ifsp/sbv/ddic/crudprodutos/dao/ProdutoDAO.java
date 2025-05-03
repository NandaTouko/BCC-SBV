package br.edu.ifsp.sbv.ddic.crudprodutos.dao;

import android.content.ContentValues;
import android.content.Context;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.util.Log;

import java.util.ArrayList;
import java.util.List;

import br.edu.ifsp.sbv.ddic.crudprodutos.modelo.Produto;

public class ProdutoDAO extends DAO<Produto> {
    private SQLiteDatabase database;

    public ProdutoDAO(Context context) {
        super(context);
        campos = new String[]{"id","descricao","valor"};
        tableName = "produto";
        database = getWritableDatabase();
    }

    public Produto getByDescricao(String descricao) {
        Produto produto = null;

        Cursor cursor = executeSelect("descricao = ?", new String[]{descricao}, null);

        if(cursor!=null && cursor.moveToFirst()) {
            produto = serializeByCursor(cursor);
        }

        if(!cursor.isClosed()) {
            cursor.close();
        }

        return produto;
    }

    public Produto getByID(Integer id) {
        Produto produto = null;

        Cursor cursor = executeSelect("id = ?", new String[]{String.valueOf(id)}, null);

        if(cursor!=null && cursor.moveToFirst()) {
            produto = serializeByCursor(cursor);
        }

        if(!cursor.isClosed()) {
            cursor.close();
        }

        return produto;
    }

    public List<Produto> listAll() {
        List<Produto> list = new ArrayList<Produto>();
        Cursor cursor = executeSelect(null, null, "1");


        if(cursor!=null && cursor.moveToFirst()) {
            do{
                list.add(serializeByCursor(cursor));
            } while(cursor.moveToNext());
        }

        if(!cursor.isClosed()) {
            cursor.close();
        }

        return list;
    }

    public boolean salvar(Produto produto) {
        Log.d("DEBUG", "Produto a ser salvo: " + produto.getDescricao() + " - Valor: " + produto.getValor());

        ContentValues values = serializeContentValues(produto);
        if(database.insert(tableName, null, values)>0)
            return true;
        else
            return false;
    }

    public boolean deletar(Integer id) {
        if(database.delete(tableName, "id = ?", new String[]{String.valueOf(id)})>0)
            return true;
        else
            return false;
    }

    public boolean atualizar(Produto produto) {
        ContentValues values = serializeContentValues(produto);
        if(database.update(tableName, values, "id = ? ", new String[]{String.valueOf(produto.getID())})>0)
            return true;
        else
            return false;
    }

    private Produto serializeByCursor(Cursor cursor) {
        Produto produto = new Produto();
        produto.setID(cursor.getInt(0));
        produto.setDescricao(cursor.getString(1));
        produto.setValor(cursor.getDouble(2));

        return produto;
    }

    private ContentValues serializeContentValues(Produto produto) {
        ContentValues values = new ContentValues();
        values.put("descricao", produto.getDescricao());
        values.put("valor", produto.getValor());

        return values;
    }

    private Cursor executeSelect(String selection, String[] selectionArgs, String orderBy) {
        return database.query(tableName,campos, selection, selectionArgs, null, null, orderBy);
    }
}
