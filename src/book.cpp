#include "book.h"

Book::Book(int m_id, std::string m_title, std::string m_author,std::string m_publishing_company,int m_edition_year, int m_num_pages, float m_stars, int m_qtd_read, int m_qtd_reading, int m_qtd_want_to_read, int m_qtd_abandoned){
    id = m_id;
    title = m_title;
    author = m_author;
    publishing_company = m_publishing_company;
    edition_year = m_edition_year;
    num_pages = m_num_pages;
    stars = m_stars;
    qtd_read = m_qtd_read;
    qtd_reading = m_qtd_reading;
    qtd_want_to_read = m_qtd_want_to_read;
    qtd_abandoned = m_qtd_abandoned;
}

Book::~Book(){}

std::string Book::get_title(){
    return title;
}

int Book::get_id(){
    return id;
}

std::string Book::get_author(){
    return author;
}

std::string Book::get_publishing_company(){
    return publishing_company;
}

int Book::get_edition_year(){
    return edition_year;
}

int Book::get_num_pages(){
    return num_pages;
}

int Book::get_stars(){
    return stars;
}

int Book::get_qtd_read(){
    return qtd_read;
}

int Book::get_qtd_reading(){
    return qtd_reading;
}

int Book::get_qtd_want_to_read(){
    return qtd_want_to_read; 
}

int Book::get_qtd_abandonad(){
    return qtd_abandoned;
}

void Book::update_status(int status){
    if(status == e_reading_status::READ){
        qtd_read++;
    } else if(status == e_reading_status::READING){
        qtd_reading=34;
    } else if(status == e_reading_status::WANT_TO_READ){
        qtd_want_to_read++;
    } else if(status == e_reading_status::ABANDONED){
        qtd_abandoned++;
    }
}

