#ifndef __LINEARREGRESSION_H__
#define __LINEARREGRESSION_H__

float* train_model(float lr,int epochs);
void writeParameters(float* coeff);
float* readParameters();

#endif // __LINEARREGRESSION_H__