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

        int state;
        std::string user_name;
        bool end_loop = false;

    public:
        void initialize();
        
        bool is_over();

        void process_events();

        void update();

        void render();        
};

