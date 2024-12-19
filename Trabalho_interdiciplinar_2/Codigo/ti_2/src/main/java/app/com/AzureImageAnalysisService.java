package app.com;

import java.net.URI;
import java.net.http.HttpClient;
import java.net.http.HttpRequest;
import java.net.http.HttpResponse;

public class AzureImageAnalysisService {

    private final HttpClient httpClient;
    private final String subscriptionKey;

    // Construtor
    public AzureImageAnalysisService(String subscriptionKey) {
        this.httpClient = HttpClient.newHttpClient();
        this.subscriptionKey = subscriptionKey; // Chave da API
    }

    /**
     * Método para enviar a imagem para análise
     *
     * @param endpoint O endpoint do serviço Azure
     * @param imageUrl A URL da imagem para análise
     * @return A resposta da API como String
     * @throws Exception Se ocorrer um erro
     */
    public String analyzeImage(String endpoint, String imageUrl) throws Exception {
        // Corpo da requisição em JSON
        String jsonPayload = String.format("{\"url\":\"%s\"}", imageUrl);

        // Cria a requisição HTTP
        HttpRequest request = HttpRequest.newBuilder()
                .uri(URI.create(endpoint))
                .header("Ocp-Apim-Subscription-Key", subscriptionKey) // Cabeçalho da chave
                .header("Content-Type", "application/json") // Tipo do corpo
                .POST(HttpRequest.BodyPublishers.ofString(jsonPayload)) // Corpo da requisição
                .build();

        // Envia a requisição e captura a resposta
        HttpResponse<String> response = httpClient.send(request, HttpResponse.BodyHandlers.ofString());

        // Retorna o corpo da resposta
        return response.body();
    }
}
