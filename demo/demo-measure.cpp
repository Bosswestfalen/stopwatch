#include <bosswestfalen/stopwatch.hpp>
#include <iostream>
#include <cmath>


unsigned recursive_fibonacci(unsigned const n)
{
    if (n == 0)
    {
        return 0;
    }

    if (n < 3)
    {
        return 1;
    }

    return recursive_fibonacci(n - 1) + recursive_fibonacci(n - 2);
}

unsigned approx_fibonacci(unsigned const n, unsigned& time)
{
    bosswestfalen::stopwatch sw{time};

    auto constexpr r_five{std::sqrt(5.0)};
    auto constexpr r_five_inv{1.0 / r_five};
    auto constexpr base{(1.0 + r_five) / 2.0};

    return std::round(r_five_inv * std::pow(base, n));
}

int main()
{
    auto constexpr N{10u};

    unsigned recursive_time{0};
    unsigned result{0};

    [&]()
    {
        bosswestfalen::stopwatch sw{recursive_time};
        result = recursive_fibonacci(N);
    }();
    std::cout << "fib(" << N << ") = " << result << ", took: " << recursive_time << std::endl;

    unsigned approx_time{0};
    result = approx_fibonacci(N, approx_time);
    std::cout << "fib'(" << N << ") = " << result << ", took: " << approx_time << std::endl;
}
