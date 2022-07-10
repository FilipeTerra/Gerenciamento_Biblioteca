
#pragma once

#include <string>

using namespace std;

class Book{
  string isbn;
  string title;
  string author;
public:
  Book(string isbn, string title, string author);
  string getIsbn();
  void setIsbn(string isbn);
  string getTitle();
  void setTitle(string title);
  string getAuthor();
  void setAuthor(string author);
  bool getStatus();
  void setStatus(bool status);
  void toString();
};
