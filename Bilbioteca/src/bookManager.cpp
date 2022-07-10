#include "bookManager.hpp"
#include <iostream>

using namespace std;

// construtor do bookmanager
BookManager::BookManager(){
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
    cout << "Insira um Título: " << endl;
    while(title.length() == 0){
      getline(cin, title);
    }
    cout << "Insira um Autor: " << endl;
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
    if(it->first == isbn){
      aux = true;
      break;
    }
  }
  return aux;
}

//ainda precisa implementar
void BookManager::insertBooking(){
  cout << "Inserindo emprestimo" << endl;
}

// ainda precisa implementar
// map<string, Booking*> BookManager::getBookings(){
//}
void BookManager::getBookings() {
  cout << "Get bookings" << endl;
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