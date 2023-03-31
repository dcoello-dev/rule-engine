#include "SWI-cpp2.h"
#include <iostream>
#include <vector>

#include <Position.hpp>

int main(
        int argc,
        char** argv)
{
    PlEngine e(argv[0]);

    Position current{"current", 2, 2};

    std::cout << current.to_string() << std::endl;

    std::vector<std::string> locations = current.is_close_to();

    std::cout << "Close to:" << std::endl;
    for (auto& loc: locations)
    {
        std::cout << "\t" << Position::position_from_tag(loc).to_string() << std::endl;
    }

    return 0;
}