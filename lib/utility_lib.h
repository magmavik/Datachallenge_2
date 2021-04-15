#ifndef __utility_lib_h__
#define __utility_lib_h__

#include <iostream>
#include <vector>
#include <math.h> //log

template<typename T, typename A>
void print_vector(std::vector<T,A> const &inv)
{
    if(inv.size() == 0)
    {
        std::cout << "ERROR: vector is empty \n";
        return;
    }
    for (auto it = inv.begin(); it != inv.end(); ++it)
    {
        std::cout << *it<< ",";
    }
};

float my_round(const float);
// {
//     return static_cast<int>(i * 10 + 0.5) / 10.0;
// }


/**
 * generate number in esponential distribution with parameter lamda 
 */
double gen_expo(double lambda);

/**
 * sign function
 */
int sgn(double x);


#endif