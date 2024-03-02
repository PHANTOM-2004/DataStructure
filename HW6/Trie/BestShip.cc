#include <algorithm>
#include <iomanip>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

class BestShip {
public:
  void read_table();
  void print_weight_index() const;
  void print_all_ships() const;
  void output() const;
  void select_and_solve();

private:
  void calc_score();

  struct Ship {
    std::string ship_name;
    std::vector<float> ship_properties_value;
    float score = 0;
  };

  struct Property {
    float property_weight;
    const std::string property_name;
    Property(const std::string &name, const float w = 0)
        : property_name(name), property_weight(w) {}
  };

  std::unordered_map<std::string, const int> property_name_to_index;
  std::unordered_map<std::string, const int> ship_name_to_index;

  std::vector<Property> properties;
  std::vector<Ship> allships;

  int weight_id = 0;
  int ship_id = 0;
  int max_shipname_length = 0;
  int max_propertyname_length = 0;
  bool first_read = true;
};

void BestShip::output() const {
  using std::setw;
  std::cout << std::setiosflags(std::ios_base::left);
  auto print = [this](const Ship &ship) {
    for (int i = 0; i < properties.size(); i++) {
      std::cout << setw(12) << "p_name : " << setw(max_propertyname_length + 2)
                << properties[i].property_name;
      std::cout << setw(12) << "p_weight : " << setw(5)
                << properties[i].property_weight;
      std::cout << setw(12) << "p_value : " << ship.ship_properties_value[i]
                << "\t";
      std::cout << std::endl;
    }
    std::cout << std::endl;
  };

  for (const auto &iter : allships) {
    std::cout << "Ship name : " << setw(max_shipname_length + 2)
              << iter.ship_name << std::endl;
    std::cout << "Total score : " << iter.score << std::endl;
    print(iter);
  }
}

void BestShip::print_weight_index() const {
  for (const auto &iter : property_name_to_index) {
    std::cout << iter.first << ' ' << iter.second << '\n';
  }
}

void BestShip::print_all_ships() const {
  for (const auto &iter : ship_name_to_index) {
    std::cout << iter.first << ' ' << iter.second << '\n';
  }
}

void BestShip::read_table() {
  std::string property_name;
  float weight{};
  std::cin >> property_name >> weight;
  property_name_to_index.insert({property_name, weight_id++});
  max_propertyname_length =
      std::max(max_shipname_length, (int)property_name.size());
  properties.emplace_back(property_name, weight);

  std::string ship_name;
  float value{};
  std::cin.clear();
  while (std::cin >> ship_name) {
    if (ship_name == "TEND")
      break;
    std::cin >> value;

    if (first_read) {
      // 还没有将这个name加入映射之中
      ship_name_to_index.insert({ship_name, ship_id++});
      // 还没有构造足够的ship
      allships.emplace_back();
      max_shipname_length =
          std::max(max_shipname_length, (int)ship_name.length());
    }
    const auto cur_index = ship_name_to_index[ship_name];
    // 添加当前属性的值
    if (first_read)
      allships[cur_index].ship_name = ship_name;

    allships[cur_index].ship_properties_value.push_back(value);
  }
  if (first_read)
    first_read = false;
}

void BestShip::calc_score() {
  auto calc = [this](Ship &ship) {
    ship.score = 0;
    for (int i = 0; i < ship.ship_properties_value.size(); i++) {
      ship.score +=
          ship.ship_properties_value[i] * properties[i].property_weight;
    }
  };
  std::for_each(allships.begin(), allships.end(), calc);
}

void BestShip::select_and_solve() {
  calc_score();
  auto cmp = [](const Ship &a, const Ship &b) { return a.score > b.score; };
  std::sort(allships.begin(), allships.end(), cmp);
}

int main() {
  freopen("BestShip.txt", "r", stdin);
  BestShip T;
  int N = 0;
  std::cin >> N;
  while (N--) {
    T.read_table();
  }
  T.output();
  std::cout << "\n\n_____________________________________\n\n";

  T.select_and_solve();
  T.output();
  //  T.print_weight_index();
  //  T.print_all_ships();
  // T.output();
}
