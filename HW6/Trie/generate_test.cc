#include <algorithm>
#include <iostream>
#include <vector>

constexpr unsigned SEED = 0;

static std::string random_alphabet_string(const int L = 10) {
  std::string res;
  res.reserve(L);
  int len = rand() % 10 + 1;
  while (len--) {
    const char ch = rand() % 26 + (rand() % 2 ? 'A' : 'a');
    res += ch;
  }
  return res;
}
struct Property {
  float property_weight;
  const std::string property_name;
  Property(const std::string &name, const float w = 0)
      : property_name(name), property_weight(w) {}
};

class RandomTest {
public:
  RandomTest(const int n = 15, const int p = 5) : N_ship(n), N_property(p) {}
  void generate_cases();

private:
  void generate_ship_name();
  void generate_property();
  void generate_table(const Property &property) const;
  std::vector<std::string> ship_name;
  std::vector<Property> property;
  const int N_ship;
  const int N_property;
  static constexpr int property_value_limits = 300;
  static constexpr int weight_value_limits = 30;
};

void RandomTest::generate_ship_name() {
  ship_name.reserve(N_ship);
  for (int i = 0; i < N_ship; i++) {
    auto cur_name = random_alphabet_string();
    while (std::find(ship_name.begin(), ship_name.end(), cur_name) !=
           ship_name.end())
      cur_name = random_alphabet_string();
    ship_name.emplace_back(std::move(cur_name));
  }
}

void RandomTest::generate_property() {
  property.reserve(N_property);

  for (int i = 0; i < N_property; i++) {
    auto cur_name = random_alphabet_string();

    auto p = [&cur_name](const Property &name) {
      return cur_name == name.property_name;
    };
    while (std::find_if(property.begin(), property.end(), p) != property.end())
      cur_name = random_alphabet_string();

    property.emplace_back(cur_name, float(rand() % weight_value_limits));
  }
}

void RandomTest::generate_table(const Property &property) const {
  std::cout << property.property_name << ' ' << property.property_weight
            << std::endl;
  std::vector<bool> chosen(ship_name.size(), false);
  for (int i = 0; i < ship_name.size(); i++) {
    int target = rand() % ship_name.size();
    while (chosen[target]) {
      target = rand() % ship_name.size();
    }
    chosen[target] = true;

    std::cout << ship_name[target] << ' ';
    std::cout << rand() % property_value_limits << std::endl;
  }
  std::cout << "TEND\n" << std::endl;
}

void RandomTest::generate_cases() {
  std::cout << N_property << "\n\n";
  generate_ship_name();
  generate_property();
  for (const auto &prop : property) {
    generate_table(prop);
  }
}
int main() {
  freopen("BestShip.txt", "w", stdout);
  RandomTest T;
  T.generate_cases();
}