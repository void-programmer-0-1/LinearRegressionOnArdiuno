#include "vectors.h"

void init(struct vector& var,float data[],int size) 
{
    var.size = size;
    var.data = (float *)malloc(sizeof(float) * size);
    for(int i=0;i<var.size;i++)
    {
      var.data[i] = data[i];
    }
}




void __delete__(struct vector& var)
{
    free(var.data);
}


float vector_sum(struct vector& var)
{
    float sum = 0;
    for(int i=0;i<var.size;i++)
        sum += var.data[i];

    return sum;
}


struct vector sub(struct vector& a,struct vector& b)
{   
    struct vector subracted;
    subracted.data = (float *)malloc(sizeof(float) * (a.size));
    subracted.size = a.size;

    for(int i=0;i<a.size;i++)
    {
        subracted[i] = a[i] - b[i];
    }
    return subracted;
}


struct vector dot1d(struct vector& a,struct vector& b)
{   
    struct vector dot;
    dot.data = (float *)malloc(sizeof(float) * (a.size));
    dot.size = a.size;

    for(int i=0;i<a.size;i++)
    {
        dot[i] = a[i] * b[i];
    }
    return dot;
}


struct vector scalar_dot(struct vector& a,float b)
{
    struct vector var;
    var.size = a.size;
    var.data = (float *)malloc(sizeof(float) * var.size);
    
    for(int i=0;i<a.size;i++)
    {
        var.data[i] = a[i] * b;
    }

    return var;
}


struct vector scalar_add(struct vector& a,float b)
{
    struct vector var;
    var.size = a.size;
    var.data = (float *)malloc(sizeof(float) * var.size);
    
    for(int i=0;i<a.size;i++)
    {
        var.data[i] = a[i] - b;
    }

    return var;
}


float predict(float* coefficients,int x)
{
    float m = coefficients[0] , c = coefficients[1];
    float y_hat = m * x + c;
    return y_hat;
}
