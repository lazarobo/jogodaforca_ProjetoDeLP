#ifndef FORCA_H
#define FORCA_H

#include <iostream>
#include "../include/SelectWord.h"
#include <set>
#include <string> 
#include <vector>

class Forca
{
private:
    SelectWord _palavraArmazenada;
    std::string _palavraSecreta, _dica;
    int _chancesRestantes;
    std::set<char> _letrasErradas;
    std::set<char> _letrasCertas;

    bool jaFoiChutada(char letra) const;

public:
    Forca(const std::string& caminhoArquivo, int chances);

    bool chute(char letra);
    std::string avanco() const;
    int chancesRestantes() const;

    std::set<char> getLetrasErradas() const;
    std::string palavraCompleta() const;
    std::string getDica() const;

};



#endif
