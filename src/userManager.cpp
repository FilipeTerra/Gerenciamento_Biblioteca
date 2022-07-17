#include "../include/userManager.hpp"
#include <iomanip>
#include <iostream>

using namespace std;

// construtor do usermanager
UserManager::UserManager() {}

// menu de registro do user
int UserManager::registrationMenu() {
  string userPassword;
  string userPasswordConfirmation;
  string userLogin;

  limpaTela();
  cout << "Cadastre-se no sistema." << endl;
  cout << "Insira um login: " << endl;

  do {
    while (userLogin.length() == 0) {
      getline(cin, userLogin);
    }
    if (findCostumer(userLogin)) {
      userLogin.clear();
      cout << "Login de usuário já existe, por favor, insira um diferente: "
           << endl;
      cout << endl;
      while (userLogin.length() == 0) {
        getline(cin, userLogin);
      }
    }
  } while (findCostumer(userLogin) == true);

  do {
    userPassword.clear();
    userPasswordConfirmation.clear();

    cout << "Insira sua senha: " << endl;
    while (userPassword.length() == 0) {
      getline(cin, userPassword);
    }
    cout << "Confirme a senha: " << endl;
    while (userPasswordConfirmation.length() == 0) {
      getline(cin, userPasswordConfirmation);
    }

    if (userPassword != userPasswordConfirmation) {
      cout << "Erro! A senhas precisam combinar!" << endl;
    }
  } while (userPassword != userPasswordConfirmation);

  limpaTela();
  cout << "Usuário cadastrado com sucesso!" << endl;
  this->registration(userLogin, userPassword);
  return 0;
}

// menu de registro do admin
void UserManager::registrationadminMenu() {
  string userPassword;
  string userPasswordConfirmation;
  string userLogin;

  limpaTela();
  cout << "Cadastre um novo usuário no sistema." << endl;
  cout << "Insira o login: " << endl;

  do {
    while (userLogin.length() == 0) {
      getline(cin, userLogin);
    }
    if (findCostumer(userLogin)) {
      userLogin.clear();
      cout << "Login de usuário já existe, por favor, insira um diferente: "
           << endl;
      cout << endl;
      while (userLogin.length() == 0) {
        getline(cin, userLogin);
      }
    }
  } while (findCostumer(userLogin) == true);

  do {
    userPassword.clear();
    userPasswordConfirmation.clear();

    cout << "Insira sua senha: " << endl;
    while (userPassword.length() == 0) {
      getline(cin, userPassword);
    }
    cout << "Confirme a senha: " << endl;
    while (userPasswordConfirmation.length() == 0) {
      getline(cin, userPasswordConfirmation);
    }

    if (userPassword != userPasswordConfirmation) {
      cout << "Erro! A senhas precisam combinar!" << endl;
    }
  } while (userPassword != userPasswordConfirmation);

  limpaTela();
  cout << "Usuário cadastrado com sucesso!" << endl;
  cout << endl;
  this->registration(userLogin, userPassword);
  return;
}

// menu de login
int UserManager::loginMenu() {
  auto costumers = getCostumers();
  string userLogin;
  string passwordLogin;
  int flag = 0;

  limpaTela();
  cout << "Entre no sistema." << endl;
  do {
    do {
      userLogin.clear();
      passwordLogin.clear();
      cout << "Insira seu login: " << endl;
      while (userLogin.length() == 0) {
        getline(cin, userLogin);
      }
      flag = findCostumer(userLogin);

      int opc;
      if (flag == 0) {
        cout << "Erro: Login não cadastrado." << endl;
        do {
          cout << "[1] - Tentar novamente" << endl;
          cout << "[2] - Sair" << endl;
          cin >> opc;
          switch (opc) {
          case 1:
            flag = 0;
            break;
          case 2:
            limpaTela();
            return 0;
            break;
          }
        } while (opc < 1 || opc > 2);
      }
    } while (flag == 0);

    cout << "Insira sua senha: " << endl;
    while (passwordLogin.length() == 0) {
      getline(cin, passwordLogin);
    }

    if ((costumers.find(userLogin)->second->getPassword()) != passwordLogin) {
      cout << "Erro! Senha incorreta!" << endl;
    }
    cout << endl;
  } while ((costumers.find(userLogin)->second->getPassword()) != passwordLogin);

  setUserLogged(login(userLogin));
  if ((userLogin == "admin") && (passwordLogin == "admin123")) {
    return 10;
  }
  limpaTela();
  return 6;
}

