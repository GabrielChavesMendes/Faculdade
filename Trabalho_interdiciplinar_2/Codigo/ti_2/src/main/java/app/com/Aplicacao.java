package app.com;

import java.io.File;
import java.io.IOException;
import java.io.InputStream;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.StandardCopyOption;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Base64;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.stream.Collectors;

import javax.crypto.Cipher;
import javax.crypto.SecretKey;
import javax.crypto.spec.IvParameterSpec;
import javax.servlet.MultipartConfigElement;
import javax.servlet.ServletException;
import javax.servlet.http.Part;

import com.google.gson.Gson;
import com.google.gson.JsonObject;

import dao.FarmaceuticoDAO;
import dao.HospitalDAO;
import dao.LoteDAO;
import dao.MedicosDAO;
import dao.PessoasDAO;
import dao.ProntuarioDAO;
import dao.RemedioDAO;
import model.Farmaceutico;
import model.Hospital;
import model.Lote;
import model.Medico;
import model.PessoaProntuario;
import model.Pessoas;
import model.Prontuario;
import model.Remedio;
import model.RemedioLote;
import spark.Request;
import static spark.Spark.before;
import static spark.Spark.get;
import static spark.Spark.options;
import static spark.Spark.port;
import static spark.Spark.post;
import static spark.Spark.staticFiles;

public class Aplicacao {

    private static final String ALGORITHM = "AES/CBC/PKCS5Padding";

    public static String criptografar(String texto, SecretKey chave, IvParameterSpec iv) throws Exception {
        Cipher cipher = Cipher.getInstance(ALGORITHM);
        cipher.init(Cipher.ENCRYPT_MODE, chave, iv);
        byte[] textoCriptografado = cipher.doFinal(texto.getBytes());
        return Base64.getEncoder().encodeToString(textoCriptografado);
    }

    public static String descriptografar(String textoCriptografado, SecretKey chave, IvParameterSpec iv) throws Exception {
        Cipher cipher = Cipher.getInstance(ALGORITHM);
        cipher.init(Cipher.DECRYPT_MODE, chave, iv);
        byte[] textoDescriptografado = cipher.doFinal(Base64.getDecoder().decode(textoCriptografado));
        return new String(textoDescriptografado);
    }


    private static void logInfo(Request req, Path tempFile) throws IOException, ServletException {
        System.out.println("Uploaded file '" + getFileName(req.raw().getPart("uploaded_file")) + "' saved as '"
                + tempFile.toAbsolutePath() + "'");
    }

    private static String getFileName(Part part) {
        for (String cd : part.getHeader("content-disposition").split(";")) {
            if (cd.trim().startsWith("filename")) {
                return cd.substring(cd.indexOf('=') + 1).trim().replace("\"", "");
            }
        }
        return null;
    }

    // Gson gson = new Gson();

    public static int idHospital;

