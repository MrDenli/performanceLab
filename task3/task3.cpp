#include <iostream>
#include <fstream>
#include <map>
#include <nlohmann/json.hpp>

using json = nlohmann::json;
using namespace std;

void fill_values(json& test, const map<int, string>& value_map) {
    if (test.contains("id") && value_map.count(test["id"].get<int>())) {
        test["value"] = value_map.at(test["id"]);
    }
    if (test.contains("values") && test["values"].is_array()) {
        for (auto& sub_test : test["values"]) {
            fill_values(sub_test, value_map);
        }
    }
}

int main(int argc, char* argv[]) {
    ifstream values_file(argv[1]);
    json values_json;
    values_file >> values_json;
    values_file.close();

    map<int, string> value_map;
    for (const auto& val : values_json["values"]) {
        value_map[val["id"].get<int>()] = val["value"].get<string>();
    }

    ifstream tests_file(argv[2]);
    json tests_json;
    tests_file >> tests_json;
    tests_file.close();

    if (tests_json.contains("tests") && tests_json["tests"].is_array()) {
        for (auto& test : tests_json["tests"]) {
            fill_values(test, value_map);
        }
    }

    ofstream report_file(argv[3]);
    report_file << tests_json.dump(2);
    report_file.close();

    return 0;
}