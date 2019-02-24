#include "bosswestfalen/stopwatch.hpp"


struct test final
{
    void operator()(bosswestfalen::time_type const) noexcept
    {
    };
};


int main()
{
    bosswestfalen::stopwatch x{test{}};
}

