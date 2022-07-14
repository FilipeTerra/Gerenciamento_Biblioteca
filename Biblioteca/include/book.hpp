#pragma once

#include <string>

using namespace std;
/** 
*  @brief This class is responsible to storage and manage a book information, 
*  Also, the other class 'booking' inherits this class.
*/

class Book{
/**  
*  @brief specific registration number of each book
*/
  string isbn;
/**
*  @brief title of each book
*/
  string title;
/**
*  @brief the author of each book
*/
  string author;
protected:
/**
*  @brief this is the atribute that 'booking' class can access to change book status
*  @param status, means the status of each book which can be either false(rented) or true(free to rent)
*/
  bool status;
public:
/**
*  @brief Book constructor.
*/
  Book(string isbn, string title, string author);
/**
*  @brief returns book's isbn.
*/
  string getIsbn();
/**
*  @brief define book's isbn set by the parameter.
*/
  void setIsbn(string isbn);
/**
*  @brief returns book's title.
*/
  string getTitle();
/**
*  @brief define book's title set by the parameter.
*/
  void setTitle(string title);
/**
*  @brief returns book's author.
*/
  string getAuthor();
/**
*  @brief define book's author set by the parameter.
*/
  void setAuthor(string author);
/**
*  @brief returns if book's status is true or false.
*/
  bool getStatus();
/**
*  @brief define book's status set by the parameter.
*/
  void setStatus(bool status);
/**
*  @brief print the complete book's info EX: ISBN | Title | Author
*  it will be inherited in 'Booking' class.
*/
  virtual void toString();
};
