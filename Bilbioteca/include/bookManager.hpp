
#pragma once

#include "booking.hpp"
#include <map>
#include <vector>

using namespace std;

class BookManager{
  map<string, Book*> stand;
  map<string, vector <Booking*>> bookings;
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
  void insertBooking(string isbn, string title, string author, User* client);
  void removeBooking(User* client, string isbn);
   map<string, vector <Booking*>> getBookings();
  void printBookings();
  void printBookingsuser(User* client);
  void limpaTela();
};
