// #include "gmock/gmock.h"
// #include "../models/Project.hpp"
// #include "../Project/ProjectRepoInterface.hpp"

// using namespace testing;

// class MockProjectRepo : public ProjectRepoInterface
// {
// public:
//     MOCK_METHOD(Project, GetProjectById, (int projectId), (override));
//     MOCK_METHOD(void, CreateProject, (int userId), (override));
//     MOCK_METHOD(void, RemoveProjectById, (int projectId), (override));
//     MOCK_METHOD(void, UpdateProject, (const Project &project), (override));
// };

// /* Correct data */

// TEST(ProjectRepoTest, GetProjectByIdTest)
// {
//     MockProjectRepo mockProjectRepo;

//     EXPECT_CALL(mockProjectRepo, GetProjectById(1))
//         .Times(1);

//     mockProjectRepo.GetProjectById(1);
// }

// TEST(ProjectRepoTest, RemoveProjectByIdTest)
// {
//     MockProjectRepo mockProjectRepo;

//     EXPECT_CALL(mockProjectRepo, RemoveProjectById(1))
//         .Times(1);

//     mockProjectRepo.RemoveProjectById(1);
// }

// TEST(ProjectRepoTest, CreateProjectTest)
// {
//     MockProjectRepo mockProjectRepo;

//     EXPECT_CALL(mockProjectRepo, CreateProject(1))
//         .Times(1);

//     mockProjectRepo.CreateProject(1);
// }

// TEST(ProjectRepoTest, UpdateProjectTest)
// {
//     MockProjectRepo mockProjectRepo;
//     Project project(1, "Project Name");

//     EXPECT_CALL(mockProjectRepo, UpdateProject(project))
//         .Times(1);

//     mockProjectRepo.UpdateProject(project);
// }

// /* Incorrect data*/

// TEST(ProjectHandlerTest, GetProjectByIdNegativeProjectIdTest)
// {
//     MockProjectRepo mockProjectHandler;

//     EXPECT_CALL(mockProjectHandler, GetProjectById(_))
//         .Times(0);

//     ASSERT_THROW(mockProjectHandler.GetProjectById(-1), std::invalid_argument);
// }

// // тут ещё тесты можно написать...

// /* Incorrect logic*/

// TEST(ProjectHandlerTest, GetProjectByIdNotFoundTest)
// {
//     MockProjectRepo mockProjectHandler;

//     EXPECT_CALL(mockProjectHandler, GetProjectById(42))
//         .WillOnce(Throw(std::runtime_error("Project not found")));

//     EXPECT_THROW(mockProjectHandler.GetProjectById(42), std::runtime_error);
// }

// // тут ещё тесты можно написать...