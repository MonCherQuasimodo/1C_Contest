#include <iostream>

#include "Solution/Solution.h"

void solve() {
    std::cout << "Type in path of file.txt\n";

    std::string filename;
    std::cin >> filename;

    std::ifstream file(filename);
    if (file.fail()) {
        std::cout << "Some error with opening file, remember: current directory - build\n";
        std::cout << "Put full path or use ../ or place file.txt in build folder\n";
        std::cout << "Sorry :(\n";
        return;
    }

    Solution<DataBaseUnMap> solution(file);

    std::cout << "Type in count of requests\n";

    unsigned int count_request;
    std::cin >> count_request;

    std::cout << "Type in requests:\n";

    for (unsigned int i = 0; i < count_request; ++i) {
        std::string input_key;
        std::cin >> input_key;

        std::optional<PosType> position = solution.request(input_key);
        if (position.has_value()) {
            std::cout << "The required sequence starts at " << position.value() << " word\n";
        } else {
            std::cout << "No suitable sequence\n";
        }
    }

    file.close();
}

int main() {
    solve();
    return 0;
}
