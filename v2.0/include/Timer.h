#include "Lib.h"

/**
 * @class Timer
 * @brief Laiko matavimo klasė, skirta skaičiuoti programos veikimo laiką.
 *
 * Klasė Timer naudoja high_resolution_clock, leidžiantį tiksliai nustatyti praėjusį laiką. 
 */
class Timer {
  private:
    using hrClock = std::chrono::high_resolution_clock;
    using durationDouble = std::chrono::duration<double>;
    std::chrono::time_point<hrClock> start;
  public:
    Timer() : start{ hrClock::now() } {}
    void reset() {
      start = hrClock::now();
    }
    double elapsed() const {
      return durationDouble (hrClock::now() - start).count();
    }
};