#include <iostream>
#include <stdexcept>

#include "../algorithm.h"
using namespace std;

class LR: public Algorithm<float>{
    private:
        float m, b;
    public:
        void fit(vector<float> x, vector<float> y) override{
            float x_mean = 0;
            float y_mean = 0;
            float numerator = 0;
            float denominator = 0;
            int x_len = x.size();
            int y_len = y.size();

            if(x_len != y_len) throw new invalid_argument("x and y should be of the same shape");
            
            for(int itr=0; itr<x_len; itr++){
                x_mean += x[itr];
                y_mean += y[itr];
            }
            
            x_mean = x_mean / x_len;
            y_mean = y_mean / y_len;

            for(int itr=0; itr<x_len; itr++){
                numerator += (y[itr] - y_mean) * (x[itr] - x_mean);
                denominator += (x[itr] - x_mean) * (x[itr] - x_mean);
            }

            this->m = numerator / denominator;
            this->b = y_mean - (m * x_mean);
        }

        float predict(float x) override{
            return ((this->m * x) + b);
        }
};