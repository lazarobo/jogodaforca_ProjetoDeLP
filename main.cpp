#include "../include/SelectWord.h"
#include "../include/Forca.h"
#include <iostream>
#include <cstdlib> 

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << argv[0] << " <caminho_para_arquivo> <chances>\n";
        return 1;
    }

    std::string caminho = argv[1];
    int chances = std::stoi(argv[2]);

    if (chances <= 0) {
        std::cout << "O número de tentativas deve ser maior que zero!\n";
        return 1;
        }

    Forca jogo(caminho, chances);

    std::cout << "----------------------------------------------\n";
    std::cout << "JOGO DA FORCA\n";
    std::cout << "----------------------------------------------\n";
    
    while (jogo.chancesRestantes() > 0)
    {
        std::string progresso = jogo.avanco();

        bool venceu = true;

        for (char l : progresso) {
            if (l == '_') {
                venceu = false;
                break;
            }
        }

        if (venceu == true) {
            std::cout << "Parabéns, você venceu!! A palavra era: " << progresso << "\n";
            break;
        } 

        std::string entrada;
        std::cout << "Digite uma letra: ";
        std::cout << "----------------------------------------------\n";
        std::getline(std::cin, entrada);

        system("clear");

        if (entrada.length() == 1) {
            jogo.chute(entrada[0]);
        } else {
            std::cout << "Entrada inválida. Digite apenas UMA letra.\n";
            std::cout << "----------------------------------------------\n";
        }


        jogo.getLetrasErradas();

        if (jogo.chancesRestantes() == 0) {
            std::cout << R"(  
                _______
                |/      |
                |      (_)
                |      \|/
                |       |
                |      / \
                |
                _|___

                DERROTA! Você perdeu."\n";
                )";
            std::cout << "A palavra era: " << jogo.palavraCompleta() << "\n";

            break;
        }
    }

    std::cout << "Pressione Enter para sair...";
    //std::cin.ignore(); 
    std::cin.get();  

    

    return 0;
}
