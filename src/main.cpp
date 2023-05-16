#include <iostream>
#include <memory>
#include "MainPadge/MainPadgeController.hpp"
#include "Project/ProjectRepo.hpp"
#include "DbDriver/DbDriver.hpp"

int main()
{
    auto db = std::make_shared<DbDriver>("hostaddr=95.165.158.58 port=28009 dbname=TaskMaster user=umlaut-super password=0FNYiW}GwcaSfMh");
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