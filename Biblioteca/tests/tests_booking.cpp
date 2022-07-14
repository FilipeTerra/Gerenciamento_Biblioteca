#include "../include/booking.hpp"
#include "../include/user.hpp"
#include "../third_party/doctest.h"
#include <exception>



TEST_CASE("chamadas do booking") {
User *user = new User("Sample", "senha");
Booking *sample = new Booking("0123452", "Boas Praticas em C++", "Author Programador", user);
  CHECK_EQ(user, sample->getClient());
  CHECK_EQ(false, sample->getStatus());
}

TEST_CASE("testar excecoes do booking") {
  User *user = new User("Sample", "senha");
  Booking *sample = new Booking("0123452", "Boas Praticas em C++", "Author Programador", user);
  CHECK_THROWS(sample->setClient(nullptr));
}