#ifndef __VECTOR_H__
#define __VECTOR_H__

#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <fstream>

#define LOG(msg) std::cout << msg << std::endl;

struct vector
{
    float *data;
    int size;
    
    float& operator[](int index)
    {
        return data[index];
    }

};

void init(struct vector& var,float data[],int size);
void printv(struct vector& var);
void __delete__(struct vector& var);

float vector_sum(struct vector& var);
struct vector sub(struct vector& a,struct vector& b);
struct vector dot1d(struct vector& a,struct vector& b);
struct vector scalar_dot(struct vector& a,float b);
struct vector scalar_add(struct vector& a,float b);
float predict(float* coefficients,int x); 

#endif // __VECTOR_H__
