#include "../third_party/doctest.h"
#include "../include/bookManager.hpp"
#include <exception>
#include <string>

TEST_CASE("Testando o book manager") {
  BookManager* manager = new BookManager();
  manager->insertBook("livro1","titulo1","autor1");
  manager->insertBook("livro2","titulo2","autor2");
  CHECK_EQ(false, manager->findBook("ndaeidnaid"));
  CHECK_EQ(true, manager->findBook("livro1"));
  CHECK_EQ(true, manager->findBook("livro2"));
  CHECK_EQ(2,manager->getStand().size());
  CHECK_EQ(0,manager->getBookings().size());
}
