#include <bosswestfalen/stopwatch.hpp>

struct test final
{
    test& operator=(bosswestfalen::time_type const)
    {
        return *this;
    }
};

int main()
{
    test tmp;
    bosswestfalen::stopwatch x{tmp};
}

