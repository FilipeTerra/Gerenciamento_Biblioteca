
#pragma once

#include "ctime"
#include "book.hpp"
#include "user.hpp"

using namespace std;

class Booking
{
    Book* book;
    User* client;
    time_t data_i;
    time_t data_f;
public:
    Booking(Book *book, User *client);
    void setBook(Book *book);
    Book* getBook();
    void setClient(User *client);
    User* getClient();
    void set_data_i(time_t data_i);
    time_t get_data_i();
    void set_data_f(time_t data_f);
    time_t get_data_f();
};
