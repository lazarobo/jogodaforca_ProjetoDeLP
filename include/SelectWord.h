#ifndef SELECTWORD_H
#define SELECTWORD_H

#include <string>
#include <vector>
#include <iostream>

class SelectWord
{
protected:

    std::vector<std::string> _wordList;
    std::string _wordSelected;

public:
    bool carregarPalavras(const std::string& caminhoArquivo);
    const std::string& getWord() const; 
    const std::vector<std::string>& getList() const;
};




#endif