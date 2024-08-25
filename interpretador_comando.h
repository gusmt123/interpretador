#include <string>
#include <vector>

class interpretador_comando
{
    private:
        std::string nome_arquivo;

    public:
        interpretador_comando(const std::string& comando);
        void processaComando();
        void interpreta_Comando(const std::string& linha);

};