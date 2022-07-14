#include <iostream>
#include <iomanip>
#include "userManager.hpp"

using namespace std;

// construtor do usermanager
UserManager::UserManager(){

}

// menu de registro do user 
int UserManager::registrationMenu(){
  string userPassword;
  string userPasswordConfirmation;
  string userLogin;

  limpaTela();
  cout << "Cadastre-se no sistema." << endl;
  cout << "Insira um login: " << endl;

  while(userLogin.length() == 0){
    getline(cin, userLogin);
  }

  do{
    userPassword.clear();
    userPasswordConfirmation.clear();

    cout << "Insira sua senha: " << endl;
    while(userPassword.length() == 0){
      getline(cin, userPassword);
    }
    cout << "Confirme a senha: " << endl;
    while(userPasswordConfirmation.length() == 0){
      getline(cin, userPasswordConfirmation);
    }

    if(userPassword != userPasswordConfirmation){
      cout << "Erro! A senhas precisam combinar!" << endl;
    }
  }while(userPassword != userPasswordConfirmation);

  this->registration(userLogin, userPassword);
  limpaTela();
  return 0;
}

// menu de registro do admin 
void UserManager::registrationadminMenu(){
  string userPassword;
  string userPasswordConfirmation;
  string userLogin;

  limpaTela();
  cout << "Cadastre um novo usuário no sistema." << endl;
  cout << "Insira o login: " << endl;

  while(userLogin.length() == 0){
    getline(cin, userLogin);
  }

  do{
    userPassword.clear();
    userPasswordConfirmation.clear();

    cout << "Insira a senha: " << endl;
    while(userPassword.length() == 0){
      getline(cin, userPassword);
    }
    cout << "Confirme a senha: " << endl;
    while(userPasswordConfirmation.length() == 0){
      getline(cin, userPasswordConfirmation);
    }

    if(userPassword != userPasswordConfirmation){
      cout << "Erro! A senhas precisam combinar!" << endl;
    }
  }while(userPassword != userPasswordConfirmation);

  this->registration(userLogin, userPassword);
  limpaTela();
  return;
}

// menu de login
int UserManager::loginMenu(){
  auto costumers = getCostumers();
  string userLogin;
  string passwordLogin;
  int flag = 0;

  limpaTela();
  cout << "Entre no sistema." << endl;
  do{
    do{
      userLogin.clear();
      passwordLogin.clear();
      cout << "Insira seu login: " << endl;
      while (userLogin.length() == 0){
        getline(cin, userLogin);
      }
      flag = findCostumer(userLogin);

      int opc;
      if(flag == 0){
        cout << "Erro: Login não cadastrado." << endl;
        do{
          cout << "[1] - Tentar novamente" << endl;
          cout << "[2] - Sair" << endl;
          cin >> opc;
          switch (opc){
  				  case 1:
              flag = 0;
              break;
            case 2:
              limpaTela();
              return 0;
              break;            
          }
			  }while(opc < 1 || opc > 2);
      }
    } while (flag == 0);

    cout << "Insira sua senha: " << endl;
    while(passwordLogin.length() == 0){
      getline(cin, passwordLogin);
    }

    if((costumers.find(userLogin)->second->getPassword()) != passwordLogin){
      cout << "Erro! Senha incorreta!" << endl;
    }
    cout << endl;
  } while ((costumers.find(userLogin)->second->getPassword()) != passwordLogin);


  setUserLogged(login(userLogin));
  if((userLogin == "admin") && (passwordLogin == "admin123")){
    return 10;
  }
  limpaTela();
  return 6;
}

