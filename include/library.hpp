
#pragma once

#include "userManager.hpp"

using namespace std;

class Library{
  UserManager *userManager;
  BookManager *bookManager;
public:  
  Library();
  int principalMenu();
  void init();
  void limpaTela();
};

