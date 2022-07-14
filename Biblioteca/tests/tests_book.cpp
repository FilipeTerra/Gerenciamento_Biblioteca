#include "../third_party/doctest.h"
#include "../include/book.hpp"
#include <exception>

TEST_CASE("chamadas do book") {
  Book* sample = new Book("0123456789", "HarryPotter", "Mago");
  CHECK_EQ("0123456789", sample->getIsbn());
  CHECK_EQ("HarryPotter", sample->getTitle());
  CHECK_EQ("Mago", sample->getAuthor());
  CHECK_EQ(true, sample->getStatus());
  CHECK_EQ(!false, sample->getStatus());
}
