#include <string>
#include <vector>

class User {
    private:
        struct Book{
            int id;
            int num_pages;
            int read_pages;
            int stars;
        };

        int id;
        std::string name;
        std::string user_name;
        std::string password;
        int qtd_read;
        int qtd_reading;
        int qtd_want_to_read;
        int qtd_abandoned;
        std::vector <Book> library;


    public:
        User(int m_id, 
            std::string m_name,
            std::string m_user_name,
            std::string m_password,
            int m_qtd_read,
            int m_qtd_reading,
            int m_qtd_want_to_read,
            int m_qtd_abandoned
        );

        ~User();  

        int get_id();

        std::string get_name();

        std::string get_user_name();

        std::string get_password();

        int get_qtd_read();

        int get_qtd_reading();

        int get_qtd_want_to_read();

        int get_qtd_abandoned(); 

        void add_book(int id, int num_pages, int read_pages, int stars);  

        int library_size();  
};
