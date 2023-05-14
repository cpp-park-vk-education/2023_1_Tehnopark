CMAKE_MINIMUM_REQUIRED(VERSION 3.1)
set(CMAKE_CXX_STANDARD 17)
Project(TaskMaster)

FIND_PACKAGE(Wt REQUIRED Wt HTTP)

ADD_DEFINITIONS(-DHPDF_DLL)

option(BUILD_TESTS "build tests")

if(BUILD_TESTS)
  enable_testing()
endif()


ADD_EXECUTABLE(taskmaster.wt
  taskmaster.C
  model/src/AuthUser.C
  model/src/Session.C
  view/src/MainView.C
  view/src/LoginWidget.C
)

add_subdirectory(TaskMaster)

target_include_directories(taskmaster.wt PUBLIC model/include view/include)
TARGET_LINK_LIBRARIES(taskmaster.wt
  Wt::Wt
  Wt::HTTP
  Wt::Dbo
  TaskMasterDB
  wtdbopostgres
)
