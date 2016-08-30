#ifndef __ALGORITHM_COMMON__
#define __ALGORITHM_COMMON__

// basical types

typedef unsigned char       UINT8;
typedef unsigned short      UINT16;
typedef unsigned int        UINT32;
typedef unsigned long long  UINT64;

template <T>
void swap(T &a, T &b){
    T tmp = a;
    a = b;
    b = a;
}


#endif
