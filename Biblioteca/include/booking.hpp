
#pragma once

#include "ctime"
#include "book.hpp"
#include "user.hpp"

using namespace std;
/**
*  @brief This is a class created from class 'Book',
*  Booking class is responsible to create and manage book bookings.
*/

class Booking : public Book{
/**
*  @brief each 'booking' has its own User/client.
*/
    User* client;
public:
    /**
    *  @brief booking constructor.
    */
    Booking(string isbn, string title, string author, User *client);
    /**
    *  @brief booking destructor.
    */
    ~Booking();
    /**
    *  @brief defines booking client set by the parameter.
    */
    void setClient(User *client);
    /**
    *  @brief returns the booking User.
    */
    User* getClient();
    /**
    *  @brief inherited method from Book class used to print the complete book's info + client.
    */
    void toString();
};
