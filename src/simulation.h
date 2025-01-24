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

        int state;              //< Controla fluxo de estados
        bool end_loop = false;  //< Controla o loop
        Database data;          //< Instância do banco de dados do sistema
        int option;             //< Opção de entrada no sistema


    public:
        void initialize();
        
        bool is_over();

        void process_events();

        void update();

        void render();        
};

