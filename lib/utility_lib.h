#ifndef __utility_lib_h__
#define __utility_lib_h__

#include <iostream>
#include <vector>
#include <math.h> //log
#include <algorithm>
#include <random>
#include <fstream>



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
template <typename T> int sgn(T val) {
    return (T(0) < val) - (val < T(0));
}

template< typename T> 
double add_gaussian_noise( T sigma)
{
    std::random_device rd{};
    std::mt19937 gen{rd()};


    std::normal_distribution<T> dist(0.0, sigma);

    return dist(gen);

}

/**
 * This function add a column to a csv file
 * input:
 *       * filename (str)
 *       * column   (std::vector)
 *       * comn name ( std::string)
 * 
 */
template<typename T> 
void add_column_to_file(std::string nameFile , std::vector<T> column, std::string nameColumn)
{
    std::ifstream fin(nameFile);
    std::ofstream fout(nameFile);

    std::string line;

    if(! (fin.good() and fout.good()) )
    {
        std::cerr << "ERROR: unable to read or wright on file.\n"
                  << "       Some problem may have occurred\n";
    }

    std::getline(fin, line);
    fout << line + nameColumn;
    typename std::vector<T>::iterator it;
    for( it = column.begin(); it != column.end(); ++ it)
    {
        getline(fin,line);
        fout << line << "," << *it << "\n";
    }

    


}


#endif