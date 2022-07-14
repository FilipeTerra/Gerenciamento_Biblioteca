
#pragma once

#include <string>

using namespace std;

class User{
  string login;
  string password;
  bool status;
public:
  User(string login, string password);
  string getLogin();
  void setLogin(string login);
  string getPassword();
  void setPassword(string password);
  bool getStatus();
  void setStatus(bool status);
  void print ();
};
