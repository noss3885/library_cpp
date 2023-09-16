#include <chrono>

class Timer {
  private:
    std::chrono::system_clock::time_point start_time, end_time;

  public:
    Timer() : start_time(std::chrono::system_clock::now()) {}
    void start() {
        start_time = std::chrono::system_clock::now();
    }
    double elapsed() {
        end_time = std::chrono::system_clock::now();
        return static_cast<double>(std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count());
    }
};