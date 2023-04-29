add_library(TaskMaster src/Project/ProjectController.cpp
                        src/Project/ProjectRepo.cpp
                        src/Board/BoardController.cpp
                        src/Board/BoardRepo.cpp
                        src/Task/TaskController.cpp
                        src/Task/TaskRepo.cpp
                        src/User/UserController.cpp
                        src/User/UserRepo.cpp)

target_include_directories(TaskMaster PUBLIC include/Project include/Board include/Task include/User)

if(BUILD_TESTS)
  add_subdirectory(tests)
endif()
