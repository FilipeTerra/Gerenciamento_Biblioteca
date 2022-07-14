#include "../third_party/doctest.h"
#include "../include/user.hpp"
#include <exception>

TEST_CASE("chamadas do usuario") {
  User* sample = new User("Sample", "senha");
  CHECK_EQ("Sample", sample->getLogin());
  CHECK_EQ("senha", sample->getPassword());
  CHECK_EQ(true, sample->getStatus());
}
