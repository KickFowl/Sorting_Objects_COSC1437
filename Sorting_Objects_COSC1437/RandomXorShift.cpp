#include "RandomXorShift.h"

uint32_t RandomXorShift::xorshift32() {
    uint32_t x = state;
    x ^= x << 13;
    x ^= x >> 17;
    x ^= x << 5;
    state = x;
    return x;
}

uint32_t RandomXorShift::get_time_seed()
{
    auto now = std::chrono::system_clock::now().time_since_epoch();

    // Use nanoseconds or microseconds for high variability
    auto ns = std::chrono::duration_cast<std::chrono::nanoseconds>(now).count();

    // Cast to uint32_t (will safely truncate the upper bits)
    return static_cast<uint32_t>(ns);
}

RandomXorShift::RandomXorShift()
{
    state = get_time_seed();
}

RandomXorShift::RandomXorShift(uint32_t seed) : state(seed)
{}

int RandomXorShift::getRandomRange(int min, int max) {
    uint32_t raw = xorshift32();
    return min + (raw % (max - min + 1));
}