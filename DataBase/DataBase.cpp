#include "DataBase.h"

bool DataBaseUnMap::is_contained(const std::string & key) {
    return un_map_.find(hash_(key)) != un_map_.end();
}

void DataBaseUnMap::add_key(const std::string& key, PosType pos) {
    if (!is_contained(key)) {
        un_map_.insert({hash_(key), pos});
    }
}

std::optional<PosType> DataBaseUnMap::get_pos(const std::string& key) {
    return is_contained(key) ? std::optional<PosType>(un_map_[hash_(key)]) : std::nullopt;
}

DataBaseUnMap::HashType DataBaseUnMap::hash_(const std::string& key) {
    return std::hash<std::string>{}(key);
}
