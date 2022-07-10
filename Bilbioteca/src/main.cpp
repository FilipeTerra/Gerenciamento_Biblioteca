#include "user.hpp"
#include "userManager.hpp"
#include "library.hpp"
#include "bookManager.hpp"
#include "book.hpp"
#include "booking.hpp"


int main() {
  Library *biblioteca = new Library();
  biblioteca->init();
  return 0;
}