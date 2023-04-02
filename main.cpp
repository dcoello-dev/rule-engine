#include "SWI-cpp2.h"

#include <cstdlib>
#include <iostream>
#include <vector>
#include <mutex>

#include <Position.hpp>
#include <RuleEngine.hpp>

int main(
        int argc,
        char** argv)
{
    PlEngine e(argv[0]);

    RuleEngine engine{};
    Position robotA{"robotA", 1, 1};
    Position robotB{"robotB", 9, 9};
    Position robotC{"robotC", 5, 5};

    robotA.sync_with_knowledge_base();
    robotB.sync_with_knowledge_base();
    robotC.sync_with_knowledge_base();

    for (int i = 0; i < 10; i++)
    {
        std::cout << "STEP " << i << std::endl;

        robotA.set_pos(i, i);
        robotB.set_pos(i, 10 - i);
        robotC.set_pos(10 - i, 10 - i);

        robotA.sync_with_knowledge_base();
        robotB.sync_with_knowledge_base();
        robotC.sync_with_knowledge_base();

        std::cout << robotA.to_string() << std::endl;
        std::cout << robotB.to_string() << std::endl;
        std::cout << robotC.to_string() << std::endl;

        engine.check();
    }

    return 0;
}