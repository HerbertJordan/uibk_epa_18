#pragma once

#include <stdbool.h>

#include <time.h>
#include <unistd.h>

// a small wrapper for convenient time measurements

typedef double timestamp;

timestamp now() {
    struct timespec spec;
    clock_gettime(CLOCK_REALTIME, &spec);
    return spec.tv_sec + spec.tv_nsec / (1e9);
}
