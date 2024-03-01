#include <iostream>
#include <unordered_map>
#include <vector>

struct Ship {
  std::vector<float> properties;
  float score = 0;
};

class BestShip {
public:
  void read_table();
  void print_weight_index() const;
  void print_all_ships() const;
  void output() const;
  void select_and_solve();

private:
  void calc_score();

  void analyze_weight(const std::string &weight_name, const std::string &msg);
  std::unordered_map<std::string, const int> weight_name_to_index;
  std::unordered_map<std::string, const int> ship_name_to_index;
  std::vector<float> weight;
  std::vector<Ship> AllShip;
  int weight_number = 0;
  int ship_number = 0;
  bool first_read = true;
};

void BestShip::print_weight_index() const {
  for (const auto &iter : weight_name_to_index) {
    std::cout << iter.first << ' ' << iter.second << '\n';
  }
}

void BestShip::print_all_ships() const {
  for (const auto &iter : ship_name_to_index) {
    std::cout << iter.first << ' ' << iter.second << '\n';
  }
}

void BestShip::analyze_weight(const std::string &weight_name,
                              const std::string &msg) {
  const auto pos = msg.find('=');
  if (pos == std::string::npos) {
    std::cerr << "Invalid Number\n";
    exit(-1);
  }
  float weight_value = std::stof(msg.substr(pos + 1));

  weight_name_to_index.insert({weight_name, weight_number++});
  weight.push_back(weight_value);
}

void BestShip::read_table() {
  std::string weight_name;
  std::string msg;
  std::cin >> weight_name >> msg;
  analyze_weight(weight_name, msg);
  std::string ship_name;
  float value{};

  std::cin.clear();
  while (std::cin >> ship_name) {
    std::cin >> value;

    if (first_read) {
      // 还没有将这个name加入映射之中
      ship_name_to_index.insert({ship_name, ship_number++});
      // 还没有构造足够的ship
      AllShip.emplace_back();
    }
    const auto cur_index = ship_name_to_index[ship_name];
    // 添加当前属性的值
    AllShip[cur_index].properties.push_back(value);
  }
}

int main() {
  BestShip T;
  T.read_table();
  T.print_weight_index();
  T.print_all_ships();
}
