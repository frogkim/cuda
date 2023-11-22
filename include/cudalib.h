#ifndef CUDALIB_H_
#define CUDALIB_H_

#ifdef CUDALIB_EXPORT
#define CUDALIB __declspec(dllexport)
#else
#define CUDALIB __declspec(dllimport)
#endif
extern "C" 
{
    CUDALIB bool DeviceReset(void);
    CUDALIB bool addWithCuda(int* c, const int* a, const int* b, unsigned int size);
}
#endif