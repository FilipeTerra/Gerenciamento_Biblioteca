
#pragma once

#include "ctime"
#include "book.hpp"
#include "user.hpp"

using namespace std;

class Booking : public Book
{
    User* client;
    time_t data_i;
    time_t data_f;
public:
    Booking(string isbn, string title, string author, User *client);
    ~Booking();
    void setClient(User *client);
    User* getClient();
    void set_data_i(time_t data_i);
    time_t get_data_i();
    void set_data_f(time_t data_f);
    time_t get_data_f();
    void toString();
};
