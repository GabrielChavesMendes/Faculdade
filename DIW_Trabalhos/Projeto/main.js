// Função para gerar o HTML de cada álbum
function gerarCardAlbum(album) {
    return `
        <div class="col-md-3 mt-2">
            <div class="card">
                <img src="${album.url_capa}" alt="${album.titulo}" border="0" class="card-img-top" height="200">
                <div class="card-body">
                    <h5 class="card-title">${album.titulo}</h5>
                    <p class="card-text">${album.descricao}</p>
                    <a href="álbum.html" class="btn btn-primary">Detalhes</a>
                </div>
            </div>
        </div>
    `;
}

// Função para popular o container de álbuns com os cards
function popularContainerDeAlbuns(data) {
    var albumsContainer = document.getElementById('albumsContainer');
    var albumsHTML = '';

    data.albuns.forEach(function (album) {
        albumsHTML += gerarCardAlbum(album);
    });

    albumsContainer.innerHTML = albumsHTML;
}

// Carregar o JSON e chamar a função para popular o container de álbuns
document.addEventListener('DOMContentLoaded', function () {
    fetch('albums.json')
        .then(response => response.json())
        .then(data => popularContainerDeAlbuns(data))
        .catch(error => console.error('Erro ao carregar JSON:', error));
});
