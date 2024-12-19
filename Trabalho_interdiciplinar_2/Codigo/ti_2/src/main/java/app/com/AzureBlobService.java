package app.com;

import com.azure.storage.blob.*;
import com.azure.storage.blob.models.*;
import com.azure.storage.blob.BlobServiceClient;
import com.azure.storage.blob.BlobServiceClientBuilder;
import com.azure.storage.blob.BlobContainerClient;

import java.io.InputStream;

public class AzureBlobService {

    private final BlobContainerClient containerClient;

    // Construtor: inicializa o cliente do Azure Blob Storage
    public AzureBlobService(String connectionString, String containerName) {
        BlobServiceClient blobServiceClient = new BlobServiceClientBuilder()
                .connectionString(connectionString)
                .buildClient();
        this.containerClient = blobServiceClient.getBlobContainerClient(containerName); // Corrigido aqui
    }

    // Método para fazer upload de arquivo
    public String uploadFile(InputStream inputStream, String fileName, long fileSize) {
        try {
            // Cria o cliente para o arquivo (blob)
            BlobClient blobClient = containerClient.getBlobClient(fileName);

            // Faz o upload do arquivo
            blobClient.upload(inputStream, fileSize, true);

            // Retorna a URL do arquivo no Azure Blob Storage
            return blobClient.getBlobUrl();
        } catch (Exception e) {
            throw new RuntimeException("Erro ao fazer upload do arquivo: " + e.getMessage(), e);
        }
    }

    // Método para recuperar a URL de um arquivo no Azure Blob Storage
    public String findFile(String fileName) {
        try {
            // Cria o cliente para o arquivo (blob)
            BlobClient blobClient = containerClient.getBlobClient(fileName);

            // Verifica se o arquivo existe
            if (blobClient.exists()) {
                return blobClient.getBlobUrl();
            } else {
                throw new RuntimeException("Arquivo não encontrado: " + fileName);
            }
        } catch (Exception e) {
            throw new RuntimeException("Erro ao recuperar arquivo: " + e.getMessage(), e);
        }
    }
}