// menu do usuario
int UserManager::userMenu(BookManager *bookManager) {
  limpaTela();
  int opc;
  do {
    auto logged = getUserLogged();
    cout << "Olá, " << logged->getLogin() << endl;
    cout << "Menu do usuário" << endl;
    cout << "(1) Alugar Livro" << endl;
    cout << "(2) Meus alugueis" << endl;
    cout << "(3) Devolver livro" << endl;
    cout << "(4) Sair" << endl;

    cin >> opc;
    while (opc < 1 || opc > 4) {
      cout << "Opcão inválida! Escolha novamente: " << endl;
      cin >> opc;
    }
    switch (opc) {
    case 1:
      limpaTela();
      bookingMenu(bookManager, logged);
      break;
    case 2:
      try {
        bookManager->printBookingsuser(logged);
      } catch (const char *msg) {
        cerr << msg << endl;
      }
      break;
    case 3:
      removeBookingMenu(bookManager);
      break;
    case 4:
      logout();
      opc = 0;
    default:
      break;
    }
  } while (opc > 0);
  limpaTela();
  return 0;
}

// menu de emprestimo
void UserManager::bookingMenu(BookManager *bookManager, User *userLogged) {
  if (bookManager->getStand().size() == 0) {
    cout << "Não há nenhum livro disponível para alugel" << endl;
    cout << endl;
    return;
  } else {
    cout << "Livros disponíveis para aluguel: " << endl;
    cout << endl;
    for (auto it : bookManager->getStand()) {
      Book *book = it.second;
      if (book->getStatus()) {
        book->toString();
        cout << endl;
      }
    }

    cout << "Insira o ISBN do livro que deseja alugar:" << endl;
    string isbn;
    cin >> isbn;
    limpaTela();
    if (bookManager->findBook(isbn)) {
      string title = bookManager->getStand()[isbn]->getTitle();
      string author = bookManager->getStand()[isbn]->getAuthor();
      bookManager->insertBooking(isbn, title, author, userLogged);
    } else {
      cout << "Livro já alugado ou não cadastrado." << endl;
    }
  }
}

// menu de devolução de livro
void UserManager::removeBookingMenu(BookManager *bookManager) {
  limpaTela();
  cout << "Insira o ISBN do livro que deseja devolver" << endl;
  string isbn;
  cin >> isbn;
  limpaTela();
  try {
    bookManager->removeBooking(getUserLogged(), isbn);
    cout << "Livro devolvido com sucesso!" << endl;
  } catch (const char *msg) {
    cerr << msg << endl;
  }

  cout << endl;
}

// menu do administrador
int UserManager::adminMenu(BookManager *bookManager) {
  limpaTela();
  int opc = 0;
  do {
    cout << "Olá, administrador" << endl;
    cout << "Admistração" << endl;
    cout << "(1) Cadastrar livro" << endl;
    cout << "(2) Remover livro" << endl;
    cout << "(3) Atualizar livro" << endl;
    cout << "(4) Cadastrar usuário" << endl;
    cout << "(5) Listar empréstimos" << endl;
    cout << "(6) Sair" << endl;
    cin >> opc;
    while (opc < 1 || opc > 6) {
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
      try{
        bookManager->printBookings();
      }catch(const char *msg){
        cerr << msg << endl;
      }
      break;
    case 6:
      logout();
      opc = -1;
    default:
      break;
    }
  } while (opc >= 0);
  limpaTela();
  return 0;
}

// loga um usuario/admin
User *UserManager::login(string userLogin) {
  return costumers.find(userLogin)->second;
};

// registra um novo usuario
void UserManager::registration(string userLogin, string password) {
  costumers[userLogin] = new User(userLogin, password);
}

// procura um usuario pelo login
bool UserManager::findCostumer(string target) {
  for (auto it = costumers.begin(); it != costumers.end(); it++) {
    if (it->first == target) {
      return true;
    }
  }
  return false;
}

// retorna os usuarios
map<string, User *> UserManager::getCostumers() { return costumers; }

// define um usuario logado
void UserManager::setUserLogged(User *logged) {
  try {
    if (logged == nullptr) {
      throw "Usuário inválido";
    }
  } catch (const char *msg) {
    cerr << msg << endl;
    return;
  }
  this->userLogged = logged;
}

// retorna o usuario logado
User *UserManager::getUserLogged() { return userLogged; }

// desloga o usuario/admin
void UserManager::logout() { userLogged = nullptr; }

// limpa a tela
void UserManager::limpaTela() {
  try {
    if (system("clear||cls") == -1) {
      throw std::exception();
    }
  } catch (int e) {
    cout << "Não foi possível limpar a tela" << endl;
  }
}