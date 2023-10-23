#include <iostream>
#include <map>
#include <string>
int main() {
  auto team_scores = std::map<std::string, int>{{"Blue", 0}, {"Yellow", 0}};
  team_scores["Blue"] = 10;
  team_scores["Yellow"] = 50;

  auto team_name = std::string{"Blue"};
  auto score = team_scores[team_name];

  std::cout << "The score for " << team_name << " is: " << score << std::endl;

  return 0;
}
