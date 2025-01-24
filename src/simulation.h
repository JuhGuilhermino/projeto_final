/**
 * @file simulation.h
 * @author Júlia Guilhermino (juh.guilhermino03@gmail.com.com)
 * @brief 
 * @version 0.1
 * @date 2025-01-23
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include <string>
#include <iostream>
#include "database.h"

class Simulation {
    private:
        //=== Estados que represetam a simulação do sistema.
        enum e_states{
            STARTING = 0,  //< Carrega dados
            WELCOME,       //< Opções de incializaçaõ
            LOGIN,         //< Realiza login
            SUBSCRIBING,   //< Realiza cadastro
            PROFILE,       //< Exibe perfil do usuário e menu
            LIBRARY,       //< Busca livros na biblioteca pessoal
            READING_BOOK,  //< Atualiza histórioco de leitura
            SEARCHING,     //< Busca livros no acervo
            VIEW_BOOK,     //< Viazualiza dados de um livro
            SAVING,        //< Salva livro na biblioteca pessoal
            QUITTING       //< Slava de dados e encerra o sistema
        };

        enum e_option{
            LOG = 1,
            SUBSCRIBE
        };

        enum e_menu_option{
            SEARCH_BOOK = 1,
            SEARCH_LIBRARY,
            READING_PROGRESS,
            QUIT
        };

        enum e_quitting_option{
            STAY = 1,
            BACK_TO_WELCOME,
            QUIT_NOW
        };

        int state;              //< Controla fluxo de estados
        bool end_loop = false;  //< Controla o loop
        Database data;          //< Instância do banco de dados do sistema
        int option;             //< Opção de entrada no sistema
        int user;               //< ID so usuário que está usando o sistema
        std::string username;   //< Nome no usuário no login
        std::string password;   //< Senha do usuário no login
        std::string name;       //< Nome de susuário nahora do cadastro
        int menu_option;        //< Opção do menu do usuário
        int quitting_option;    //< Opção do menu de saida
        std::string title;      //< Titulo do livro buscado
        int book;               //< Armazena o ide do livro que foi encontrado em uma busca
        char save;              //< Opção de salvar ou não o livro


    public:
        void initialize();
        
        bool is_over();

        void process_events();

        void update();

        void render();        
};

