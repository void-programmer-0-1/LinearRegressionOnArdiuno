#include "../includes/vectors.h"
#include "../includes/LinearRegression.h"
#include <experimental/filesystem>

namespace fs = std::experimental::filesystem;

int main()
{
    struct vector var;
    struct vector var1;

    float array[] = {1,2,3,4,5,10,120};
    int array_size = sizeof(array) / sizeof(array[0]);
    init(var,array,array_size);
    
    float arr[] = {1,2,3,4,5,10,120};
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    init(var1,array,array_size);
    

    struct vector var2 = sub(var,var1);

    struct vector var3 = dot1d(var,var1);

    __delete__(var);
    __delete__(var1);
    __delete__(var2);
    __delete__(var3);


    if(fs::exists("weights.txt"))
    {
        LOG("Reading from file.......")
        float* coeff = readParameters();
        LOG(coeff[0]);
        LOG(coeff[1]);

        int prediction = (int)predict(coeff,6);
        LOG(prediction);

        free(coeff);
    }
    else
    {
        LOG("Training");
        float* coeff = train_model(0.00001,1850);
        LOG(coeff[0]);
        LOG(coeff[1]);

        int prediction = (int)predict(coeff,6);
        LOG(prediction);

        free(coeff);
    }


    return 0;
}