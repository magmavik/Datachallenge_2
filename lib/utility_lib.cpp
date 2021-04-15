#include "utility_lib.h"

// template<typename T, typename A>
// void print_vector(std::vector<T,A> const &inv)
// {
//     if(inv.size() == 0)
//     {
//         std::cout << "ERROR: vector is empty \n";
//         return;
//     }
//     for (auto it = inv.begin(); it != inv.end(); ++it)
//     {
//         std::cout << *it<< ",";
//     }
// }


float my_round(const float i)
{
    return static_cast<int>(i * 10 + 0.5) / 10.0;
}

double gen_expo(double lambda){
    double u;
    u = rand() / (RAND_MAX + 1.0);
    return -log(1- u) / lambda;
}

int sgn(double x)
{
    if(x > 0)
    {
        return 1;
    }
    else
    {
        return -1;
    }
}


