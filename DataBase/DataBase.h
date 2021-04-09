#pragma once

#include "../ForwardDeclaration.h"

#include <deque>
#include <fstream>
#include <functional>
#include <iostream>
#include <optional>
#include <string>
#include <unordered_map>
#include <utility>

class DataBaseUnMap {
 public:
    using HashType = int;

    bool is_contained(const std::string&);
    void add_key(const std::string&, PosType);
    std::optional<PosType> get_pos(const std::string& key);
 private:
    HashType hash_(const std::string&);
    std::unordered_map<HashType, PosType> un_map_;
};
