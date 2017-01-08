#include "Timer.hpp"

using namespace std::chrono;

Timer::Timer(const TimerPrecision precision)
    : m_initialTime(high_resolution_clock::now()), 
    m_precision(precision)
{
}

void Timer::setPrecision(const TimerPrecision precision)
{
    m_precision = precision;
}

void Timer::reset()
{
    m_initialTime = high_resolution_clock::now();
}

long long Timer::getTime() const
{
    const auto timeNow = high_resolution_clock::now();
    const auto difference = timeNow - m_initialTime;

    switch (m_precision)
    {
    case TimerPrecision::NANOSECONDS: 
        return duration_cast<nanoseconds>(difference).count();

    case TimerPrecision::MICROSECONDS:
        return duration_cast<microseconds>(difference).count();

    case TimerPrecision::MILLISECONDS:
        return duration_cast<milliseconds>(difference).count();

    case TimerPrecision::SECONDS:
        return duration_cast<seconds>(difference).count();

    default:
        return duration_cast<milliseconds>(difference).count();
    }
}
