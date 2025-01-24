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

    } else if (state = e_states::LOGIN){
    
    } else if (state = e_states::SUBSCRIBING){
    
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
        
    } else if (state = e_states::LOGIN){
        end_loop = true;

    } else if (state = e_states::SUBSCRIBING){
        end_loop = true;
        
    }
}

void Simulation::render(){
    if(state == e_states::STARTING){
        // Não faz nada
    } else if(state == e_states::WELCOME){
       std::cout << "------------------------------------------------------------\nBem vinde ao seu geranciador de leituras! \n------------------------------------------------------------\n\nDigite:\n 1. Fazer Login\n 2. Fazer Cadastro. \n>>>   "; 

    } else if (state = e_states::LOGIN){
    
    } else if (state = e_states::SUBSCRIBING){
    
    }
}

