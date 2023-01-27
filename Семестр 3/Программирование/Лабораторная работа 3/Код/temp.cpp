#include <iostream>
#include <regex>
#include <string>

int main() {
  // The function header string
  std::string header = "int add(int a, int b)";

  // Use a regular expression to extract the return type, function name, and
  // parameter list
  std::regex r("(\\w+)\\s+(\\w+)\\(([^\\)]*)\\)");
  std::smatch m;

  // Extract the parts of the function header
  if (std::regex_match(header, m, r)) {
    // m[1] is the return type, m[2] is the function name, and m[3] is the
    // parameter list
    std::cout << "Return type: " << m[1] << std::endl;
    std::cout << "Function name: " << m[2] << std::endl;
    std::cout << "Parameter list: " << m[3] << std::endl;
  }
  return 0;
}
