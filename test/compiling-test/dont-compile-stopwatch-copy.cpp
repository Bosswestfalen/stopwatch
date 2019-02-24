#include "bosswestfalen/stopwatch.hpp"
#include <utility>


int main()
{
    unsigned i{0};
    bosswestfalen::stopwatch a{i};
    bosswestfalen::stopwatch b{std::move(a)};
}

