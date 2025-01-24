#include <vector>
#include <string>
#include <iostream>
#include "book.h"
#include "user.h"

class Database {
    private:
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

        Book get_book(int id);

        User get_user(int id);

        int search_user(std::string username);

        bool valid_password(int user_id, std::string password);

        void add_user(std::string name, std::string username, std::string password);
     
};
