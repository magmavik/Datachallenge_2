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
    void regenerate(double _l); //For changing dataset lenght, not yet developed

    double length();

    void print();

private:

    double l;
    std::vector <bool> data;

};








#endif //DATASET