#include "simulation.h"

void Simulation::initialize(){
    // Carrega dados de livros e usuários cadastrados
    data.read_books();
    data.read_users();

    //Inicia os estados
    state = e_states::STARTING; 
}
        
bool Simulation::is_over(){
    return end_loop;
}

void Simulation::process_events(){
    if(state == e_states::STARTING){
        // Não faz nada
    } else if(state == e_states::WELCOME){
        std::cin >> option;

    } else if (state == e_states::LOGIN){
        std::cout << "Nome de Usuário:   ";
        std::cin >> username;
        std::cout << "Senha:   ";
        std::cin >> password;

    } else if (state == e_states::SUBSCRIBING){
        std::cout << "Nome Completo >>>   ";
        std::cin >> name;
        std::cout << "Nome de Usuário >>>   ";
        std::cin >> username;
        std::cout << "Senha >>>   ";
        std::cin >> password;
    } else if (state == e_states::PROFILE){
        std::cin >> menu_option;
        
    } else if (state == e_states::SEARCHING){
        std::cin >> title;

    } else if (state == e_states::VIEW_BOOK){
        std::cin >> save;

    } else if (state == e_states::SAVING){

    } else if (state == e_states::QUITTING){
        std::cin >> quitting_option;
        
    }
}

void Simulation::update(){
    if(state == e_states::STARTING){
        // Atualiza estado
        state = e_states::WELCOME;

    } else if(state == e_states::WELCOME){
        // Verifica entrada e atualiza estados
        if (option == e_option::LOG){
            state = e_states::LOGIN;

        } else if (option == e_option::SUBSCRIBE){
            state = e_states::SUBSCRIBING;

        } else {
            std::cerr << "\nERRO: opção inválida!\n" << std::endl;
        }
        
    } else if (state == e_states::LOGIN){
        //Verificação das informações de login
        if (data.search_user(username) < 0){
            std::cout << "\n ERRO: usuário não cadastrado.\n";

            // Atualiza estado
            state = e_states::WELCOME;

        } else {
            user = data.search_user(username);

            if (data.valid_password(user, password)){
                // Usuário validado, atualiza estado
                state = e_states::PROFILE;

            } else {
                std::cout << "\n ERRO: senha incorreta.\n";
            }        
        }
        
    } else if (state == e_states::SUBSCRIBING){
        // Verifica se esse usuário já existe
        if (data.search_user(username) < 0){
            // Adiciona novo usuário
            data.add_user(name, username, password);

            // Redireciona para login
            state = e_states::LOGIN;

        } else {
            std::cout << "\n ERRO: usuário já cadastrado.\n";
        }
        
    } else if (state == e_states::PROFILE){
        if (menu_option == e_menu_option::SEARCH_BOOK){
            state = e_states::SEARCHING;

        } else if (menu_option == e_menu_option::SEARCH_LIBRARY){
            end_loop = true;

        } else if (menu_option == e_menu_option::READING_PROGRESS){
            end_loop = true;

        } else if (menu_option == e_menu_option::QUIT){
            state = e_states::QUITTING;

        } else {
            std::cout << "\n ERRO: operação inválida!\n";
        }
        
    } else if (state == e_states::SEARCHING){
        if (data.search_book(title) < 0){
            std::cout << "\n ERRO: livro não encontrado.\n";

        } else {
            book = data.search_book(title);
            state = e_states::VIEW_BOOK;
        }

    } else if (state == e_states::VIEW_BOOK){
        if (save == 'S' or save == 's'){
            // Muda o estado
            state = e_states::SAVING;

        } else if (save == 'N' or save == 'n'){
            // Volta para o perfil
            state = e_states::PROFILE;

        } else {
            // Continua na mesma página
            std::cout << "\n ERRO: operação inválida!\n";
        }
        

    } else if (state == e_states::SAVING){
        end_loop = true;

    } else if (state == e_states::QUITTING){
        if (quitting_option == e_quitting_option::STAY){
            // Atualiza estado para 
            state = e_states::PROFILE;

        } else if (quitting_option == e_quitting_option::BACK_TO_WELCOME){
            // Atualiza estado para 
            state = e_states::WELCOME;

        } else if (quitting_option == e_quitting_option::QUIT_NOW){
            // Atualiza estado para 
            state = e_states::STARTING;
            end_loop = true;

        } else {
            std::cout << "\n ERRO: operação inválida!\n";
        }

    }
}

