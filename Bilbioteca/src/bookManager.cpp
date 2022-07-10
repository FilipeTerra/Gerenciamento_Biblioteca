#include "bookManager.hpp"
#include <iostream>

using namespace std;

// construtor do bookmanager
BookManager::BookManager()
{
  
}

// menu principal da prateleira/bookmanager
int BookManager::shelfMenu(){
  limpaTela();
  int opc;
  do {
    cout << "Prateleira" << endl;
    cout << "(1) Lista de Livros" << endl;
    cout << "(2) Buscar Livro" << endl;
    cout << "(3) Sair para o menu principal" << endl;

    cin >> opc;
    while(opc < 1 || opc > 7){
      cout << "Escolha inválida. Tente novamente." << endl;
      cin >> opc;
    }

    limpaTela();
    switch (opc)
    {
    case 1:
      limpaTela();
      printStand();
      break;
    case 2:
      findBookMenu();
      break;
    case 3:
      return 0;
      break;
    default:
      return 0;
      break;
    }
  }while(true);

  limpaTela();
  return 0;
}

// menu para procurar livro
void BookManager::findBookMenu(){
  string isbn;
  limpaTela();
  cout << "Procure um livro:" << endl;
  cout << "Insira um ISBN: " << endl;
  while(isbn.length() == 0){
    getline(cin, isbn);
  }
  limpaTela();
  bool aux = findBook(isbn);
  if(aux == false){
    cout << "-> Livro não encontrado ou já alugado" << endl;
  }else{
    cout << "-> Cadastrado e disponível" << endl;
  }
}

// menu para inserir livro
void BookManager::insertBookMenu(){
  string isbn;
  string author;
  string title;
  limpaTela();
  cout << "Cadastre um livro." << endl;
  cout << "Insira o ISBN: " << endl;
  while(isbn.length() == 0){
    getline(cin, isbn);
  }

  cout << "Insira um Título: " << endl;
  while(title.length() == 0){
    getline(cin, title);
  }
  cout << "Insira um Autor: " << endl;
  while(author.length() == 0){
    getline(cin, author);
  }

  insertBook(isbn, title, author);
  limpaTela();
}


// menu para remover livro
void BookManager::removeBookMenu(){
  string isbn;
  limpaTela();
  cout << "Remova um livro" << endl;
  cout << endl;
  cout << "Insira um ISBN: " << endl;
  while(isbn.length() == 0){
    getline(cin, isbn);
  }
  removeBook(isbn);
  limpaTela();
}


void BookManager::updateBookMenu(){
  string isbn;
  string author;
  string title;
  int opc;
  limpaTela();
  cout << "Atualize um livro." << endl;
  do{
    isbn.clear();
    cout << "Insira um ISBN" << endl;
    while(isbn.length() == 0){
      getline(cin, isbn);
    }
    if(!findBook(isbn)){
      cout << "Livro não cadastrado ou já alugado, impossível atualizar" << endl;
      do{
        cout << "(1) Tentar novamente" << endl;
        cout << "(2) Sair" << endl;
        cin >> opc;
      } while (opc < 1 || opc > 2);
    }
    switch (opc){
      case 1:
        break;
      case 2:
        limpaTela();
        return;
    }
  } while(!findBook(isbn));

  if(findBook(isbn) && opc != 2){
    cout << "Insira o Título atualizado: " << endl;
    while(title.length() == 0){
      getline(cin, title);
    }
    cout << "Insira o Autor atualizado: " << endl;
    while(author.length() == 0){
      getline(cin, author);
    }
    updateBook(isbn, title, author);
  }
 
  limpaTela();
}

// insere um livro na prateleira
void BookManager::insertBook(string isbn, string title, string author){
  stand[isbn] = new Book(isbn, title, author);
}

// remove um livro na prateleira
void BookManager::removeBook(string isbn){
  if (findBook(isbn)) {
    stand.erase(isbn);
    cout << "Livro do ISBN: " << isbn << " -> Removido com sucesso! <-" << endl;
  }else {
    cout << "Nao foi possivel remocao. Livro nao cadastrado ou ja alugado." << endl;
  }
}

// atualiza um livro
void BookManager::updateBook(string isbn, string title, string author){
  if(findBook(isbn)){
    insertBook(isbn, title, author);
  }
}

// busca um livro na prateleira
bool BookManager::findBook(string isbn){
  bool aux = false;
  for(auto it = stand.begin(); it != stand.end(); it++){
    if(it->first == isbn && it->second->getStatus()){
      aux = true;
      break;
    }
  }
  return aux;
}

//Inserindo livro na lista de emprestimo da pessoa
void BookManager::insertBooking(string isbn, string title, string author, User* client){
  if(bookings[client->getLogin()].size()==0)
  {
    if(!(bookings[client->getLogin()].size()<3))
    {
      return;
      cout << "Limite de emprestimo atingido, devolva algum livro para poder alugar outro." << endl;
    }else
    {
      Booking *aux = new Booking(isbn, title, author, client);
      bookings[client->getLogin()].push_back(aux);
      stand[isbn]->setStatus(false);
      cout << "Inserido emprestimo" << endl;
      cout << "Livro alugado com sucesso." << endl;
    }
  }
}

// retorna o map com todos alugueis da biblioteca
map<string, vector <Booking*>> BookManager::getBookings()
{
  return this->bookings;
}

// imprime o estande de livros 
void BookManager::printStand(){
  if (stand.size() == 0) {
    cout << "Nenhum livro cadastrado!" << endl;
    cout << endl;
  }else {
  	cout << "Listagem de todos os livros cadastrados: " << endl;
    cout << endl;
  	for (auto it = stand.begin(); it != stand.end(); it++){
  		Book * book = it->second;
      book->toString();
      cout << endl;
    }
	}
}

map<string, Book*> BookManager::getStand() {
  return this->stand;
}

// função para limpar a tela
void BookManager::limpaTela(){
  try{
    if(system("clear||cls") == -1){
      throw std::exception();
    }
  }catch(int e){
    cout << "Não foi possível limpar a tela" << endl;
  }
}

//imprime o estande de livros alugados
void BookManager::printBookings()
{
  if (bookings.size() == 0) {
    cout << "Nenhum livro alugado!" << endl;
    cout << endl;
  }else {
  	cout << "Listagem de todos os livros alugados: " << endl;
    cout << endl;
  	for (auto it = bookings.begin(); it != bookings.end(); it++)
    {
  		vector<Booking *> book = it->second;
      for(auto it1 = book.begin(); it1 != book.end(); it1 ++)
      {
        Book *livros = *it1;
        livros->toString();
      }
      cout << endl;
    }
	}
}

//remove emprestimo de um usuario
void BookManager::removeBooking(User* client, string isbn)
{
  string nome = client->getLogin();
  for(auto it = bookings.begin(); it != bookings.end(); it++)
  {
    if(it->first == nome)
    {
      vector <Booking *> livro = it->second;
      for(auto it1 = livro.begin(); it1 != livro.end(); it1++)
      {
        Book * alugado = *it1;
        if(alugado->getIsbn()==isbn)
        {
          livro.erase(it1);
        }
      }
    }
  }
}

void BookManager::printBookingsuser(User* client)
{
  string nome = client->getLogin();
  for(auto it = bookings.begin(); it != bookings.end(); it++)
  {
    if(it->first == nome)
    {
      vector <Booking *> livro = it->second;
      for(auto it1 = livro.begin(); it1 != livro.end(); it1++)
      {
        Book * alugado = *it1;
        alugado->toString();
      }
    }
  }
}