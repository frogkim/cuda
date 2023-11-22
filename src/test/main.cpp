#include "test_header.h"
#include <time.h>

int main()
{
    struct timespec t_start, t_end;
    
    time_t sec;
    long nano;
    
    const int arraySize = 5;
    const int a[arraySize] = { 1, 2, 3, 4, 5 };
    const int b[arraySize] = { 1, 2, 3, 4, 5 };
    int c[arraySize] = { 0 };
    int d[arraySize] = { 0, 0, 0, 0, 0 };
    bool ret;

    (void)timespec_get(&t_start, TIME_UTC);
    // Add vectors in parallel.
    for (int i = 0; i < 50000; i++)
    {
        ret = addWithCuda(c, a, b, arraySize);
        if (!ret) {
            fprintf(stderr, "addWithCuda failed!");
            return 1;
        }
    }
    (void)timespec_get(&t_end, TIME_UTC);
    t_end.tv_sec -= t_start.tv_sec;
    t_end.tv_nsec -= t_start.tv_nsec;
    if (t_end.tv_nsec < 0) {
        t_end.tv_nsec += 1000000000;
        t_end.tv_sec -= 1;
    }
    printf("sec: %lld, nano: %ld\n", t_end.tv_sec, t_end.tv_nsec);

    printf("{1,2,3,4,5} + {10,20,30,40,50} = {%d,%d,%d,%d,%d}\n",
        c[0], c[1], c[2], c[3], c[4]);

    (void)timespec_get(&t_start, TIME_UTC);
    for (int i = 0; i < 50000; i++)
    {
        ret = addWithCuda(d, a, d, arraySize);
        if (!ret) {
            fprintf(stderr, "addWithCuda failed!");
            return 1;
        }
    }
    (void)timespec_get(&t_end, TIME_UTC);
    t_end.tv_sec -= t_start.tv_sec;
    t_end.tv_nsec -= t_start.tv_nsec;
    if (t_end.tv_nsec < 0) {
        t_end.tv_nsec += 1000000000;
        t_end.tv_sec -= 1;
    }
    printf("sec: %lld, nano: %ld\n", t_end.tv_sec, t_end.tv_nsec);

    printf("{%d,%d,%d,%d,%d}\n",
        d[0], d[1], d[2], d[3], d[4]);


    // cudaDeviceReset must be called before exiting in order for profiling and
    // tracing tools such as Nsight and Visual Profiler to show complete traces.
    ret = DeviceReset();
    if (!ret) {
        fprintf(stderr, "cudaDeviceReset failed!");
        return 1;
    }

    return 0;
}
