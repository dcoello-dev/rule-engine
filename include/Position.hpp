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

    void set_pos(
            uint32_t x,
            uint32_t y) noexcept
    {
        X_ = x;
        Y_ = y;
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

    PlTermv get_position_tm()  noexcept
    {
        PlTermv tm(3);
        (void)tm[0].unify_string(tag_.c_str());
        (void)tm[1].unify_integer(X_);
        (void)tm[2].unify_integer(Y_);
        return tm;
    }

    bool sync_with_knowledge_base() noexcept
    {
        bool ret = false;
        PlTermv pos = get_position_tm();
        PlQuery q("add_POI", pos);
        while ( q.next_solution())
        {
            ret = true;
        }
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