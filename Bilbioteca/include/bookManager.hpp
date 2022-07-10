
#pragma once

#include "booking.hpp"
#include <map>

using namespace std;

class BookManager{
  map<string, Book*> stand;
  map<string, Booking*> bookings;
public:
  BookManager();
  int shelfMenu();
  void findBookMenu();
  void removeBookMenu();
  void insertBookMenu();
  void updateBookMenu();
  // books
  void printStand();
  map<string, Book*> getStand();
  void insertBook(string isbn, string title, string author);
  void removeBook(string isbn);
  void updateBook(string isbn, string title, string author);
  bool findBook(string isbn);
  //bookings
  // void insertBooking(Book *book);
  void insertBooking();
  // map<string, Booking*> getBookings();  
  void getBookings();
  void limpaTela();
};
