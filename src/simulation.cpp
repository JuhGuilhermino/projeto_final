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

    }
}

void Simulation::update(){
    if(state == e_states::STARTING){
        std::cout << "Estou aqui \n";
        end_loop = true;
    }
}

void Simulation::render(){
    if(state == e_states::STARTING){
        
    }
}

