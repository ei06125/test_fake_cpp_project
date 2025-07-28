#if defined __has_include
#  if __has_include(<print>)
#    include <print>
namespace mystd = std;
#  else
#    include <format>
#    include <iostream>
#    define USE_MYSTD
#  endif
#else
#  include <format>
#  include <iostream>
#  define USE_MYSTD
#endif

#ifdef USE_MYSTD
namespace mystd {

template <typename... Args>
inline void println(const std::format_string<Args...> fmt, Args &&...args) {
  std::cout << std::vformat(fmt.get(), std::make_format_args(args...)) << '\n';
}
} // namespace mystd
#endif // USE_MYSTD

#include <string>

#include <fake/fake.hpp>

int main() {
  mystd::println("{}", std::string(80, '='));
  mystd::println("Running fake_cpp_project tests");
  mystd::println("{}", std::string(80, '='));

  // get_value
  mystd::println("{}", std::string(80, '-'));
  mystd::println("Running fake_cpp_project get_value tests");
  constexpr std::string_view test_name = "get_value returns 42: ";
  mystd::println("{}{:>{}}", test_name,
                 (42 == fake::get_value() ? "PASSED" : "FAILED"),
                 80 - test_name.size());
  mystd::println("{}", std::string(80, '-'));

  return 0;
}
