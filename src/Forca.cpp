#include "../include/Forca.h"

Forca::Forca(const std::string& caminhoArquivo, int chances){
    _palavraArmazenada.carregarPalavras(caminhoArquivo);
    _palavraSecreta = _palavraArmazenada.getWord();
    _dica = _palavraArmazenada.getHint();
    _chancesRestantes = chances;
}

bool Forca::jaFoiChutada(char letra) const {
    for (char l : _letrasCertas) {
        if (l == letra) return true;
    }
    for (char l : _letrasErradas) {
        if (l == letra) return true;
    }
    return false;
}

bool Forca::chute(char letra) {

    if (!std::isalpha(letra)) {
        std::cout << "Por favor, digite uma letra.\n";
        std::cout << "----------------------------------------------\n";
        return false;
    }

    letra = std::tolower(letra);

    if (jaFoiChutada(letra)) {
        std::cout << "----------------------------------------------\n";
        std::cout << "Essa letra já foi chutada, tente outra vez!\n";
        std::cout << "----------------------------------------------\n";
        return false;
    }

    bool acertou = false;
    for (char l : _palavraSecreta) {
        if (l == letra) {
            acertou = true;
            break;
        }
    }

    if (acertou) {
        _letrasCertas.insert(letra); //insert para o set
        std::cout << "A letra '" << letra << "' está na palavra! Chances restantes: "<< _chancesRestantes << "\n";
        std::cout << "----------------------------------------------\n";
    } else {
        _letrasErradas.insert(letra);
        _chancesRestantes--;
        std::cout << "A letra '" << letra << "' não está na palavra. Chances restantes: " << _chancesRestantes << "\n";
        std::cout << "----------------------------------------------\n";
    }

    return acertou;
}

std::string Forca::avanco() const {
    std::string palavraAvancada;
    for (char l : _palavraSecreta) {
        if (_letrasCertas.count(l) > 0) {
            palavraAvancada += l;
        } else {
            palavraAvancada += '_';
        }
        palavraAvancada += ' ';
    }
    std::cout << "Progresso atual: " << palavraAvancada << "\n";
    return palavraAvancada;
}


int Forca::chancesRestantes() const {
    std::cout << "Chances restantes: " << _chancesRestantes << "\n";
    return _chancesRestantes;
}

std::set<char> Forca::getLetrasErradas() const {
    std::cout << "Letras erradas chutadas: ";
    for (char l : _letrasErradas) {
        std::cout << l << " ";
    }
    std::cout << "\n";
    return _letrasErradas;
}

std::string Forca::palavraCompleta() const {
    return _palavraSecreta;
}

std::string Forca::getDica() const{
    return _dica;
}