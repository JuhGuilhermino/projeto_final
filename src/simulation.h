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

#ifndef SIMULATION.H
#define SIMULATION.H

#include <string>

class Simulation {
    private:
        //=== Estados que represetam a simulação do sistema.
        enum e_states{
            STARTING = 0,
            LOGIN
        };

        int state;
        std::string user_name;

    public:
        void initialize(int argc, char* argv[]);
        
        bool is_over();

        void process_events();

        void update();

        void render();        
};

#endif