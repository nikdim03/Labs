#include <fstream>
#include <iostream>
#include <regex>
#include <string>
#include <unordered_set>

void deleteExcessWhitespacesAndInsertSpaceAfterComma(std::string& line) {
  // Delete leading whitespaces
  line.erase(line.begin(), std::find_if(line.begin(), line.end(), [](int ch) {
               return !std::isspace(ch);
             }));
  // Find the position of the first occurrence of ";" in the line
  size_t pos = line.find(";");
  if (pos != std::string::npos) {
    // Erase the whitespaces after ";"
    line.erase(pos + 1, std::string::npos);
  }
  // Iterate through the characters in the line
  size_t i = 0;
  while (i < line.size()) {
    // Replace multiple spaces with a single space
    if (std::isspace(line[i])) {
      size_t j = i + 1;
      while (j < line.size() && std::isspace(line[j])) {
        line.erase(j, 1);
      }
      line[i] = ' ';
    }
    // Insert a single space after "," if there are no more spaces
    else if (line[i] == ',') {
      size_t j = i + 1;
      if (j == line.size() || !std::isspace(line[j])) {
        line.insert(j, " ");
      }
    }
    // Delete whitespaces after ")" and "("
    else if (line[i] == ')' || line[i] == '(') {
      size_t j = i + 1;
      while (j < line.size() && std::isspace(line[j])) {
        line.erase(j, 1);
      }
      // Delete whitespaces before ")" and "("
      size_t k = i - 1;
      while (k > 0 && std::isspace(line[k])) {
        line.erase(k, 1);
      }
    }
    ++i;
  }
}

void cutCommentsAndStandardize(std::string& line) {
  // Remove comments from the line
  std::regex r1("//.*$");
  std::regex r2("/\\*.*\\*/");
  line = std::regex_replace(line, r1, "");
  line = std::regex_replace(line, r2, "");
  // Delete excess whitespaces and insert space after ","
  deleteExcessWhitespacesAndInsertSpaceAfterComma(line);
}

// Check the balance of parenceses
bool checkParentheses(const std::string& line) {
  size_t leftCount = 0, rightCount = 0;
  for (char c : line)
    if (c == '(')
      leftCount++;
    else if (c == ')')
      rightCount++;
  return leftCount == rightCount;
}

// Check if the modifier is valid
bool checkModifier(std::string modifier, std::string& errorMessage) {
  // Remove whitespaces
  modifier.erase(std::remove(modifier.begin(), modifier.end(), ' '),
                 modifier.end());
  // Use a regular expression to match valid return types
  std::regex r(
      "\\b(unsigned|signed|short|long|volatile|extern|static|inline|restrict|)"
      "\\b");
  if (std::regex_match(modifier, r)) {
    return true;
  } else {
    errorMessage = "Invalid modifier";
    return false;
  }
}

// Check if the return type is valid
bool checkReturnType(std::string returnType, std::string& errorMessage) {
  // Use a regular expression to match valid return types
  std::regex r(
      "\\b(string|void|int|float|double|char|bool|short|long|unsigned|signed|"
      "size_t)"
      "\\b");
  if (std::regex_match(returnType, r)) {
    return true;
  } else {
    errorMessage = "Invalid return type";
    return false;
  }
}

// Check if the function name is valid
bool checkFunctionName(std::string functionName, std::string& errorMessage) {
  // Use a regular expression to match valid function names
  std::regex r("[a-zA-Z_][a-zA-Z0-9_]*");
  if (std::regex_match(functionName, r)) {
    return true;
  } else {
    errorMessage = "Invalid function name";
    return false;
  }
}

// Check if the parameter list is valid
bool checkParameterList(std::string parameterList, std::string& errorMessage) {
  // Check if the parameter list is empty
  if (parameterList.empty()) return true;
  // Split the parameter list into individual parameters
  std::regex r("\\s*,\\s*");
  std::sregex_token_iterator iter(parameterList.begin(), parameterList.end(), r,
                                  -1);
  std::sregex_token_iterator end;
  std::vector<std::string> parameters(iter, end);
  // Check for duplicate parameter names
  std::unordered_set<std::string> parameterNames;
  for (const auto& parameter : parameters) {
    // Split the parameter into its type and name
    std::regex r("\\s+");
    std::sregex_token_iterator iter(parameter.begin(), parameter.end(), r, -1);
    std::sregex_token_iterator end;
    std::vector<std::string> parameterComponents(iter, end);
    if (parameterComponents.size() != 2) {
      errorMessage = "Invalid parameter structure";
      return false;
    }
    // Check if the parameter name has already been used
    if (parameterNames.count(parameterComponents[1])) {
      errorMessage = "Duplicate parameter name";
      return false;
    }
    parameterNames.insert(parameterComponents[1]);
    // Check if the parameter type is valid
    if (!checkReturnType(parameterComponents[0], errorMessage)) return false;
  }
  // Check if the parameter list ends with a comma
  std::regex r2(",\\s*$");
  if (std::regex_search(parameterList, r2)) {
    errorMessage = "Comma at the end of parameter list";
    return false;
  }
  return true;
}

