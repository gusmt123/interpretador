//inclui bibliotecas usadas no projeto
#include <iostream>
#include <string>


//verifica validade e executa o comando 
bool verifica_validade_comando(const std::string& comando)
{

    // Verifica se o comando contém "printa" e uma das palavras "se" ou "repete"
    if (comando.find("printa") != std::string::npos &&
        (comando.find("se") != std::string::npos || comando.find("repete") != std::string::npos))
    {
        
        
        //verifica se tem o comando tem o tamanho minimo necessário
        if(comando.length() < 16)
        {
            return false;
        }

        //verifica se a primeira palavra do comando é repete ou se
        if(comando.substr(0, 7 ) == "repete " || comando.substr(0,3) == "se ")
        {
            
            //verifica se é se
            if(comando.substr(0,3) == "se ")
            {

                if(comando.substr(9, 6) != "printa")
                {
                    return false;
                }

                //verifica se há um operador lógico na posição correta
                if(comando[5] != '=' && comando[5] != '>' && comando[5] != '<')
                {
                    return false;
                }
                else
                {
                    //verifica se os caracteres inputados  para o if estão entre 0 e 9
                    if(comando[3] > '9' || comando[3] < '0')
                    {
                        return false;
                    }

                    if(comando[7] > '9' || comando[7] < '0')
                    {
                        return false;
                    }

                    //executa lógica if
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

                    
                }
            }

            //se for repete o comando
            else
            {
                //verifica printa na posição certa
                if(comando.substr(9, 6) != "printa")
                {
                    return false;
                }

                //executa o repete
                for(int i = 0; i < comando[7] - '0';i++)
                {
                    std::cout << comando.substr(16) << std::endl;
                }

            }

            return true;
            
        }

    }
        
    return false; // Comando inválido
    
}


//função que inicializa o programa
int main()
{

    
    //armazena o input do usuário 
    std::string comando;
    std::cout << "Segue a sintax" << std::endl;
    std::cout << "repete numero_entre_0_e_9 printa texto" << std::endl;
    std::cout << "se numero_entre_0_e_9 =_ou_>_ou< numero_entre_0_e_9 printa texto " << std::endl;
    std::cout << "Insira um comando:" << std::endl;
    std::getline(std::cin, comando);

    //verifica a válidade do comando
    if(!verifica_validade_comando(comando))
    {
        std::cout << "resposta invalida" << std::endl;
    }

}