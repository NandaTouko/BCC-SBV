package br.edu.ifsp.sbv.ddic.cadastraclienteintent;

import android.os.Parcel;
import android.os.Parcelable;

import androidx.annotation.NonNull;

public class Cliente implements Parcelable {
    private int ID;
    private String nome;
    private int idade;

    public Cliente() {
    }

    public int getID() {
        return ID;
    }

    public void setID(int ID) {
        this.ID = ID;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public int getIdade() {
        return idade;
    }

    public void setIdade(int idade) {
        this.idade = idade;
    }

    protected Cliente(Parcel in) {
        ID = in.readInt();
        nome = in.readString();
        idade = in.readInt();
    }

    public static final Creator<Cliente> CREATOR = new Creator<Cliente>() {
        @Override
        public Cliente createFromParcel(Parcel in) {
            return new Cliente(in);
        }

        @Override
        public Cliente[] newArray(int size) {
            return new Cliente[size];
        }
    };

    @Override
    public int describeContents() {
        return 0;
    }

    @Override
    public void writeToParcel(@NonNull Parcel dest, int flags) {
        dest.writeInt(ID);
        dest.writeString(nome);
        dest.writeInt(idade);
    }
}
