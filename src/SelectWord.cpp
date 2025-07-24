#include "../include/SelectWord.h"
#include <iostream>
//#include <sstream>
#include <fstream>
#include <cstdlib>
#include <ctime>

bool SelectWord::carregarPalavras(const std::string& caminhoArquivo) {
    std::ifstream arquivo(caminhoArquivo); 
    if (!arquivo.is_open()) {
        std::cerr << "erro ao abrir o arquivo: " << caminhoArquivo << "\n";
        return false; 
    }

    std::string palavra;
    _wordList.clear();

    while (std::getline(arquivo, palavra)) {
        _wordList.push_back(palavra);
    }

    if (!_wordList.empty()) { //se há algum valor na lista
        std::srand(std::time(nullptr)); 
        int i = std::rand() % _wordList.size();
        _wordSelected = _wordList[i];
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