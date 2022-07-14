#include "../include/bookManager.hpp"
#include <iostream>
#include <time.h>

using namespace std;

// construtor do bookmanager
BookManager::BookManager() {}

// menu principal da prateleira/bookmanager
int BookManager::shelfMenu() {
  limpaTela();
  int opc;
  do {
    cout << "Prateleira" << endl;
    cout << "(1) Lista de Livros" << endl;
    cout << "(2) Buscar Livro" << endl;
    cout << "(3) Sair para o menu principal" << endl;

    cin >> opc;
    while (opc < 1 || opc > 7) {
      cout << "Escolha inválida. Tente novamente." << endl;
      cin >> opc;
    }

    limpaTela();
    switch (opc) {
    case 1:
      limpaTela();
      printStand();
      break;
    case 2:
      try {
        if (stand.size() == 0) {
          throw "Estande vazia.\n";
        }
      } catch (const char *msg) {
        cerr << msg << endl;
        break;
      }
      findBookMenu();
      break;
    case 3:
      return 0;
      break;
    default:
      return 0;
      break;
    }
  } while (true);

  limpaTela();
  return 0;
}

// menu para procurar livro
void BookManager::findBookMenu() {
  string isbn;
  limpaTela();
  cout << "Procure um livro:" << endl;
  cout << "Insira um ISBN: " << endl;
  while (isbn.length() == 0) {
    getline(cin, isbn);
  }
  limpaTela();
  bool aux = findBook(isbn);

  try {
    if (aux == false) {
      throw "Livro não encontrado ou já alugado\n";
    }
  } catch (const char *msg) {
    cerr << msg << endl;
    return;
  }
  cout << "Cadastrado e disponível\n" << endl;
}

// menu para inserir livro
void BookManager::insertBookMenu() {
  string isbn;
  string author;
  string title;
  limpaTela();
  cout << "Cadastre um livro." << endl;
  cout << "Insira o ISBN: " << endl;
  while (isbn.length() == 0) {
    getline(cin, isbn);
  }

  do {
    try {
      if (findBook(isbn) == true) {
        throw "Livro já existente na biblioteca!";
      }
    } catch (const char *msg) {
      limpaTela();
      cerr << msg << endl;
      isbn.clear();
      cout << "Tente novamente ou digite sair para voltar." << endl;
      cout << "Cadastre um livro." << endl;
      cout << "Insira o ISBN: " << endl;
      while (isbn.length() == 0) {
        getline(cin, isbn);
      }
      if (isbn == "sair") {
        limpaTela();
        return;
      }
    }
  } while (findBook(isbn));

  cout << "Insira um Título: " << endl;
  while (title.length() == 0) {
    getline(cin, title);
  }
  cout << "Insira um Autor: " << endl;
  while (author.length() == 0) {
    getline(cin, author);
  }

  insertBook(isbn, title, author);
}

// menu para remover livro
void BookManager::removeBookMenu() {
  try {
    if (stand.size() == 0) {
      limpaTela();
      throw "Estande vazia. Impossível limpar.\n";
    }
  } catch (const char *msg) {
    cerr << msg << endl;
    return;
  }
  string isbn;
  limpaTela();
  cout << "Remova um livro" << endl;
  cout << endl;
  cout << "Insira um ISBN: " << endl;
  while (isbn.length() == 0) {
    getline(cin, isbn);
  }
  removeBook(isbn);
}

void BookManager::updateBookMenu() {
  try {
    if (stand.size() == 0) {
      limpaTela();
      throw "Estande vazia. Impossível atualizar qualquer livro.\n";
    }
  } catch (const char *msg) {
    cerr << msg << endl;
    return;
  }
  string isbn;
  string author;
  string title;
  int opc;
  limpaTela();
  cout << "Atualize um livro." << endl;
  do {
    isbn.clear();
    cout << "Insira um ISBN" << endl;
    while (isbn.length() == 0) {
      getline(cin, isbn);
    }
    try {
      if (!findBook(isbn)) {
        limpaTela();
        throw "Livro não cadastrado ou já alugado, impossível atualizar\n";
      }
    } catch (const char *msg) {
      cerr << msg << endl;
      do {
        cout << "(1) Tentar novamente" << endl;
        cout << "(2) Sair" << endl;
        cin >> opc;
        limpaTela();
      } while (opc < 1 || opc > 2);
    }

    switch (opc) {
    case 1:
      break;
    case 2:
      limpaTela();
      return;
    }
  } while (!findBook(isbn));

  if (findBook(isbn) && opc != 2) {
    cout << "Insira o Título atualizado: " << endl;
    while (title.length() == 0) {
      getline(cin, title);
    }
    cout << "Insira o Autor atualizado: " << endl;
    while (author.length() == 0) {
      getline(cin, author);
    }
    updateBook(isbn, title, author);
  }
}

