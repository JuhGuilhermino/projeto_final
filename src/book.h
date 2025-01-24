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

#ifndef BOOK.H
#define BOOK.H

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
};

#endif