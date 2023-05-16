CMAKE_MINIMUM_REQUIRED(VERSION 3.1)
set(CMAKE_CXX_STANDARD 17)
Project(TaskMaster)

FIND_PACKAGE(Wt REQUIRED Wt HTTP)
ADD_DEFINITIONS(-DHPDF_DLL)

option(BUILD_TESTS "build tests")

if(BUILD_TESTS)
  enable_testing()
endif()

add_executable(taskmaster.wt
  taskmaster.C
  model/src/AuthUser.C
  model/src/Session.C
  view/src/MainView.C
  view/src/LoginWidget.C
)
target_include_directories(taskmaster.wt PUBLIC model/include view/include)
target_link_libraries(taskmaster.wt Wt::Wt Wt::HTTP Wt::Dbo TaskMasterDB wtdbopostgres)

add_subdirectory(TaskMaster)
add_executable(main src/main.cpp)
include_directories(TaskMaster/include)
target_link_libraries(main TaskMaster)
