/*!
 * \file stopwatch.hpp
 * \author Bosswestfalen (https://github.com/Bosswestfalen)
 * \version 0.0.1
 * \date 2019
 * \copyright MIT License
 */


#ifndef BOSSWESTFALEN_STOPWATCH_HPP_
#define BOSSWESTFALEN_STOPWATCH_HPP_


#include <chrono>
#include <type_traits>


/*!
 * \brief namespace for Bosswestfalen
 * \see https://github.com/Bosswestfalen
 */
namespace bosswestfalen
{
/// Type alias for ticks.
using time_type = decltype (std::chrono::high_resolution_clock::now().time_since_epoch().count());

/*!
 * \brief Stopwatch
 *
 * The stopwatch measures the time of its existence, by calculating 
 * the elapsed time between construction and destruction.
 * A "target" of type T is then called (in case of a callable) with or assigned to (in case of a variable)
 * the duration.
 *
 * \tparam T Type of the target.
 * \tparam R Time resolution, default is std::chrono::nanoseconds
 *
 * \attention T must fulfil one of the following requirements:
 *            \li \c std::is_nothrow_assignable_v<T&, time_type>
 *            \li \c std::is_nothrow_invocable_v<T&, time_type>
 *
 *            If more than one requirement is met, the first matching one will be used.
 *
 * \todo Add support for rvalue invocable.<br/>
 *       Example: \c bosswestfalen::stopwatch sw{[](bosswestfalen::time_type const time) { process time }};
 */
template <typename T,
          typename R = std::chrono::nanoseconds>
class stopwatch final
{
    static_assert(std::is_nothrow_assignable_v<T&, time_type>
                  or std::is_nothrow_invocable_v<T&, time_type>);

  public:
    /*!
     * \brief Start time measurement.
     *
     * \param target The "target" of the measured time.
     */
    explicit stopwatch(T& target) noexcept
    : m_target{target},
      m_start{std::chrono::high_resolution_clock::now()}
    {
    }

    /*!
     * \brief Stop time measurement.
     */
    ~stopwatch() noexcept
    {
        auto const end = std::chrono::high_resolution_clock::now();
        auto const duration = std::chrono::duration_cast<R> (end - m_start).count();

        if constexpr (std::is_nothrow_assignable_v<T&, time_type>)
        {
            m_target = duration;
        }
        else // std::is_nothrow_invocable_v == true
        {
            m_target(duration);
        }
    }

    /// Disable copy to avoid double use of "target".
    stopwatch(stopwatch const&) = delete;

    /// Disable move to avoid double use of "target".
    stopwatch(stopwatch&&) = delete;

    /// Disable copy assignment to avoid double use of "target".
    stopwatch& operator=(stopwatch const&) = delete;

    /// Disable move assignment to avoid double use of "target".
    stopwatch& operator=(stopwatch&&) = delete;

  private:
    /// Target of the measured time.
    T& m_target;

    /// Time point of construction.
    decltype(std::chrono::high_resolution_clock::now()) const m_start;
};
}

#endif

