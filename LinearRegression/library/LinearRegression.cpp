#include "../includes/vectors.h"
#include "../includes/LinearRegression.h"

float* train_model(float lr,int epochs)
{
    float X[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    int X_size = sizeof(X) / sizeof(X[0]);

    float Y[] = {2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,40};
    int Y_size = sizeof(Y) / sizeof(Y[0]);

    struct vector x;
    init(x,X,X_size);

    struct vector y;
    init(y,Y,Y_size);
    
    float* coefficients = (float *)malloc(sizeof(float) * 2);

    struct vector y_hat;
    init(y_hat,X,X_size);

    struct vector y_hat1;
    init(y_hat1,X,X_size);

    int n = x.size;

    float c = 0, m = 0,D_m = 0,D_c = 0;

    if(x.size != y.size)
    {
        LOG("invalid vector");
    } 

    else
    {
        float k = -(float)2/n;

        for(int i=0;i<epochs;i++)
        {    
            y_hat = scalar_dot(x,m);
            y_hat = scalar_add(y_hat,c);

            y_hat1 = sub(y,y_hat);
            y_hat1 = dot1d(x,y_hat1);

            D_m = k * vector_sum(y_hat1);

            y_hat1 = sub(y,y_hat); 
            D_c = k * vector_sum(y_hat1);
            
            m = m - lr * D_m;
            c = c - lr * D_c;
        }

        coefficients[0] = m; 
        coefficients[1] = c;
    }

    __delete__(x);
    __delete__(y);
    __delete__(y_hat);
    __delete__(y_hat1);

    writeParameters(coefficients);

    return coefficients;
}


void writeParameters(float* coeff)
{
    std::ofstream weights_file("weights.txt");
    weights_file << coeff[0];
    weights_file << "\n";
    weights_file << coeff[1];

}

float* readParameters()
{
    float* coeff = (float *)malloc(sizeof(float) * 2);
    std::ifstream weights_file("weights.txt");    
    std::string text;
    int index = 0;

    while (getline (weights_file, text)) 
    {
        coeff[index++] = atof(text.c_str());
    }

    return coeff;
}   