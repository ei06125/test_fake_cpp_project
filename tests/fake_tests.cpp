#include <print>

#include <fake/fake.hpp>

int main() {
  std::println("{}", std::string(80, '='));
  std::println("Running fake_cpp_project tests");
  std::println("{}", std::string(80, '='));

  // get_value
  std::println("{}", std::string(80, '-'));
  std::println("Running fake_cpp_project get_value tests");
  constexpr std::string_view test_name = "get_value returns 42: ";
  std::println("{}{:>{}}", test_name, (42 == fake::get_value() ? "PASSED" : "FAILED"),
               80 - test_name.size());
  std::println("{}", std::string(80, '-'));

  return 0;
}
