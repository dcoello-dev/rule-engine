#pragma once

#include "SWI-cpp2.h"
#include <iostream>
#include <vector>

class Position
{
public:

    Position(
            std::string tag)
        : tag_(tag)
        , X_(0)
        , Y_(0)
    {
    }

    Position(
            std::string tag,
            uint32_t x,
            uint32_t y)
        : tag_(tag)
        , X_(x)
        , Y_(y)
    {
    }

    Position(
            const PlTermv& tm)
        : tag_(tm[0].as_string())
        , X_(tm[1].as_uint32_t())
        , Y_(tm[2].as_uint32_t())
    {
    }

    static Position position_from_tag(
            const std::string& tag) noexcept
    {
        PlTermv target(3);
        (void)target[0].unify_string(tag);
        PlQuery q2("position", target);
        while ( q2.next_solution())
        {
            return Position(target);
        }
        return Position{"invalid"};
    }

    bool get_position_tm(
            PlTermv& tm )  noexcept
    {
        bool ret = true;
        ret &= tm[0].unify_string(tag_.c_str());
        ret &= tm[1].unify_integer(X_);
        ret &= tm[2].unify_integer(Y_);
        return ret;
    }

    std::vector<std::string> is_close_to() noexcept
    {
        PlTermv av(3);
        (void)av[0].unify_integer(X_);
        (void)av[1].unify_integer(Y_);
        PlQuery q("is_close_to", av);

        std::vector<std::string> tags{};
        while ( q.next_solution())
        {
            tags.push_back(av[2].as_string());
        }
        return tags;
    }

    std::string to_string() noexcept
    {
        return tag_ + " (" + std::to_string(X_) + ", " + std::to_string(Y_) + ")";
    }

    std::string tag_;
    uint32_t X_;
    uint32_t Y_;
};