#include "book.hpp"
#include <iostream>

using namespace std;

// construtor do livro
Book::Book(string isbn, string title, string author)
{
setIsbn(isbn);
setTitle(title);
setAuthor(author);
status = true;
}

// retorna o isbn
string Book::getIsbn(){
  return isbn;
}
// define o isbn
void Book::setIsbn(string isbn){
  this->isbn = isbn;
}
// retorna o titulo
string Book::getTitle(){
  return title;
}
// define o titulo
void Book::setTitle(string title){
  this->title = title;
}
// retorna o autor
string Book ::getAuthor(){
  return author;
}
// define o autor
void Book::setAuthor(string author){
  this->author = author;
}
// retorna a representacao textual do objeto livro
void Book::toString(){
  cout << this->getIsbn() << " | Title: " << this->getTitle() << " | Author: " << this->getAuthor() << endl;
}

// retorna o status do livro
bool Book::getStatus(){
  return status;
}
// define o status do livro
void Book::setStatus(bool status){
  this->status = status;
}
