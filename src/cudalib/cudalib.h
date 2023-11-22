#ifndef CUDALIB_H_
#define CUDALIB_H_

#ifdef CUDALIB_EXPORT
#define CUDALIB __declspec(dllexport)
#else
#define CUDALIB __declspec(dllimport)
#endif

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
