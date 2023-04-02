#pragma once

#include "SWI-cpp2.h"

class RuleEngine
{
public:

    RuleEngine() = default;

    bool check () noexcept
    {
        PlTermv alert(2);
        PlQuery q("collision_alert", alert);
        while ( q.next_solution())
        {
            std::cout << "COLLISION ALERT:" << alert[0].as_string() << " -> " << alert[1].as_string() << std::endl;
        }
        return true;
    }

};