void Simulation::render(){
    if(state == e_states::STARTING){
        // Não faz nada
    } else if(state == e_states::WELCOME){
       std::cout << "----------------------------------------------------------------\n";
       std::cout << "           BEM VINDE AO SEU GERENCIADOR DE LEITURAS!!!          \n"; 
       std::cout << "----------------------------------------------------------------\n\nDigite:\n 1. Fazer Login\n 2. Fazer Cadastro. \n>>>   "; 

    } else if (state == e_states::LOGIN){
        std::cout << "----------------------------------------------------------------\n";
        std::cout << "                           LOGIN                                \n";
        std::cout << "----------------------------------------------------------------\n";
    
    } else if (state == e_states::SUBSCRIBING){
        std::cout << "----------------------------------------------------------------\n";
        std::cout << "                          CADASTRO                              \n";
        std::cout << "----------------------------------------------------------------\n";
        std::cout << "Informe os dados abaixo:\n";

    } else if (state == e_states::PROFILE){
        std::cout << "----------------------------------------------------------------\n";
        std::cout << "                           PERFIL                               \n";
        std::cout << "----------------------------------------------------------------\n";
        std::cout << "USUÁRIO(A): " << data.get_user(user).get_name() << "\n";
        std::cout << "LIVROS SALVOS: " << data.get_user(user).library_size() << "\n";
        std::cout << "STATUS DA SUA BIBLIOTECA\n";
        std::cout << "  [" << data.get_user(user).get_qtd_read() << "] - livros lidos.\n";
        std::cout << "  [" << data.get_user(user).get_qtd_reading() << "] - livros lendo.\n";
        std::cout << "  [" << data.get_user(user).get_qtd_want_to_read() << "] - livros que quero ler.\n";
        std::cout << "  [" << data.get_user(user).get_qtd_abandoned() << "] - livros abandonados.\n";
        std::cout << "MENU\n";
        std::cout << "  1 - Buscar livro no acervo.\n";
        std::cout << "  2 - Buscar livro na biblioteca pessoal.\n";
        std::cout << "  3 - Registrar histórico de leitura.\n";
        std::cout << "  4 - Sair.\n";
        std::cout << "Informe o número da operação que deseja realizar >>>   ";
    } else if (state == e_states::SEARCHING){
        std::cout << "----------------------------------------------------------------\n";
        std::cout << "                       PESQUISAR LIVRO                          \n";
        std::cout << "----------------------------------------------------------------\n";
        std::cout << "Informe o nome do livro: ";

    } else if (state == e_states::VIEW_BOOK){
        std::cout << "---\nTÍTULO: " << data.get_book(book).get_title() << "\n";
        std::cout << "AUTOR(A): " << data.get_book(book).get_author() << "\n";
        std::cout << "EDITORA: " << data.get_book(book).get_publishing_company() << "\n";
        std::cout << "ANO DA EDIÇÃO: " << data.get_book(book).get_edition_year() << "\n";
        std::cout << "Nº DE PÁGINAS: " << data.get_book(book).get_num_pages() << "\n";
        std::cout << "---\nDeseja salvar o livro na sua biblioteca? (S/N) >>>   ";

    } else if (state == e_states::SAVING){

    } else if (state == e_states::QUITTING){
        std::cout << "----------------------------------------------------------------\n";
        std::cout << "OPÇÕES:\n";
        std::cout << "  1 - Continuar com esse usuário.\n";
        std::cout << "  2 - Trocar de usuário.\n";
        std::cout << "  3 - Sair.\n";
        std::cout << "Informe o número da operação que deseja realizar >>>   ";
    }
}

