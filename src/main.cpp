#include <iostream>
#include <memory>
#include "TaskRepo.hpp"
#include "DbDriver.hpp"

int main()
{
    //char* argvDebug[] = {"./taskmaster.wt", "--docroot", "../", "--approot", "../", "--http-listen", "0.0.0.0"};
    //Wt::WServer server(7, argvDebug, WTHTTP_CONFIGURATION);
    auto db = std::make_shared<DbDriver>("hostaddr=95.165.158.58 port=28009 dbname=taskmanagerrepo user=umlaut-super password=");
    auto repo = std::make_unique<TaskRepo>(db);

    auto task = Task(1, "wash dishes", "need to wash all dishes");
    //std::cout<<(repo->CreateTask(task));
    auto res = repo->GetAllTasksForBoard(1);
    for(int i = 0; i<res.size(); ++i)
        std::cout<<res[i].Name<<" a ";
    res[0].Name="clean room";
    std::cout<<res[0].Name<<res[0].Id;
    repo->EditTask(res[0]);
    auto res2 = repo->GetAllTasksForBoard(1);
    for(int i = 0; i<res.size(); ++i)
        std::cout<<res2[i].Name<<res2[i].Id;
    return 0;
}