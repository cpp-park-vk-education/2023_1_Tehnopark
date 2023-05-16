#include <iostream>
#include <memory>
#include "DbDriver.hpp"
#include "BoardRepo.hpp"
#include "BoardController.hpp"
#include "UserController.hpp"
#include "UserRepo.hpp"

int main()
{
    auto db = std::make_shared<DbDriver>("hostaddr= port= dbname= user= password=");
    auto repo = std::make_unique<BoardRepo>(db);
    return 0;
}