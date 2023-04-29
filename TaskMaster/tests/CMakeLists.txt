add_executable(TaskMasterTest Project/ProjectControllerTest.cpp Project/ProjectRepoTest.cpp 
                                Board/BoardControllerTest.cpp
                                Board/BoardRepoTest.cpp
                                Task/TaskControllerTest.cpp
                                Task/TaskRepoTest.cpp
                                User/UserControllerTest.cpp
                                User/UserRepoTest.cpp)
                              
target_link_libraries(TaskMasterTest TaskMaster
                                    GTest::gtest_main
                                    GTest::gmock)
                                            

add_test(TaskMasterTest TaskMasterTest)
