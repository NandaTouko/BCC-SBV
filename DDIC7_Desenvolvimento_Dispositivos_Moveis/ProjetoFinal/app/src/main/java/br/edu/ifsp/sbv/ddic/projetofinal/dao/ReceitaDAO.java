package br.edu.ifsp.sbv.ddic.projetofinal.dao;

import android.content.*;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;

import java.util.*;

import br.edu.ifsp.sbv.ddic.projetofinal.modelo.Receita;

public class ReceitaDAO extends DAO<Receita> {

    public ReceitaDAO(Context context) {
        super(context);
    }

    public boolean salvar(Receita receita) {
        if (existe(receita.getId())) return false;

        SQLiteDatabase db = getWritableDatabase();
        ContentValues values = new ContentValues();
        values.put("id", receita.getId());
        values.put("nome", receita.getNome());
        values.put("modo_preparo", receita.getModoPreparo());
        values.put("imagem", receita.getImagem());
        values.put("categoria", receita.getCategoria());

        long resultado = db.insert(TABLE_RECEITAS, null, values);
        db.close();

        return resultado != -1;
    }

    public boolean existe(String id) {
        SQLiteDatabase db = getReadableDatabase();
        Cursor cursor = db.rawQuery("SELECT id FROM receitas WHERE id = ?", new String[]{id});
        boolean existe = cursor.moveToFirst();
        cursor.close();
        db.close();
        return existe;
    }

    public List<Receita> listAll() {
        List<Receita> lista = new ArrayList<>();
        SQLiteDatabase db = getReadableDatabase();
        Cursor cursor = db.rawQuery("SELECT * FROM receitas", null);

        while (cursor.moveToNext()) {
            Receita r = new Receita();
            r.setId(cursor.getString(cursor.getColumnIndexOrThrow("id")));
            r.setNome(cursor.getString(cursor.getColumnIndexOrThrow("nome")));
            r.setModoPreparo(cursor.getString(cursor.getColumnIndexOrThrow("modo_preparo")));
            r.setImagem(cursor.getString(cursor.getColumnIndexOrThrow("imagem")));
            r.setCategoria(cursor.getString(cursor.getColumnIndexOrThrow("categoria")));
            lista.add(r);
        }

        cursor.close();
        db.close();
        return lista;
    }
}
