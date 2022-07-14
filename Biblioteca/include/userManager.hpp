#pragma once

#include <string>
#include <map>
#include "bookManager.hpp"

using namespace std;

class UserManager{
  User* userLogged;
  map<string, User*> costumers;
public:
  UserManager();
  int registrationMenu();
  void registrationadminMenu();
  int loginMenu();
  int userMenu(BookManager *bookManager);
  int adminMenu(BookManager *bookManager);
  User* login(string userLogin);
  void registration(string userLogin, string password);
  bool findCostumer(string target);
  map<string, User *> getCostumers();
  void setUserLogged(User *logged);
  User* getUserLogged();
  void logout();
  void limpaTela();
  void bookingMenu (BookManager *bookManager, User* userLogged);
  void removeBookingMenu (BookManager *bookManager);
};

