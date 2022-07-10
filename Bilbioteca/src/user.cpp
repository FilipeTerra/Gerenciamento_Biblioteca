#include "user.hpp"

using namespace std;

// construtor do usuario
User::User(string login, string password){
  setLogin(login);
  setPassword(password);
  setStatus(true);
}
// retorna o login
string User::getLogin(){
    return login;
}
// define o login
void User::setLogin(string login){
  this->login = login;
}
// retorna a senha
string User::getPassword(){
  return password;
}
// define a senha
void User::setPassword(string password){
  this->password = password;
}
// retorna o status
bool User::getStatus(){
  return status;
}
// define o status
void User::setStatus(bool status){
  this->status = status;
}

