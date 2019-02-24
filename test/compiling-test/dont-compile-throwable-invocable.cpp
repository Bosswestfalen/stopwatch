#include "bosswestfalen/stopwatch.hpp"


int main()
{
    auto tmp = [](bosswestfalen::time_type const)
    {
    };

    bosswestfalen::stopwatch x{tmp};
}
