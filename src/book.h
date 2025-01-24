/**
 * @file book.h
 * @author Júlia Guilhermino (juh.guilhermino03@gmail.com.com)
 * @brief .
 * @version 0.1
 * @date 2025-01-23
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include <vector>
#include <string>

class Book {
    private:
        int id;                           //< Número de identificação
        std::string title;                //< Título do livro
        std::string author;               //< Autor(a) do livro
        std:: string  publishing_company; //< Editora do livro
        int edition_year;                 //< Ano dessa edição do livro
        int num_pages;                    //< Nº de páginas
        float stars;                      //< Média da avaliação dos leitores
        int qtd_read;                     //< Nº de leitores que salvaram como "lido"
        int qtd_reading;                  //< Nº de leitores que salvaram como "lendo"
        int qtd_want_to_read;             //< Nº de leitores que salvaram como "quero ler"
        int qtd_abandoned;                //< Nº de leitores que salvaram como "abandonado"
        
    public:
        Book(int m_id, 
             std::string m_title, 
             std::string m_author,
             std::string m_publishing_company,
             int m_edition_year,
             int m_num_pages,
             float m_stars,
             int m_qtd_read,
             int m_qtd_reading,
             int m_qtd_want_to_read,
             int m_qtd_abandoned);

        ~Book();

        int get_id();

        std::string get_title();

        std::string get_author();

        std::string get_publishing_company();

        int get_edition_year();

        int get_num_pages();

        int get_stars();

        int get_qtd_read();

        int get_qtd_reading();

        int get_qtd_want_to_read();

        int get_qtd_abandonad();

};

