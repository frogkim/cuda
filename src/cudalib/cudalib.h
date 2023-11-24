#ifndef CUDALIB_H_
#define CUDALIB_H_

#ifdef CUDALIB_EXPORT
#ifdef WIN64
#define CUDALIB __declspec(dllexport)
#else
#define CUDALIB __attribute__((visibility("default")))
#endif

#else
#ifdef WIN64
#define CUDALIB __declspec(dllimport)
#else
#define CUDALIB
#endif

#endif  // CUDALIB_EXPORT

// Math library
// Support Target: cuda, x64

extern "C" 
{
    CUDALIB bool isError(void);
    CUDALIB char* getLastErrsorMessage_pChar(void);
    CUDALIB bool DeviceReset(void);
    CUDALIB bool addWithCuda(int* c, const int* a, const int* b, unsigned int size);
    CUDALIB bool addWithCudaBegin(int* out, const int* input_a, const int* input_b, unsigned int size);
    CUDALIB bool addWithCudaContinue(const int* input); // c = c + b
    CUDALIB bool addWithCudaTerminate(void);
}
#endif

// Plan:
// AddVec: add vectors
// MulVec: multiply vectors
// AddMat: add matrix
// MulMat: multiply matrix
// Transpose matrix