// insere um livro na prateleira
void BookManager::insertBook(string isbn, string title, string author) {
  stand[isbn] = new Book(isbn, title, author);
  limpaTela();
  cout << "Livro cadastrado com sucesso!\n" << endl;
}

// remove um livro na prateleira
void BookManager::removeBook(string isbn) {
  try {
    if (findBook(isbn) == false) {
      limpaTela();
      throw "Nao foi possivel remocao. Livro nao cadastrado ou ja alugado.\n";
    }
  } catch (const char *msg) {
    cerr << msg << endl;
    return;
  }
  stand.erase(isbn);
  limpaTela();
  cout << "Livro do ISBN: " << isbn << " - Removido com sucesso!\n" << endl;
}

// atualiza um livro
void BookManager::updateBook(string isbn, string title, string author) {
  try {
    if (findBook(isbn) == false) {
      throw "Não foi possível atualizar o livro.\n";
    }
  } catch (const char *msg) {
    cerr << msg << endl;
    return;
  }
  insertBook(isbn, title, author);
  limpaTela();
  cout << "Livro atualizado com sucesso! \n" << endl;
}

// busca um livro na prateleira
bool BookManager::findBook(string isbn) {
  bool aux = false;
  for (auto it = stand.begin(); it != stand.end(); it++) {
    if (it->first == isbn && it->second->getStatus()) {
      aux = true;
      break;
    }
  }
  return aux;
}

// Inserindo livro na lista de emprestimo da pessoa
void BookManager::insertBooking(string isbn, string title, string author,
                                User *client) {

  if (bookings[client->getLogin()].size() > 3) {
    throw "Limite de emprestimo atingido, devolva algum livro para poder "
          "alugar outro.";
  }
  try {
    Booking *aux = new Booking(isbn, title, author, client);
    bookings[client->getLogin()].push_back(aux);
    stand[isbn]->setStatus(false);
    cout << "Livro alugado com sucesso!" << endl;
    cout << endl;
  } catch (const char *msg) {
    cerr << msg << endl;
  }
}

// retorna o map com todos alugueis da biblioteca
map<string, vector<Booking *>> BookManager::getBookings() {
  return this->bookings;
}

// imprime o estande de livros
void BookManager::printStand() {
  try {
    if (stand.size() == 0) {
      throw "Estande vazia!\n";
    }
  } catch (const char *msg) {
    cerr << msg << endl;
    return;
  }

  cout << "Listagem de todos os livros cadastrados: " << endl;
  cout << endl;
  for (auto it = stand.begin(); it != stand.end(); it++) {
    Book *book = it->second;
    book->toString();
    cout << endl;
  }
}

map<string, Book *> BookManager::getStand() { return this->stand; }

// função para limpar a tela
void BookManager::limpaTela() {
  try {
    if (system("clear||cls") == -1) {
      throw std::exception();
    }
  } catch (int e) {
    cout << "Não foi possível limpar a tela" << endl;
  }
}

// imprime o estande de livros alugados
void BookManager::printBookings() {
  limpaTela();
  if (bookings.size() == 0) {
    throw "Nenhum livro alugado! \n";
  }
  cout << "Listagem de todos os livros alugados: " << endl;
  cout << endl;
  for (auto it = bookings.begin(); it != bookings.end(); it++) {
    vector<Booking *> book = it->second;
    for (auto it1 = book.begin(); it1 != book.end(); it1++) {
      Book *livros = *it1;
      livros->toString();
    }
    cout << endl;
  }
}

// remove emprestimo de um usuario
void BookManager::removeBooking(User *client, string isbn) {
  for (auto it = this->bookings[client->getLogin()].begin();
       it != this->bookings[client->getLogin()].end(); it++) {
    Book *alugado = *it;
    if (isbn == alugado->getIsbn()) {
      this->bookings[client->getLogin()].erase(it);
      this->stand[isbn]->setStatus(true);
      return;
    }
  }

  throw "Você não pode remover esse aluguel.";
}

void BookManager::printBookingsuser(User *client) {
  limpaTela();

  if (bookings[client->getLogin()].size() == 0) {
    throw "Nenhum livro alugado!\n";
    return;
  }
  string nome = client->getLogin();
  for (auto it = bookings.begin(); it != bookings.end(); it++) {
    if (it->first == nome) {
      vector<Booking *> livro = it->second;
      for (auto it1 = livro.begin(); it1 != livro.end(); it1++) {
        Book *alugado = *it1;
        alugado->toString();
        cout << endl;
      }
    }
  }
}