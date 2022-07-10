#include "library.hpp"
#include <iostream>

using namespace std;

Library::Library(){
  this->userManager = new UserManager();
  this->bookManager = new BookManager();
}

int Library::principalMenu(){
  limpaTela();
  do {
    int option;
    cout << "Menu Principal." << endl;
    cout << "[1] - Cadastro" << endl;
    cout << "[2] - Login" << endl;
    cout << "[3] - Prateleira" << endl;
    cout << "[4] - Sair" << endl;
    cout << "Digite uma opção: ";
    cin >> option;
    if(option < 1 || option > 4){
      do {
        cout << "Comando inválido!" << endl;
        cout << "Digite novamente: ";
        cin >> option;
      } while (option < 1 || option > 4);
    }
    
    switch (option) {
      case 1:
        return 1;
        break;
      case 2:
        return 2;
        break;
      case 3:
        return 11;
        break;
      case 4:
        exit(1);
        break;
      default:
        return 0;
        break;
    }
  } while (true);
}

void Library::init(){
  this->userManager->registration("admin", "admin123");
  int opc = 0;
  while(true){
    switch(opc){
        //menu principal
        case 0:
            opc = this->principalMenu();
            break;
        //chama o menu de registro
        case 1:
            opc = userManager->registrationMenu();
            break;
        //chama o menu de login do user manager
        case 2:
            opc = userManager->loginMenu();
            break;
        //chama o menu do usuario logado do user manager
        case 6:
            opc = userManager->userMenu(bookManager);
            break;
        //chama o menu do admin logado do user manager
        case 10:
            opc = userManager->adminMenu(bookManager);
            break;
        //chama o menu da prateleira do book manager
        case 11:
          opc = bookManager->shelfMenu();
          break;
        case 15:
          break;  
        case 16:
          break;
        }
    }
}

//limpa a tela
void Library::limpaTela(){
  try{
    if(system("clear||cls") == -1){
      throw std::exception();
    }
  }catch(int e){
    cout << "Não foi possível limpar a tela" << endl;
  }
}