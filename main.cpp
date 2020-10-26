#include <iostream>
#include <regex>
#include <string>

int main() {
  int i;
  bool typeA, typeB, check=false;
  std::string input, temp;
  std::string cities[7] = {"Tokyo", "Delhi", "Shanghai", "Sao Paulo", "Mumbai", "Paris", "New York City"};
  input = "input";
  while(input!=""){
  getline (std::cin, input);

  std::smatch m;
  std::regex wCheck ("(weather)(.*)");   
  std::regex factCheck ("(fact)(.*)");
  std::regex amCheck ("(AM)(.*)");
  std:: regex pmCheck ("(PM)(.*)");


  if (std::regex_search (input,m, factCheck)) {
    std::cout << "Intent: Get Fact\n" << std::endl;
  }

  if ((std::regex_search (input,m, amCheck)) ||      (std::regex_search (input,m, pmCheck))) {
    std::cout << "Intent: Check Calendar\n" << std::endl;
  }

  for (i=0;i<7;i++) {
    temp = "(" + cities[i] + ")(.*)";
    std::regex cityCheck (temp);
    typeA=(std::regex_search (input,m, wCheck));
    typeB=(std::regex_search (input,m, cityCheck));
    if (typeA && typeB) {
      std::cout<<"Intent: Get Weather City\n";
      check=true;
      break;
    }
  }

  if (!check && typeA){
    std::cout<<"Intent: Get Weather\n";
  }}
}