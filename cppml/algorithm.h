#include <vector>
using namespace std;

template <typename T>
class Algorithm {
    public:
        virtual void fit(vector<T> x, vector<T> y)  = 0;
        virtual T predict(T x)  = 0;
};