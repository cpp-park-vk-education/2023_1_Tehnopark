#include <iostream>
#include <memory>
#include "MainPadge/MainPadgeController.hpp"
#include "Project/ProjectRepo.hpp"
#include "DbDriver/DbDriver.hpp"

int main()
{
    auto db = std::make_shared<DbDriver>("hostaddr=192.168.137.1 port=5432 dbname=taskmanager user=postgres password=1474");
    auto repo = std::make_unique<ProjectRepo>(db);
    MainPadgeController mp(std::move(repo));
    std::vector<Project> res = mp.GetUserProjects(1);

    for (const auto &project : res)
    {
        std::cout << project.Name << std::endl;
    }
    return 0;
}