#include "ex2.h"

void v_add_naive(double* x, double* y, double* z) {
    #pragma omp parallel
    {
        for(int i=0; i<ARRAY_SIZE; i++)
            z[i] = x[i] + y[i];
    }
}

// Adjacent Method
void v_add_optimized_adjacent(double* x, double* y, double* z) {
    // TODO: Implement this function
    // Do NOT use the `for` directive here!
    #pragma omp parallel
    {
        int N=omp_get_num_threads();
        for(int i=omp_get_thread_num();i<ARRAY_SIZE;i++)
            z[i]=x[i]+y[i];
    }
}

// Chunks Method
void v_add_optimized_chunks(double* x, double* y, double* z) {
    // TODO: Implement this function
    // Do NOT use the `for` directive here!
    #pragma omp parallel
    {
        int N=omp_get_num_threads();
        int ind=omp_get_thread_num();
        int size=ARRAY_SIZE/N;
        for(int i=ind*size;i<ind*size+size;i++)
            z[i]=x[i]+y[i];
        if(ind==0)
            for(int i=size*N;i<ARRAY_SIZE;i++)
                z[i]=x[i]+y[i];
    }
}
