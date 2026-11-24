#pragma once


class Map final
{

    public:

        Map() = delete;
        Map(const Map&) = delete;
        Map(Map&& other) noexcept = default;

        ~Map() noexcept = default;

        Map& operator=(const Map&) = delete;
        Map& operator=(Map&& other) noexcept = default;


    private:

};
