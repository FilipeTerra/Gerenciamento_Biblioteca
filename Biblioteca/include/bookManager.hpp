#pragma once

#include "booking.hpp"
#include <map>
#include <vector>

using namespace std;
/**
*  @brief class responsible to manage and store all books and bookings
*  it also is responsible to create and manage book and booking Menu
*/
class BookManager{
  /**
  *  @brief stand of books of the library, 1st isbn, 2nd book.
  */
  map<string, Book*> stand;
  /**
  *  @brief all bookings, 1st isbn, 2nd vector of bookings
  */
  map<string, vector <Booking*>> bookings;
public:
  /**
  *  @brief bookmanager constructor
  */
  BookManager();
  /**
  *  @brief execute shelf menu from main menu,
  *  it search and return books from the stand, showing its information
  *  and it allows you to return to the main menu.
  */

//////// MENUS ////////

  int shelfMenu();
/**
*  @brief menu that searches for a book and returns it availability.
*/
  void findBookMenu();
/**
*  @brief menu that searches for a book and remove it from the stand.
*/
  void removeBookMenu();
/**
*  @brief menu that gets from user's input the necessary data to create a new book.
*/
  void insertBookMenu();
/**
*  @brief menu that gets user's input to modify an existed book.
*/
  void updateBookMenu();

  //////// BOOKS ////////

/**
*  @brief function that prints all the stand's books.
*/
  void printStand();
/**
*  @brief returns all stand's books, 1st isbn, 2ns book.
*/
  map<string, Book*> getStand();
/**
*  @brief function to insert a book on the stand.
*/
  void insertBook(string isbn, string title, string author);
/**
*  @brief funtion to remove a book from the stand.
*/
  void removeBook(string isbn);
/**
*  @brief function to update a stand's book.
*/
  void updateBook(string isbn, string title, string author);
/**
*  @brief function to search a book inside the stand and returns true or false.
*/
  bool findBook(string isbn);

  //////// BOOKINGS ////////

/**
*  @brief insert a booking in bookings map.
*/
  void insertBooking(string isbn, string title, string author, User* client);
/**
*  @brief removes a booking from the bookings map. 
*/
  void removeBooking(User* client, string isbn);
/**
*  @brief returns the map of bookings.
*/
   map<string, vector <Booking*>> getBookings();

  void printBookings();
  void printBookingsuser(User* client);
  void limpaTela();
};
