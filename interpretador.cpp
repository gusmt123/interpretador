//inclui bibliotecas usadas no projeto
#include <iostream>
#include <string>

bool verifica_validade_comando(const std::string& comando)
{
    // Verifica se o comando contém "printa" e uma das palavras "se" ou "repete"
    if (comando.find("printa") != std::string::npos &&
        (comando.find("se") != std::string::npos || comando.find("repete") != std::string::npos))
    {
        
        

        if(comando.length() < 16)
        {
            return false;
        }
        if(comando.substr(0, 7 ) == "repete " || comando.substr(0,3) == "se ")
        {
            if(comando.substr(0,3) == "se ")
            {
                if(comando[5] != '=' && comando[5] != '>' && comando[5] != '<')
                {
                    return false;
                }
                else
                {

                    if(comando[3] > '9' || comando[3] < '0')
                    {
                        return false;
                    }

                    if(comando[7] > '9' || comando[7] < '0')
                    {
                        return false;
                    }

                    switch(comando[5])
                    {

                        case '=':
                            if(comando[3] == comando[7])
                            {
                                std::cout << comando.substr(16);
                            }
                        break;

                        case '>':
                            if(comando[3] > comando[7])
                            {
                                std::cout << comando.substr(16);
                            }
                        break;

                        case '<':
                            if(comando[3] < comando[7])
                            {
                                std::cout << comando.substr(16);
                            }
                        break;

                    }

                    return true;
                }
            }
            
        }

    }
        
    return false; // Comando inválido
    
}

int main()
{

    std::string comando;
    std::cout << "Insira um comando:" << std::endl;
    std::getline(std::cin, comando);

    if(verifica_validade_comando(comando))
    {

    }
    else
    {
        std::cout << "resposta invalida" << std::endl;
    }

}