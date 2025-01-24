#include "user.h"

User::User(int m_id,std::string m_name, std::string m_user_name, std::string m_password, int m_qtd_read, int m_qtd_reading, int m_qtd_want_to_read, int m_qtd_abandoned){
    id = m_id;
    name = m_name;
    user_name = m_user_name;
    password = m_password;
    qtd_read = m_qtd_read;
    qtd_reading = m_qtd_reading;
    qtd_want_to_read = m_qtd_want_to_read;
    qtd_abandoned = m_qtd_abandoned;
}

User::~User(){}  

int User::get_id(){
    return id;
}

std::string User::get_name(){
    return name;
}

std::string User::get_user_name(){
    return user_name;
}

std::string User::get_password(){
    return password;
}

int User::get_qtd_read(){
    return qtd_read;
}

int User::get_qtd_reading(){
    return qtd_abandoned;
}

int User::get_qtd_want_to_read(){
    return qtd_want_to_read;
}

int User::get_qtd_abandoned(){
    return qtd_abandoned;
}

