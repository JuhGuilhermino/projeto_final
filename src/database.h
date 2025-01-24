#include <vector>
#include <string>
#include <fstream>
#include "book.h"
#include "user.h"

class Database {
    private:
        std::string books_file = "books.txt";
        std::string users_file = "users.txt";

        std::vector <Book> books;
        std::vector <User> users;

    public:
        /**
         * @brief Realiza a leitura dos dados dos livros, instancia novos objetos do tipo Book e salvo no vetor de livros
         * 
         * @return * void 
         */
        void read_books();

        /**
         * @brief Realiza a leitura dos dados dos usuários, instancia novos objetos do tipo User e salvo no vetor de usuarios
         * 
         * @return * void 
         */
        void read_users();

        
                
};
