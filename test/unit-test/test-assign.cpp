#include <catch/catch.hpp>
#include <bosswestfalen/stopwatch.hpp>

SCENARIO("assign to variable", "[assign]")
{
    GIVEN("an unsigned int")
    {
        constexpr unsigned Init{0};
        unsigned i{Init};

        WHEN("the stopwatch gets out of scope")
        {
            {
                bosswestfalen::stopwatch sw{i};
            }

            THEN("the unsigned int is set")
            {
                REQUIRE(i not_eq Init);
            }
        }
    }
}

