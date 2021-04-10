#include "dataset.h"
#include <random>
#include <fstream>

Dataset::Dataset()
{
    srand(time(NULL));

    std::cout << "Insert lenght of generating dataset: ";
    std::cin >> _l;
    while(_l == 0)
    {
        std::cerr << "ERROR: length of dataset cannot be 0. Please insert again: " << std::endl;
        std::cin >> _l;
    }

    std::cout << "Insert wanted probability of getting true: ";
    std::cin >> _p;
    while(_p > 1)
    {
        std::cerr << "ERROR: probability can not be greater than one. Please insert again: " << std::endl;
        std::cin >> _p;
    }
    regenerate();
}

Dataset::Dataset(int lenght, float prob )
    :_l(lenght), _p(prob)
{
    srand(time(NULL));

    std::cout << "Insert lenght of generating dataset: ";
    std::cin >> _l;
    while(_l == 0)
    {
        std::cerr << "ERROR: length of dataset cannot be 0. Please insert again: " << std::endl;
        std::cin >> _l;
    }

    std::cout << "Insert wanted probability of getting true: ";
    std::cin >> _p;
    while(_p > 1)
    {
        std::cerr << "ERROR: probability can not be greater than one. Please insert again: " << std::endl;
        std::cin >> _p;
    }
    regenerate();
}

Dataset::~Dataset()
{

}


void Dataset::regenerate()
{
    _data.clear();

    for(int i=0; i< _l; i++)
    {
        bool appo = rand()/(RAND_MAX+1.0) < _p;
        _data.push_back(appo);
    }
}

void Dataset::regenerate(int l)
{
    _data.clear();

    _l = l;
    
    regenerate();
}

void Dataset::change_probability(float p)
{
    _p = p;
}

int Dataset::length()
{
    return _l;
}

float Dataset::t_probability()
{
    return _p;
}

float Dataset::f_probability()
{
    return 1 - _p;
}

void Dataset::print()
{
    std::cout << std::endl << "Dataset: " << std::endl; 
    for(int i=0; i< _l-1; i++)
    {
        std::cout << _data[i] << ", ";
    }
    std::cout << _data[_l-1] << std::endl << std::endl;
}

void Dataset::print_csv(std::string filename)
{
    std::ofstream file_out;
    file_out.open(filename);
    if(!file_out.good())
    {
        std::cerr << "ERROR: something went wrong with file" << filename << std::endl;
    }

    for(int i=0; i< _l-1; i++)
    {
        file_out << _data[i] << ",";
    }
    file_out << _data[_l-1];
}

std::vector <bool> Dataset::items()
{
    return _data;
}