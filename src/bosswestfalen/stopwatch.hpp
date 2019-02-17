#ifndef BOSSWESTFALEN_STOPWATCH_HPP_
#define BOSSWESTFALEN_STOPWATCH_HPP_

#include <chrono>
#include <type_traits>


namespace bosswestfalen
{

using time_type = decltype (std::chrono::high_resolution_clock::now().time_since_epoch().count());

template <typename T>
class stopwatch final
{
    static_assert(std::is_nothrow_assignable_v<T&, time_type>
                  or std::is_nothrow_invocable_v<T&, time_type>);

  public:
    stopwatch(T& target) noexcept
    : m_target{target},
      m_start{std::chrono::high_resolution_clock::now()}
    {
    }

    ~stopwatch() noexcept
    {
        auto const end = std::chrono::high_resolution_clock::now();
        auto const duration = std::chrono::duration_cast<std::chrono::nanoseconds> (end - m_start).count();

        if constexpr (std::is_nothrow_assignable_v<T&, time_type>)
        {
            m_target = duration;
        }
        else // std::is_nothrow_invocable_v == true
        {
            m_target(duration);
        }
    }

  private:
    T& m_target;
    decltype(std::chrono::high_resolution_clock::now()) const m_start;
};
}

#endif

