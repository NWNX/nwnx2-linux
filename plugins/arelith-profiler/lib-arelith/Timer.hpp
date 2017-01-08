#ifndef TIMER_HPP_
#define TIMER_HPP_

#include <chrono>

enum class TimerPrecision
{
    NANOSECONDS,
    MICROSECONDS,
    MILLISECONDS,
    SECONDS
};

class Timer
{
public:
    explicit Timer(const TimerPrecision precision = TimerPrecision::MILLISECONDS);
    void setPrecision(const TimerPrecision precision);
    void reset();
    long long getTime() const;

private:
    std::chrono::high_resolution_clock::time_point m_initialTime;
    TimerPrecision m_precision;
};

#endif // TIMER_HPP_