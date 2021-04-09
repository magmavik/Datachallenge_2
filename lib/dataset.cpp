#include "dataset.h"
#include <random>
#include <fstream>

Dataset::Dataset()
{
    srand(time(NULL));

    std::cout << "Insert lenght of generating dataset: ";
    std::cin >> l;
    while(l == 0)
    {
        std::cerr << "ERROR: length of dataset cannot be 0. Please insert again: " << std::endl;
        std::cin >> l;
    }

    std::cout << "Insert wanted probability of getting true: ";
    std::cin >> p;
    while(p > 1)
    {
        std::cerr << "ERROR: probability can not be greater than one. Please insert again: " << std::endl;
        std::cin >> p;
    }



    regenerate();

}

Dataset::~Dataset()
{

}


void Dataset::regenerate()
{
    data.clear();

    for(long int i=0; i<l; i++)
    {
        bool appo = rand()/(RAND_MAX+1.0) < p;
        data.push_back(appo);
    }
}

void Dataset::regenerate(long int _l)
{
    data.clear();

    l = _l;
    
    regenerate();
}

void Dataset::change_probability(float _p)
{
    p = _p;
}

long int Dataset::length()
{
    return l;
}

float Dataset::t_probability()
{
    return p;
}

float Dataset::f_probability()
{
    return 1-p;
}

void Dataset::print()
{
    std::cout << std::endl << "Dataset: " << std::endl; 
    for(long int i=0; i<l-1; i++)
    {
        std::cout << data[i] << ", ";
    }
    std::cout << data[l-1] << std::endl << std::endl;
}

void Dataset::print_csv(std::string filename)
{
    std::ofstream file_out;
    file_out.open(filename);
    if(!file_out.good())
    {
        std::cerr << "ERROR: something went wrong with file " << filename << std::endl;
    }

    for(long int i=0; i<l-1; i++)
    {
        file_out << data[i] << ",";
    }
    file_out << data[l-1];
}

std::vector <bool> Dataset::items()
{
    return data;
}
