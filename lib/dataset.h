#ifndef DATASET
#define DATASET

#include <iostream>
#include <vector>
#include "time.h"

class Dataset
{
public:
    Dataset();
    ~Dataset();

    void regenerate();
    void regenerate(long int _l); //For changing dataset lenght, not yet developed

    long int length();
    float t_probability();
    float f_probability();

    void print();
    std::vector <bool> items();

private:

    long int l;
    float p;
    std::vector <bool> data;

};








#endif //DATASET