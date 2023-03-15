//
// Created by yot on 25/02/23.
//

#include <fstream>
#include "ConfigHelper.h"

bool ConfigHelper::Initialize() {
    // Load JSON and parse its info
    std::ifstream f("Assets/config.json");
    data = json::parse(f);
    return true;
}

int ConfigHelper::GetThing() {
    return data.at("thing");
}

void ConfigHelper::SaveJson() {
    std::ofstream file("Assets/config.json");
    file << std::setw(4) << data << std::endl;
    file.flush();
}