bool checkFunctionHeader(const std::string& header, std::string& errorMessage) {
  // Regular expression to match the return type, function name, and parameter
  // list
  std::regex rightRegex("(\\w+)\\s+(\\w+)\\(([^\\)]*)\\);");
  std::regex doubleRegex(
      "((?:\\bconst\\b|\\bunsigned\\b|\\bsigned\\b|\\blong\\b|\\bshort\\b)\\s+)"
      "?(\\b(void|"
      "int|float|double|char|bool|short|size_t)\\b)\\s+(\\w+)\\(([^\\)]*)\\);");
  std::regex noRight("(\\w+)\\s+(\\w+)\\(([^\\)]*)");
  std::regex noSemi("(\\w+)\\s+(\\w+)\\(([^\\)]*)\\)");
  std::regex noType("(\\w+)\\(([^\\)]*)\\);");
  std::regex noTypeNoSemi("(\\w+)\\(([^\\)]*)\\)");
  std::regex noName("(\\w+)\\s+\\(([^\\)]*)\\)");
  std::regex noNameNoSemi("(\\w+)\\s+\\(([^\\)]*)\\);");
  std::regex noList("(\\w+)\\s+(\\w+)\\(\\);");
  std::regex noListNoSemi("(\\w+)\\s+(\\w+)\\(\\)");
  std::regex notFormattedList("(\\w+)\\s+(\\w+)\\(([^\\)]*)[^\\)]\\);");
  std::regex notFormattedListNoSemi("(\\w+)\\s+(\\w+)\\(([^\\)]*)[^\\)]\\)");

  // Use the regular expression to split the header into its individual
  // components
  std::smatch m;
  if (std::regex_match(header, m, rightRegex)) {
    // The header is valid
    std::string returnType = m[1];
    std::string functionName = m[2];
    std::string parameterList = m[3];
    if (checkReturnType(returnType, errorMessage) &&
        checkFunctionName(functionName, errorMessage) &&
        checkParameterList(parameterList, errorMessage)) {
      return true;
    }
  } else if (std::regex_match(header, m, doubleRegex)) {
    // The header is valid and has double worded type
    std::string modifier = m[1];
    std::string returnType = m[2];
    std::string functionName = m[4];
    std::string parameterList = m[5];
    if (checkModifier(modifier, errorMessage) &&
        checkReturnType(returnType, errorMessage) &&
        checkFunctionName(functionName, errorMessage) &&
        checkParameterList(parameterList, errorMessage)) {
      if (modifier == "short " && returnType == "double" ||
          modifier == "short " && returnType == "long" ||
          modifier == "long " && returnType == "short" ||
          modifier == "short " && returnType == "string" ||
          modifier == "long " && returnType == "float" ||
          returnType == "size_t") {
        errorMessage = "Wrong combination of specifier and return type";
        return false;
      }
      return true;
    }
  } else {
    if (std::regex_match(header, m, noSemi))
      errorMessage = "No semicolon at the end";
    else if (std::regex_match(header, m, noRight))
      errorMessage = "Right parenthesis missing";
    else if (std::regex_match(header, m, noType))
      errorMessage = "No return type";
    else if (std::regex_match(header, m, noTypeNoSemi))
      errorMessage = "No return type, no semicolon at the end";
    else if (std::regex_match(header, m, noName))
      errorMessage = "No function name";
    else if (std::regex_match(header, m, noNameNoSemi))
      errorMessage = "No function name, no semicolon at the end";
    else if (std::regex_match(header, m, noList))
      errorMessage = "No parameter list";
    else if (std::regex_match(header, m, noListNoSemi))
      errorMessage = "No parameter list, no semicolon at the end";
    else if (std::regex_match(header, m, notFormattedList))
      errorMessage = "Incorrectly formatted parameter list";
    else if (std::regex_match(header, m, notFormattedListNoSemi))
      errorMessage =
          "Incorrectly formatted parameter list, no semicolon at the end";
    else if (!checkParentheses(header))
      errorMessage = "Left parenthesis missing";
    else
      errorMessage = "Something utterly disgusting";
  }
  return false;
}

// This function checks if a given string is a valid C++ function header.
// It returns true if the header is valid, or false if it is not.
void checkFunctionHeaders(std::ifstream& file) {
  std::string line;
  // Read each line of the file
  int lineNumber = 1;
  while (std::getline(file, line)) {
    // Check if the line is a function header
    std::string errorMessage;
    cutCommentsAndStandardize(line);
    if (line.length() != 0) {
      if (checkFunctionHeader(line, errorMessage)) {
        std::cout << "\033[32mValid\033[0m function header on line "
                  << "\033[38;2;0;255;255m" << lineNumber << "\033[0m"
                  << ": " << std::endl
                  << line << "\n\n";
      } else {
        std::cout
            << "\033[38;2;255;165;0mInvalid\033[0m function header on line "
            << "\033[38;2;0;255;255m" << lineNumber << "\033[0m"
            << ": " << std::endl
            << line << std::endl;
        std::cout << "\033[38;2;255;0;0mError:\033[0m " << errorMessage
                  << "\n\n";
      }
    }
    lineNumber++;
  }
}

int main(int argc, char* argv[]) {
  if (argc == 2) {
    // Open the file
    std::ifstream file(argv[1]);
    // Check if the file was successfully opened
    if (!file.is_open()) {
      std::cerr << "\033[38;2;255;0;0mError:\033[0m opening file: " << argv[1]
                << std::endl;
      exit(1);
    }
    checkFunctionHeaders(file);
  } else {
    std::cerr << "\033[38;2;255;0;0mUsage:\033[0m ./new input.txt" << std::endl;
    exit(1);
  }
  return 0;
}
