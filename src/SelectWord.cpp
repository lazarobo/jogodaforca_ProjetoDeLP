#include "../include/SelectWord.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include <ctime>

bool SelectWord::carregarPalavras(const std::string& caminhoArquivo) {
    std::ifstream arquivo(caminhoArquivo); 
    if (!arquivo.is_open()) {
        std::cerr << "Erro ao abrir o arquivo: " << caminhoArquivo << "\n";
        return false; 
    }

    std::string linha;
    _wordList.clear();
    _hintList.clear();

    while (std::getline(arquivo, linha)) {
        std::stringstream ss(linha);
        std::string palavra, dica;

        if (std::getline(ss, palavra, ',') && std::getline(ss, dica)) {
            _wordList.push_back(palavra);
            _hintList.push_back(dica);
        }
    }

    if (!_wordList.empty()) {
        std::srand(std::time(nullptr)); 
        int i = std::rand() % _wordList.size();
        _wordSelected = _wordList[i];
        _hintSelected = _hintList[i];
    }

    arquivo.close(); 
    return true; 
}

const std::vector<std::string>& SelectWord::getList() const {
    return _wordList;
}

const std::string& SelectWord::getWord() const {
    return _wordSelected;
}


const std::string& SelectWord::getHint() const {
    return _hintSelected;
}
