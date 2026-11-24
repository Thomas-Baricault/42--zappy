#pragma once


#include "Direction.hpp"


class Trantorian final
{

    public:

        Trantorian() = delete;
        Trantorian(const Trantorian&) = delete;
        Trantorian(Trantorian&& aOther) noexcept = default;
        Trantorian(int aTeam) noexcept;

        ~Trantorian() noexcept = default;

        Trantorian& operator=(const Trantorian&) = delete;
        Trantorian& operator=(Trantorian&& aOther) noexcept = default;


    private:

        int mTeam;

        Direction mDirection = Direction::East;

        // 1 food = survive 126 time units
        int mFood = 0;

};
