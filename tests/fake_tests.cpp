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

int main() { return 42 == fake::get_value() ? 0 : 1; }
