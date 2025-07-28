cmake_minimum_required(VERSION 3.22)
project(test_fake_cpp_project)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQURED ON)

set(FAKE_CPP_PROJECT_BRANCH main CACHE STRING "The branch to download" FORCE)
include(FetchContent)
FetchContent_Declare(
  fake_cpp_project
  GIT_REPOSITORY https://github.com/ei06125/fake_cpp_project.git
  GIT_TAG ${FAKE_CPP_PROJECT_BRANCH}
)
FetchContent_MakeAvailable(fake_cpp_project)

add_executable(test_fake_cpp)
file(GLOB_RECURSE test_fake_cpp_SOURCES "tests/*.cpp")
target_sources(test_fake_cpp PRIVATE ${test_fake_cpp_SOURCES})
target_compile_features(test_fake_cpp PRIVATE cxx_std_23)
target_link_libraries(test_fake_cpp PRIVATE FAKE::fake_cpp_lib)
