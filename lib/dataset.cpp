#include "dataset.h"

Dataset::Dataset()
{
    srand(time(NULL));

    std::cout << "Insert lenght of generating dataset: ";
    std::cin >> l;
    while(l == 0)
    {
        std::cerr << "ERROR: lenght of dsataset cannot be 0. Please insert again: " << std::endl;
        std::cin >> l;
    }

    regenerate();

}

Dataset::~Dataset()
{

}


void Dataset::regenerate()
{
    data.clear();

    for(double i=0; i<l; i++)
    {
        bool appo = rand()%2 == 0;
        data.push_back(appo);
    }
}

void Dataset::regenerate(double _l)
{
    data.clear();

    l = _l;
    
    regenerate();
}

void Dataset::print()
{
    std::cout << std::endl << "Dataset: " << std::endl; 
    for(double i=0; i<l-1; i++)
    {
        std::cout << data[i] << ", ";
    }
    std::cout << data[l-1] << std::endl << std::endl;
}

double Dataset::length()
{
    return l;
}