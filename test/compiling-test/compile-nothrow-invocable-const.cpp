#include <bosswestfalen/stopwatch.hpp>

struct test final
{
    void operator()(bosswestfalen::time_type const) const noexcept
    {
    }
};

int main()
{
    test const_operator;
    bosswestfalen::stopwatch x{const_operator};

    test const all_const;
    bosswestfalen::stopwatch y{all_const};
}
