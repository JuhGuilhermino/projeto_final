#include "database.h"

void Database::read_books(){
    Book b0(0, "A Livraria Mágica de Paris", "Nina George", "Record", 2017, 306, 0, 0, 0, 0, 0);
    books.push_back(b0);
    Book b1(1, "Torto Arado", "Itamar Vieira Junior", "Todavia", 2021, 262, 0, 0, 0, 0, 0);
    books.push_back(b1);
    Book b2(2, "A Cor Púrpura", "Alice Walker", "José Olympio", 2020, 335, 0, 0, 0, 0, 0);
    books.push_back(b2);
    Book b3(3, "Relatos de um Gato Viajante", "Hiro Arikawa", "Alfaguara", 2017, 225, 0, 0, 0, 0, 0);
    books.push_back(b3);
    Book b4(4, "1984", "George Orwell", "Antofágica", 2021, 505, 0, 0, 0, 0, 0);
    books.push_back(b4);
    Book b5(5, "O Hobbit", "J.R.R. Tolkien", "Harper Collins", 2019, 336, 0, 0, 0, 0, 0);
    books.push_back(b5);
}

void Database::read_users(){
    User u0(0, "Julia", "juh", "123", 0,0,0,0);
    users.push_back(u0);
}

Book Database::get_book(int id){
    return books[id];
}

User Database::get_user(int id){
    return users[id];
}

int Database::search_user(std::string username){
    for (int i = 0; i < users.size(); i++){
        if (username == users[i].get_user_name()){
            return i;
            i = users.size();
        }
    }
    return -1;
}

bool Database::valid_password(int user_id, std::string password){
    if (users[user_id].get_password() == password){
        return true;
    } else {
        return false;
    }
}

void Database::add_user(std::string name, std::string username, std::string password){
    User new_user(users.size(), name, username, password, 0, 0, 0, 0);
    users.push_back(new_user);
}


