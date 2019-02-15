#include <stopwatch.hpp>

int main()
{
    auto test = [](bosswestfalen::time_type const) noexcept
    {
    };

    bosswestfalen::stopwatch x{test};
}
