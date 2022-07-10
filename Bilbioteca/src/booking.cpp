#include "booking.hpp"
#include <iostream>

using namespace std;


Booking::Booking(string isbn, string title, string author, User *client):Book(isbn,title,author)
{
  status = false;
  setClient(client);
}

Booking::~Booking(){
  status = true;
}

/*----------- acho que não precisa disso mais
void Booking::setBook(Book* book) {
  this->book = book;
}

Book* Booking::getBook() {
  return this->book;
}
*/
void Booking::setClient(User* client){
  this->client = client;
}

User* Booking::getClient(){
  return client;
}
void Booking::set_data_i(time_t data_i){
  this->data_i = data_i;
}
time_t Booking::get_data_i(){
  return data_i;
}
void Booking::set_data_f(time_t data_f){
  this->data_f = data_f;
}
time_t Booking::get_data_f(){
  return data_f;
}

void Booking::toString()
{
  cout << this->getIsbn() << " | Title: " << this->getTitle() << " | Author: " << this->getAuthor() << " | Client:" << this->getClient()->getLogin() << endl;
}