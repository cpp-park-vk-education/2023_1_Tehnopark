#include <iostream>
#include <memory>
#include "DbDriver.hpp"
#include "BoardRepo.hpp"
#include "BoardController.hpp"
#include "UserController.hpp"
#include "UserRepo.hpp"

int main()
{
    auto db = std::make_shared<DbDriver>("hostaddr=95.165.158.58 port=28009 dbname=taskmanagerrepo user=umlaut-super password=0FNYiW}GwcaSfMh");
    auto repo = std::make_unique<BoardRepo>(db);
    return 0;
}