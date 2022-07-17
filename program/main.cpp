#include "../include/user.hpp"
#include "../include/userManager.hpp"
#include "../include/library.hpp"
#include "../include/bookManager.hpp"
#include "../include/book.hpp"
#include "../include/booking.hpp"

int main() {
  Library *biblioteca = new Library();
  biblioteca->init();
  return 0;
}