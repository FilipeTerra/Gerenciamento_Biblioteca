#include "../third_party/doctest.h"
#include "../include/userManager.hpp"
#include <exception>

TEST_CASE("chamadas do user manager") {
  UserManager* manager = new UserManager();
  User* sample = new User("Sample", "senha");
  manager->registration("Sample", "senha");
  
  CHECK_EQ("senha", sample->getPassword());
  CHECK_EQ(1, manager->getCostumers().size());
  CHECK_EQ(false, manager->findCostumer("Inexistente"));
  CHECK_EQ(true, manager->findCostumer("Sample"));
}
