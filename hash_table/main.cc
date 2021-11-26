#include "./hash_table.h"
#include "./hash_table_tests.h"
#include <unordered_map>


void stdlib_experiments()
{
    std::unordered_map<std::string, std::string> states;

    states["Texas"] = "Austin";
    states["Florida"] = "Tallahassee";
    states["Washington"] = "Olympia";

    for (auto it = states.begin(); it != states.end(); ++it) {
        std::cout << "The capital of " << it->first << " is " << it->second << std::endl;
    }

    auto iter = states.find("Oregon");
    if (iter == states.end()) {
        std::cout << "Oregon not found" << std::endl;
    }

    for (int i = 0; i < states.bucket_count(); ++i) {
        std::cout << "Size of bucket " << i << ": " << states.bucket_size(i) << std::endl;
    }
}

int main(int argc, char *argv[])
{
    run_all_tests();

    stdlib_experiments();
    return 0;
}