// menu do usuario
int UserManager::userMenu(BookManager *bookManager){
  limpaTela();
  int opc;
  do {
    auto logged = getUserLogged();
    cout << "Olá, " << logged->getLogin() << endl;
    cout << "Menu do usuário" << endl;
    cout << "(1) Alugar Livro" << endl;
    cout << "(2) Meus alugueis" << endl;
    cout << "(3) Sair" << endl;

    cin >> opc;
    while (opc < 1 || opc > 3) {
      cout << "Opcão inválida! Escolha novamente: " << endl;
      cin >> opc;
    }
    switch (opc) {
      case 1:
        limpaTela();
        bookingMenu(bookManager,logged);
        // bookManager->insertBooking(); vou mudar isso para responsabilidade do usermanager (já foi)
        break;
      case 2:
        bookManager->printBookingsuser(logged);
        //limpaTela();
        //bookManager->getBookings(); vou mudar isso para responsabilidade do usermanager (já foi)
        break;
      case 3:
        //volta ao menu principal da biblioteca
        logout();
        opc = 0;
      default:
        break;
    }
  }while (opc > 0);
  limpaTela();
  return 0;
}

//menu de emprestimo 
void UserManager::bookingMenu(BookManager *bookManager, User* userLogged) {
  if (bookManager->getStand().size() == 0) 
  {
    cout << "Não há nenhum livro disponível para alugel" << endl;
    cout << endl;
    return;
  }
  else 
  {
  	cout << "Livros disponíveis para aluguel: " << endl;
    cout << endl;
  	for (auto it : bookManager->getStand()){
  		Book * book = it.second;
      if(book->getStatus())
      {
        book->toString();
        cout << endl;
      }
    }
    cout << "Insira o ISBN do livro que deseja alugar:" << endl;
    string isbn;
    cin >> isbn;
    if(bookManager->findBook(isbn))
    {
      cout << "entrou" << endl;
      string title = bookManager->getStand()[isbn]->getTitle();
      string author = bookManager->getStand()[isbn]->getAuthor();
      bookManager->insertBooking(isbn, title, author, userLogged); 
      limpaTela();
    }else 
    {
      cout << "Livro já alugado." << endl;
      for (int i = 0 ; i<1000; i++){};
    }
  }
}

// menu do administrador
int UserManager::adminMenu(BookManager *bookManager){
  limpaTela();
  int opc;
  do {
    cout << "Olá, administrador" << endl;
    cout << "Admistração" << endl;
    cout << "(1) Cadastrar livro" << endl;
    cout << "(2) Remover livro" << endl;
    cout << "(3) Atualizar livro" << endl;
    cout << "(4) Cadastrar usuário" << endl;
    cout << "(5) Sair" << endl;
    cin >> opc;
    while (opc < 1 || opc > 5) {
      cout << "Opcão inválida! Escolha novamente: " << endl;
      cin >> opc;
    }
    switch (opc) {
      case 1:
        bookManager->insertBookMenu();
        break;
      case 2:
        bookManager->removeBookMenu();
        break;
      case 3:
        bookManager->updateBookMenu();
        break;
      case 4:
        registrationadminMenu();
        break;
      case 5:
        logout();
        opc = 0;
      default:
        break;
    }
  }while (opc > 0);
  limpaTela();
  return 0;
}

// loga um usuario/admin
User* UserManager::login(string userLogin){
  return costumers.find(userLogin)->second ;
};
 
// registra um novo usuario
void UserManager::registration(string userLogin, string password){
  costumers[userLogin] = new User(userLogin, password);
}


// procura um usuario pelo login
bool UserManager::findCostumer(string target){
  for(auto it = costumers.begin(); it != costumers.end(); it++){
    if(it->first == target){
      return true;
    }
  }
  return false;
}

// retorna os usuarios
map<string, User*> UserManager::getCostumers(){
  return costumers;
}

// define um usuario logado
void UserManager::setUserLogged(User* logged){
  this->userLogged = logged;
}

// retorna o usuario logado
User* UserManager::getUserLogged(){
  return userLogged;
}

// desloga o usuario/admin
void UserManager::logout(){
  userLogged = nullptr;
}
//limpa a tela
void UserManager::limpaTela(){
  try{
    if(system("clear||cls") == -1){
      throw std::exception();
    }
  }catch(int e){
    cout << "Não foi possível limpar a tela" << endl;
  }
}