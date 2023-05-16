#include <iostream>
#include <memory>
#include "MainPadgeController.hpp"
#include "ProjectRepo.hpp"
#include "DbDriver.hpp"

int main()
{
    auto db = std::make_shared<DbDriver>("");
    auto repo = std::make_unique<ProjectRepo>(db);
    MainPadgeController mp(std::move(repo));
    // std::vector<Project> res = mp.GetUserProjects(1);

    // for (const auto &project : res)
    // {
    //     std::cout << project.Name << std::endl;
    // }
    // Project pr = mp.GetProjectById(7);
    // std::cout << pr.Name << std::endl;
     mp.CreateProject(2, "CreateUest");
    
    return 0;
}