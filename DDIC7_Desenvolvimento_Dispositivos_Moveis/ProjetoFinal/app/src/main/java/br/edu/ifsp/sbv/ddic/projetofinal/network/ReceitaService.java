package br.edu.ifsp.sbv.ddic.projetofinal.network;

import br.edu.ifsp.sbv.ddic.projetofinal.network.ReceitaResponse;
import retrofit2.Call;
import retrofit2.http.GET;
import retrofit2.http.Query;

public interface ReceitaService {
    @GET("search.php")
    Call<ReceitaResponse> buscarReceitas(@Query("s") String termo);
}