    @SuppressWarnings("resource")
    public static void main(String[] args) throws Exception {

        String texto = "12345678";
        byte[] chaveBytes = new byte[16]; // 128 bits
        chaveBytes[0] = 1; // Preencher com valor fixo para simulação
        SecretKey chave = new javax.crypto.spec.SecretKeySpec(chaveBytes, "AES");

        // IV fixo
        byte[] ivBytes = new byte[16]; // 128 bits
        ivBytes[0] = 1; // Preencher com valor fixo para simulação
        IvParameterSpec iv = new IvParameterSpec(ivBytes);

        // Criptografar
        String textoCriptografado = criptografar(texto, chave, iv);
        System.out.println("Texto criptografado: " + textoCriptografado);

        // Descriptografar
        String textoDescriptografado = descriptografar(textoCriptografado, chave, iv);
        System.out.println("Texto descriptografado: " + textoDescriptografado);





        File uploadDir = new File("upload");
        uploadDir.mkdir(); // create the upload directory if it doesn't exist

        staticFiles.externalLocation("upload");

        // Conexão com banco de dados para cada DAO correspondente
        FarmaceuticoDAO farmaceuticoDAO = new FarmaceuticoDAO();
        RemedioDAO remedioDAO = new RemedioDAO();
        PessoasDAO pessoasDAO = new PessoasDAO();
        MedicosDAO medicosDAO = new MedicosDAO();
        ProntuarioDAO prontuarioDAO = new ProntuarioDAO();
        HospitalDAO hospitalDAO = new HospitalDAO();
        LoteDAO loteDAO = new LoteDAO();

        // Conectar ao banco de dados
        if (!farmaceuticoDAO.conectar() || !remedioDAO.conectar() || !pessoasDAO.conectar() ||
                !medicosDAO.conectar() || !prontuarioDAO.conectar() || !hospitalDAO.conectar() || !loteDAO.conectar()) {
            System.out.println("Erro ao conectar ao banco de dados.");
            return; // Encerra a aplicação se não conseguir conectar
        }

        // Configuração do Spark
        port(4567); // Porta padrão para o Spark
        // port(8083);
        // Configurações CORS
        before((request, response) -> {
            response.header("Access-Control-Allow-Origin", "*");
            response.header("Access-Control-Allow-Methods", "GET, POST, PUT, DELETE, OPTIONS");
            response.header("Access-Control-Allow-Headers", "Content-Type, Authorization, X-Requested-With");
        });
        before("/*", (request, response) -> {
            request.attribute("org.eclipse.jetty.multipartConfig", new MultipartConfigElement("/temp"));
        });

        // Configuração de OPTIONS para CORS
        options("/*", (request, response) -> {
            String accessControlRequestHeaders = request.headers("Access-Control-Request-Headers");
            if (accessControlRequestHeaders != null) {
                response.header("Access-Control-Allow-Headers", accessControlRequestHeaders);
            }

            String accessControlRequestMethod = request.headers("Access-Control-Request-Method");
            if (accessControlRequestMethod != null) {
                response.header("Access-Control-Allow-Methods", "GET, POST, PUT, DELETE, OPTIONS");
            }

            return "OK";
        });

        ////////////////////////////////////////////////////
        // POST RESPONSAVEL PELO CADASTRO DO FARMACEUTICO //
        ////////////////////////////////////////////////////

        post("/farmaceuticos", (req, res) -> {
            res.type("application/json");
            Farmaceutico farmaceutico = new Gson().fromJson(req.body(), Farmaceutico.class);

            farmaceutico.setSenha(criptografar(farmaceutico.getSenha(), chave, iv));

            farmaceutico.setIdHospital(idHospital);

            farmaceuticoDAO.insert(farmaceutico);
            res.status(201); // Created
            return new Gson().toJson(farmaceutico);
        });

        //////////////////////////////////////////////
        // POST RESPONSAVEL PELO CADASTRO DO MEDICO //
        //////////////////////////////////////////////

        post("/medicos", (req, res) -> {
            Medico medico = new Gson().fromJson(req.body(), Medico.class);

            medico.setIdHospital(idHospital);

            medico.setSenha(criptografar(medico.getSenha(), chave, iv));


            medicosDAO.insert(medico); // Salve o médico no banco de dados
            res.status(201); // Created
            return new Gson().toJson(medico);
        });

        //////////////////////////////////////////
        // POST RESPONSAVEL PELA PARTE DE LOGIN //
        //////////////////////////////////////////

        post("/login", (req, res) -> {
            res.type("application/json");

            // Converte o corpo da requisição JSON para um objeto
            JsonObject loginRequest = new Gson().fromJson(req.body(), JsonObject.class);

            String username = loginRequest.get("crf").getAsString();
            String password = loginRequest.get("senha").getAsString();
            String setor = loginRequest.get("setor").getAsString();
            int id = loginRequest.get("idHospital").getAsInt();

            Hospital hos = hospitalDAO.get(id);
            idHospital = hos.getId();

            System.out.println(id);

            // Verifica o setor para decidir qual DAO usar (Farmacêutico, Médico, Admin, Paciente)
            switch (setor) {
                case "option1" -> {
                    // Busca o farmacêutico no banco de dados

                    System.out.println("entrei no setor option 1");
                    System.out.println(username);
                    System.out.println(password);
                    System.out.println(setor);

                    Farmaceutico farmaceutico = farmaceuticoDAO.get(username);

                    if (farmaceutico == null) {

                        System.out.println("farmaceutico e vazio");
                        // Falha na autenticação
                        res.status(401); // Unauthorized
                        return "{\"message\":\"Usuário ou senha não encontrados no banco de dados.\"}";
                    } else {

                        boolean var = false;
                        Farmaceutico[] farmaceuticos = farmaceuticoDAO.listar();

                        for (Farmaceutico farmaceutico1 : farmaceuticos) {

                            if (farmaceutico1.getCrf().equals(farmaceutico.getCrf())) {
                                var = true;
                            }
                        }
                        if ((var) && descriptografar(farmaceutico.getSenha(), chave, iv).equals(password)) { // verifica a senha e crf

                            if (id == farmaceutico.getIdHospital()) { // verifica o idHospital
                                return new Gson().toJson(farmaceutico); // Autenticado com sucesso
                            } else {
                                // Falha na autenticação
                                res.status(401); // Unauthorized
                                return "{\"message\":\"Usuário não pertence a esse Hospital.\"}";
                            }

                        } else {
                            // Falha na autenticação
                            res.status(401); // Unauthorized
                            return "{\"message\":\"Usuário ou senha inválidos.\"}";
                        }
                    }
                }
                case "option2" -> {
                    Medico medico = medicosDAO.get(username);
                    // Busca o médico no banco de dados

                    if (medico == null) {

                        System.out.println("ta vazio o medioc");
                        // Falha na autenticação
                        res.status(401); // Unauthorized
                        return "{\"message\":\"Usuário ou senha não encontrados no banco de dados.\"}";
                    } else {

                        System.out.println("entrei no setor option 2");
                        System.out.println(username);
                        System.out.println(password);
                        System.out.println(setor);
                        
                        boolean var = false;
                        Medico[] medicos = medicosDAO.listar();
                        for (Medico medico1 : medicos) {
                            if (medico1.getCrm().equals(medico.getCrm())) {
                                var = true;
                            }
                        }

                        if ((var) && descriptografar(medico.getSenha(), chave, iv).equals(password)) { // verifca a senha e o crm

                            if (id == medico.getIdHospital()) { // verifica o idHospital
                                return new Gson().toJson(medico); // Autenticado com sucesso
                            } else {
                                // Falha na autenticação
                                res.status(401); // Unauthorized
                                return "{\"message\":\"Usuário não pertence a esse Hospital.\"}";
                            }

                        } else {
                            // Falha na autenticação
                            res.status(401); // Unauthorized
                            return "{\"message\":\"Usuário ou senha inválidos.\"}";
                        }

                    }
                }
                case "option3" -> {
                    Hospital adm = hospitalDAO.getPorUser(username);
                    // Busca o adm no banco de dados

                    if (adm == null) {

                        System.out.println("ta vazio o adm");
                        // Falha na autenticação
                        res.status(401); // Unauthorized
                        return "{\"message\":\"Usuário ou senha não encontrados no banco de dados.\"}";
                    } else {

                        System.out.println("entrei no setor option 3");
                        System.out.println(username);
                        System.out.println(password);
                        System.out.println(setor);
                        System.out.println("\n" + descriptografar(adm.getSenha(), chave, iv) + "\n");

                        boolean var = false;
                        Hospital[] hospitais = hospitalDAO.listar();
                        for (Hospital hospitai : hospitais) {
                            if (hospitai.getUsuario().equals(adm.getUsuario())) {
                                var = true;

                                
                            }
                        }

                        if ((var) && descriptografar(adm.getSenha(), chave, iv).equals(password)) { // verifica a senha e o usuario de admin

                            if (id == adm.getId()) { // verifica o idHospital
                                return new Gson().toJson(adm); // Autenticado com sucesso
                            } else {
                                // Falha na autenticação
                                res.status(401); // Unauthorized
                                return "{\"message\":\"Usuário não pertence a esse Hospital.\"}";
                            }

                        } else {
                            // Falha na autenticação
                            res.status(401); // Unauthorized
                            return "{\"message\":\"Usuário ou senha inválidos.\"}";
                        }

                    }
                }
                case "option4" -> {
                    Pessoas pessoa = pessoasDAO.get(username);
                    // Busca a pessoa no banco de dados

                    if (pessoa == null) {

                        System.out.println("ta vazio a pessoa");
                        // Falha na autenticação
                        res.status(401); // Unauthorized
                        return "{\"message\":\"Usuário ou senha não encontrados no banco de dados.\"}";
                    } else {

                        System.out.println("entrei no setor option 4");
                        System.out.println(username);
                        System.out.println(password);
                        System.out.println(setor);

                        boolean var = false;
                        Pessoas[] pessoas = pessoasDAO.listar();
                        for (Pessoas pessoa1 : pessoas) {
                            if (pessoa1.getNome().equals(pessoa.getNome())) {
                                var = true;
                            }
                        }

                        if ((var) && descriptografar(pessoa.getSenha(), chave, iv).equals(password)) {
                            // Autenticado com sucesso
                            return new Gson().toJson(pessoa);
                        } else {
                            // Falha na autenticação
                            res.status(401); // Unauthorized
                            return "{\"message\":\"Usuário ou senha inválidos.\"}";
                        }

                    }
                }
                default -> {
                    // Setor inválido
                    res.status(400); // Bad Request
                    return "{\"message\":\"Setor inválido.\"}";
                }
            }
        });

        /////////////////////////////////////////////////////////////////////
        // GET RESPONSAVEL PELA LISTAGEM DE HOSPITAIS DA PAGINA PRINCIPAL //
        /////////////////////////////////////////////////////////////////////

        get("/hospital", (req, res) -> {
            res.type("application/json");
            Hospital[] hospitais = hospitalDAO.listar();

            // Verifica se existem hospitais
            if (hospitais != null) {
                return new Gson().toJson(hospitais);
            } else {
                res.status(404); // Caso não tenha hospitais
                return "{\"message\":\"Nenhum hospital encontrado.\"}";
            }
        });

        //////////////////////////////////////////////////////////////////////////
        // GET RESPONSAVEL PELA LISTAGEM DE REMEDIO DA PAGINA lista-medicamento //
        //////////////////////////////////////////////////////////////////////////

        get("/remedio-lotes", (req, res) -> {
            res.type("application/json");

            System.out.println("entrei aq no remedio lotes = " + idHospital);

            Remedio[] remedios = remedioDAO.listar();

            if (remedios == null) {
                res.status(404); // Caso não tenha remédios
                return "{\"message\":\"Nenhum remédio encontrado.\"}";
            }

            Lote[] lotes = loteDAO.listar();

            if (lotes == null) {
                res.status(404); // Caso não tenha lotes
                return "{\"message\":\"Nenhum lote encontrado.\"}";
            }

            int tamanho = 0;
            for (Lote lote : lotes) {
                if (lote.getIdHospital() == idHospital) {
                    tamanho++;
                }
            }

            RemedioLote[] remediolotes = new RemedioLote[tamanho];
            int k = 0;
            for (int j = 0; j < lotes.length; j++) {
                // Instanciação de cada RemedioLote

                // System.out.println("entrei lotes = " + lotes[j].getIdHospital());

                if (lotes[j].getIdHospital() == idHospital) {

                    remediolotes[k] = new RemedioLote();

                    remediolotes[k].setId(lotes[j].getIdRemedio());
                    remediolotes[k].setCodigo(lotes[j].getCodigo());
                    remediolotes[k].setQuantidade(lotes[j].getQuantidade());
                    remediolotes[k].setDataFabricacao(lotes[j].getDataFabricacao());
                    remediolotes[k].setValidade(lotes[j].getValidade());
                    remediolotes[k].setDosagem(lotes[j].getDosagem());

                    // Atribui o nome do remédio correspondente
                    for (Remedio remedio : remedios) {
                        if (lotes[j].getIdRemedio() == remedio.getId()) {
                            remediolotes[k].setNome(remedio.getNome());
                            break;
                        }
                    }

                    k++;
                }

            }

            // Ordena os RemedioLote com QuickSort
            RemedioLote.quicksort(remediolotes, 0, remediolotes.length - 1);

            // Converte o array para JSON
            String jsonRemedioLotes = new Gson().toJson(remediolotes);
            // System.out.println(jsonRemedioLotes);

            return jsonRemedioLotes; // Retorna a resposta em JSON
        });

        ////////////////////////////////////////////////////
        // GET RESPONSAVEL PELA LISTAGEM DOS MEDICAMENTOS //
        ////////////////////////////////////////////////////

        get("/remedios", (req, res) -> {
            res.type("application/json");

            // Obtenha o termo de pesquisa enviado pelo Select2
            String searchTerm = req.queryParams("term");

            // Obtenha todos os remédios
            Remedio[] todosRemedios = remedioDAO.listar();

            // Verifique se o termo de pesquisa está presente e não está vazio
            List<Remedio> remediosFiltrados;
            if (searchTerm != null && !searchTerm.isEmpty()) {
                // Filtra os remédios com base no termo de pesquisa
                remediosFiltrados = Arrays.stream(todosRemedios)
                        .filter(remedio -> remedio.getNome().toLowerCase().contains(searchTerm.toLowerCase()))
                        .collect(Collectors.toList());
            } else {
                // Se o termo estiver vazio, retorna todos os remédios
                remediosFiltrados = Arrays.asList(todosRemedios);
            }

            if (remediosFiltrados.isEmpty()) {
                res.status(404); // Caso não tenha remédios correspondentes
                return "{\"message\":\"Nenhum remédio encontrado.\"}";
            }

            // Converte a lista filtrada para JSON usando Gson
            String jsonRemedioLotes = new Gson().toJson(remediosFiltrados);
            return jsonRemedioLotes; // Retorna a resposta em JSON
        });

        /////////////////////////////////////////////////////
        // POST RESPONSAVEL PELO CADASTRO DOS MEDICAMENTOS //
        /////////////////////////////////////////////////////

        post("/remedio-cadastro", (req, res) -> {
            res.type("application/json");

            System.out.println("ENTREI NO CADASTRO DE LOTE");
            System.out.println("Dados recebidos: " + req.body()); // Verifique os dados recebidos

            Lote remedio = new Gson().fromJson(req.body(), Lote.class);
            remedio.setIdHospital(idHospital); // Verifique se o idHospital está correto

            System.out.println("Dados recebidos: " + remedio.getIdHospital());

            boolean sucesso = loteDAO.insert(remedio);

            if (sucesso) {
                res.status(201); // Código HTTP para "Criado"
                return "{\"message\":\"Remédio adicionado com sucesso.\"}";
            } else {
                res.status(500); // Código HTTP para "Erro do Servidor"
                return "{\"message\":\"Erro ao adicionar remédio.\"}";
            }
        });

        ///////////////////////////////////////////////////
        // POST RESPONSAVEL PELO UPDATE DOS MEDICAMENTOS //
        ///////////////////////////////////////////////////

        post("/remedio-editar", (req, res) -> {
            res.type("application/json");

            JsonObject loginRequest = new Gson().fromJson(req.body(), JsonObject.class);

            String lote = loginRequest.get("lote").getAsString();
            int quant = loginRequest.get("quant").getAsInt();

            Lote lote1 = loteDAO.getCodigo(lote);

            lote1.setQuantidade(quant + lote1.getQuantidade());

            if (loteDAO.update(lote1)) {
                System.out.println("o lote1 foi editado");
                res.status(200); // OK
                return new Gson().toJson(lote1);
            } else {
                res.status(401); // Unauthorized
                return "{\"message\":\"Falha ao atualizar.\"}";
            }
        });

        ////////////////////////////////////////////////////
        // GET RESPONSAVEL PELO LISTAMENTO DOS PRONTUARIO //
        ////////////////////////////////////////////////////

        get("/prontuarios", (req, res) -> {
            res.type("application/json");
            Prontuario[] prontu = prontuarioDAO.listar();

            if (prontu == null) {
                res.status(404); // Caso não tenha prontuarios
                return "{\"message\":\"Nenhum prontuario encontrado.\"}";
            }

            /* */ Pessoas[] pessoas = pessoasDAO.listar();

            if (pessoas == null) {
                res.status(404); // Caso não tenha pessoas
                return "{\"message\":\"Nenhuma pessoa encontrada.\"}";
            }

            PessoaProntuario[] pessoaProntuarios = new PessoaProntuario[prontu.length];

            Hospital[] hospitais = hospitalDAO.listar();

            for (int j = 0; j < prontu.length; j++) {
                // Instanciação de cada PessoaProntuario
                pessoaProntuarios[j] = new PessoaProntuario();

                pessoaProntuarios[j].setDescricao(prontu[j].getDescricao());
                pessoaProntuarios[j].setDataAtendimento(prontu[j].getDataAtendimento());
                pessoaProntuarios[j].setStatus(prontu[j].getStatus());
                pessoaProntuarios[j].setIdHospital(prontu[j].getIdHospital());

                for (Hospital hospital : hospitais) {
                    if (pessoaProntuarios[j].getIdHospital() == hospital.getId()) {
                        pessoaProntuarios[j].setNomeHospital(hospital.getNome());
                    }
                }

                pessoaProntuarios[j].setMedicoResp(prontu[j].getMedicoResp());

                for (Pessoas pessoa : pessoas) {
                    if (prontu[j].getCpfPaciente().equals(pessoa.getCpf())) {
                        pessoaProntuarios[j].setCpf(pessoa.getCpf());
                        pessoaProntuarios[j].setNome(pessoa.getNome());
                        pessoaProntuarios[j].setAlergia(pessoa.getAlergia());
                        pessoaProntuarios[j].setIdade(pessoa.getIdade());
                        pessoaProntuarios[j].setTipoSanguineo(pessoa.getTipoSanguineo());
                        pessoaProntuarios[j].setPeso(pessoa.getPeso());
                        pessoaProntuarios[j].setAltura(pessoa.getAltura());
                        pessoaProntuarios[j].setSenha(pessoa.getSenha());
                    }
                }
            }
            return new Gson().toJson(pessoaProntuarios);
        });

        ////////////////////////////////////////////////////
        // GET RESPONSAVEL PELO LISTAMENTO DOS PRONTUARIO //
        ////////////////////////////////////////////////////

        post("/prontuarios-get-especifico", (req, res) -> {
            res.type("application/json");

            // Extrai o CPF do request
            JsonObject loginRequest = new Gson().fromJson(req.body(), JsonObject.class);
            String cpf = loginRequest.get("cpf").getAsString();

            System.out.println(cpf + " entrou no get-especifico");

            Prontuario[] prontu = prontuarioDAO.listar();
            if (prontu == null) {
                res.status(404); // Caso não tenha prontuários
                return "{\"message\":\"Nenhum prontuário encontrado.\"}";
            }

            Pessoas[] pessoas = pessoasDAO.listar();
            if (pessoas == null) {
                res.status(404); // Caso não tenha pessoas
                return "{\"message\":\"Nenhuma pessoa encontrada.\"}";
            }

            Hospital[] hospitais = hospitalDAO.listar();

            // Usamos uma lista em vez de um array fixo
            @SuppressWarnings("Convert2Diamond")
            List<PessoaProntuario> pessoaProntuarios = new ArrayList<PessoaProntuario>();

            for (Prontuario prontuario : prontu) {
                // Filtra pelo CPF
                if (cpf.equals(prontuario.getCpfPaciente())) {
                    PessoaProntuario pessoaProntuario = new PessoaProntuario();

                    // Preenche os dados do prontuário
                    pessoaProntuario.setDescricao(prontuario.getDescricao());
                    pessoaProntuario.setDataAtendimento(prontuario.getDataAtendimento());
                    pessoaProntuario.setStatus(prontuario.getStatus());
                    pessoaProntuario.setIdHospital(prontuario.getIdHospital());

                    for (Hospital hospital : hospitais) {
                        if (pessoaProntuario.getIdHospital() == hospital.getId()) {
                            pessoaProntuario.setNomeHospital(hospital.getNome());
                        }
                    }

                    pessoaProntuario.setMedicoResp(prontuario.getMedicoResp());

                    // Preenche os dados da pessoa correspondente
                    for (Pessoas pessoa : pessoas) {
                        if (cpf.equals(pessoa.getCpf())) {
                            pessoaProntuario.setCpf(pessoa.getCpf());
                            pessoaProntuario.setNome(pessoa.getNome());
                            pessoaProntuario.setAlergia(pessoa.getAlergia());
                            pessoaProntuario.setIdade(pessoa.getIdade());
                            pessoaProntuario.setTipoSanguineo(pessoa.getTipoSanguineo());
                            pessoaProntuario.setPeso(pessoa.getPeso());
                            pessoaProntuario.setAltura(pessoa.getAltura());
                            pessoaProntuario.setSenha(pessoa.getSenha());
                            break; // Pessoa encontrada, não precisa continuar buscando
                        }
                    }

                    // Adiciona o prontuário filtrado à lista
                    pessoaProntuarios.add(pessoaProntuario);
                }
            }

            // Converte a lista para JSON
            String jsonPessoas = new Gson().toJson(pessoaProntuarios);
            System.out.println(jsonPessoas);
            return jsonPessoas;
        });

        ////////////////////////////////////////////////////
        // GET RESPONSAVEL PELO LISTAMENTO DOS PRONTUARIO //
        ////////////////////////////////////////////////////

        post("/prontuarios-get", (req, res) -> {
            res.type("application/json");

            JsonObject loginRequest = new Gson().fromJson(req.body(), JsonObject.class);

            String cpf = loginRequest.get("cpf").getAsString();

            System.out.println(cpf);

            Prontuario prontu = prontuarioDAO.get(cpf);

            if (prontu == null) {
                res.status(404); // Caso não tenha prontuarios
                return "{\"message\":\"Nenhum prontuario encontrado.\"}";
            }

            Pessoas pessoa = pessoasDAO.get(cpf);

            if (pessoa == null) {
                res.status(404); // Caso não tenha pessoas
                return "{\"message\":\"Nenhuma pessoa encontrada.\"}";
            }

            PessoaProntuario pessoaProntuarios = new PessoaProntuario();

            pessoaProntuarios.setDescricao(prontu.getDescricao());
            pessoaProntuarios.setDataAtendimento(prontu.getDataAtendimento());
            pessoaProntuarios.setStatus(prontu.getStatus());
            pessoaProntuarios.setIdHospital(prontu.getIdHospital());
            pessoaProntuarios.setMedicoResp(prontu.getMedicoResp());

            pessoaProntuarios.setCpf(pessoa.getCpf());
            pessoaProntuarios.setNome(pessoa.getNome());
            pessoaProntuarios.setAlergia(pessoa.getAlergia());
            pessoaProntuarios.setIdade(pessoa.getIdade());
            pessoaProntuarios.setTipoSanguineo(pessoa.getTipoSanguineo());
            pessoaProntuarios.setPeso(pessoa.getPeso());
            pessoaProntuarios.setAltura(pessoa.getAltura());
            pessoaProntuarios.setSenha(pessoa.getSenha());

            System.out.println("entrei e entreguei pessoa");

            String jsonPessoas = new Gson().toJson(pessoaProntuarios);

            return jsonPessoas;
        });

        //////////////////////////////////////////////////////
        // POST RESPONSAVEL PELO EXCLUIMENTO DOS PRONTUARIO //
        //////////////////////////////////////////////////////

        post("/prontuarios-excluir", (req, res) -> {
            // Obtendo o CPF do corpo da requisição

            JsonObject loginRequest = new Gson().fromJson(req.body(), JsonObject.class);

            String cpf = loginRequest.get("cpf").getAsString();

            // Lógica para excluir o prontuário com o CPF fornecido
            boolean excluido = prontuarioDAO.remove(cpf); // Supondo que você tenha esse método

            if (excluido) {
                res.status(200);
                return "{\"message\":\"Prontuário excluído com sucesso.\"}";
            } else {
                res.status(404);
                return "{\"message\":\"Prontuário não encontrado.\"}";
            }
        });

        /////////////////////////////////////////////////
        // POST RESPONSAVEL PELO EDIÇÃO DOS PRONTUARIO //
        /////////////////////////////////////////////////

        post("/prontuarios-editar", (req, res) -> {

            JsonObject loginRequest = new Gson().fromJson(req.body(), JsonObject.class);

            String cpf = loginRequest.get("cpf").getAsString();
            String medico = loginRequest.get("medico").getAsString();
            String dataInternacao = loginRequest.get("dataInternacao").getAsString();
            String status = loginRequest.get("status").getAsString();
            String descricao = loginRequest.get("descricao").getAsString();

            Prontuario prontuario = new Prontuario();

            prontuario.setMedicoResp(medico);
            prontuario.setDataAtendimento(dataInternacao);
            prontuario.setIdHospital(idHospital);
            prontuario.setCpfPaciente(cpf);
            prontuario.setDescricao(descricao);
            prontuario.setStatus(status);

            if (prontuarioDAO.update(prontuario)) {
                System.out.println("O prontuario foi atualizado!");
                res.status(200); // OK
                return new Gson().toJson(prontuario);
            } else {
                res.status(401); // Unauthorized
                return "{\"message\":\"Falha ao Atualizar.\"}";
            }
        });

        ///////////////////////////////////////////////////
        // POST RESPONSAVEL PELO CADASTRO DOS PRONTUARIO //
        ///////////////////////////////////////////////////

        post("/cadastrar-prontuario", (req, res) -> {
            res.type("application/json");

            // System.out.println("ENTREI NA BAGAcA DO PRONTUARIO");

            JsonObject loginRequest = new Gson().fromJson(req.body(), JsonObject.class);

            String CPF = loginRequest.get("CPF").getAsString();
            String medico = loginRequest.get("medico").getAsString();
            String dataInternacao = loginRequest.get("dataInternacao").getAsString();
            String status = loginRequest.get("status").getAsString();
            String descricao = loginRequest.get("descricao").getAsString();

            Prontuario prontuario = new Prontuario();
            Pessoas[] pessoas = pessoasDAO.listar();

            prontuario.setMedicoResp(medico);
            prontuario.setDataAtendimento(dataInternacao);
            prontuario.setIdHospital(idHospital);
            prontuario.setCpfPaciente(CPF);
            prontuario.setDescricao(descricao);
            prontuario.setStatus(status);
            prontuario.setIdHospital(idHospital);

            for (Pessoas pessoa : pessoas) {
                if (pessoa.getCpf().equals(prontuario.getCpfPaciente())) {
                    if (prontuarioDAO.insert(prontuario)) {
                        System.out.println("O prontuario foi inserido!");
                        res.status(200); // OK
                        return new Gson().toJson(prontuario);
                    } else {
                        res.status(401); // Unauthorized
                        return "{\"message\":\"Falha ao Inserir.\"}";
                    }
                }
            }

            res.status(400); // Bad Request
            return "{\"message\":\"O Cpf Digitado não se encontra no banco de dados!\"}";
        });

        post("/receita-upload", (req, res) -> {
            try {
                // Configuração do Azure Blob Storage
                String connectionString = "DefaultEndpointsProtocol=https;AccountName=medlogimg;AccountKey=erZODcqmAiqQzliWUfGJ66S/Pg2y8NVNuo3NYlebVmqDVQMaPwaFoSpEsKyeGZIiUC/3ws3bOflW+ASt1lS0ag==;EndpointSuffix=core.windows.net"; // Substitua
                                                                                                                                                                                                                                      // pela
                                                                                                                                                                                                                                      // sua
                                                                                                                                                                                                                                      // Connection
                                                                                                                                                                                                                                      // String
                String containerName = "medlogimg"; // Substitua pelo nome do container

                // Inicializa o serviço AzureBlobService
                AzureBlobService azureBlobService = new AzureBlobService(connectionString, containerName);

                String subscriptionKey = "0b0643998822416db138e16bf1dba758";
                String endpoint = "https://medlog.cognitiveservices.azure.com/computervision/imageanalysis:analyze?features=read&model-version=latest&language=en&api-version=2024-02-01";
                AzureImageAnalysisService analysisService = new AzureImageAnalysisService(subscriptionKey);

                // Obtém o arquivo enviado
                Part filePart = req.raw().getPart("uploaded_file");
                String originalFileName = filePart.getSubmittedFileName(); // Nome original do arquivo enviado
                String fileExtension = "";

                // Extrair a extensão do arquivo
                int i = originalFileName.lastIndexOf('.');
                if (i > 0) {
                    fileExtension = originalFileName.substring(i); // Pega a extensão, incluindo o ponto (e.g., ".jpg")
                }

                // Criar um arquivo temporário com a extensão
                Path tempFile = Files.createTempFile(uploadDir.toPath(), "", fileExtension);

                // Copiar o conteúdo do arquivo enviado para o arquivo temporário
                try (InputStream input = filePart.getInputStream()) {
                    Files.copy(input, tempFile, StandardCopyOption.REPLACE_EXISTING);
                }

                // Faça o upload do arquivo para o Azure Blob Storage
                try (InputStream input = Files.newInputStream(tempFile)) {
                    Gson gson = new Gson();
                    String blobUrl = azureBlobService.uploadFile(input, originalFileName, Files.size(tempFile));

                    String responseFromAnalysis = analysisService.analyzeImage(endpoint, blobUrl);

                    AnalysisResult analysisResult = gson.fromJson(responseFromAnalysis, AnalysisResult.class);

                    String formattedText = analysisResult.formatToSingleWord();

                    Map<String, Object> responseMap = new HashMap<>();
                    responseMap.put("file_url", blobUrl);
                    responseMap.put("text", formattedText);
                    responseMap.put("formatted_text", formattedText);
                    responseMap.put("analysis", gson.fromJson(responseFromAnalysis, Object.class));

                    System.out.println("Api de receitas respondeu");

                    res.type("application/json");
                    return gson.toJson(responseMap);
                }
            } catch (Exception e) {
                res.status(500);
                return "Error: " + e.getMessage();
            }

        });

        ////////////////////////////////////////////////
        // POST RESPONSAVEL PELO CADASTRO DAS PESSOAS //
        ////////////////////////////////////////////////

        post("/cadastrar-pessoa", (req, res) -> {
            res.type("application/json");

            // System.out.println("ENTREI NA BAGAcA DA PESSOA");

            JsonObject loginRequest = new Gson().fromJson(req.body(), JsonObject.class);

            String nome = loginRequest.get("nome").getAsString();
            String CPF = loginRequest.get("cpf").getAsString();
            int tipoSanguineo = loginRequest.get("tipoSanguineo").getAsInt();
            int idade = loginRequest.get("idade").getAsInt();
            String alergia = loginRequest.get("alergia").getAsString();
            double peso = loginRequest.get("peso").getAsDouble();
            int altura = loginRequest.get("altura").getAsInt();
            String senha = loginRequest.get("senha").getAsString();

            String textocripto = criptografar ( senha , chave , iv );

            Pessoas pessoa = new Pessoas();

            pessoa.setCpf(CPF);
            pessoa.setNome(nome);
            pessoa.setTipoSanguineo(tipoSanguineo);
            pessoa.setAlergia(alergia);
            pessoa.setIdade(idade);
            pessoa.setPeso(peso);
            pessoa.setAltura(altura);
            pessoa.setSenha(textocripto);

            if (pessoasDAO.insert(pessoa)) {
                System.out.println("a pessoa foi inserida!");
                res.status(200); // OK
                return new Gson().toJson(pessoa);
            } else {
                res.status(401); // Unauthorized
                return "{\"message\":\"Falha ao atualizar.\"}";
            }
        });

    }
}
