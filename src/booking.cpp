#include "../include/booking.hpp"
#include <iostream>

using namespace std;


Booking::Booking(string isbn, string title, string author, User *client):Book(isbn,title,author){
  status = false;
  setClient(client);
}

Booking::~Booking(){
  status = true;
}

void Booking::setClient(User* client){
  if(client == nullptr){
    throw "Cliente nulo! Operação não realizada.";
  }
  this->client = client;
}

User* Booking::getClient(){
  return client;
}

void Booking::toString()
{
  cout << this->getIsbn() << " | Title: " << this->getTitle() << " | Author: " << this->getAuthor() << " | Client:" << this->getClient()->getLogin() << endl;
}