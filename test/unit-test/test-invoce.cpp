#include <catch/catch.hpp>
#include <stopwatch.hpp>

SCENARIO("invoce a function", "[invoce]")
{
    GIVEN("a nothrow callable")
    {
        constexpr unsigned Init{0};
        unsigned i{Init};
        auto i_to_time = [&i](bosswestfalen::time_type const in) noexcept
        {
            i = in;
        };

        WHEN("the stopwatch gets out of scope")
        {
            {
                bosswestfalen::stopwatch sw{i_to_time};
            }

            THEN("the function was called")
            {
                REQUIRE(i not_eq Init);
            }
        }
    }
}

