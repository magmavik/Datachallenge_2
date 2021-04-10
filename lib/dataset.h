#ifndef DATASET
#define DATASET

#include <iostream>
#include <vector>
#include "time.h"
#include <string>

class Dataset
{
public:
    Dataset();
    ~Dataset();

    void regenerate();
    void regenerate(int _l);

    void change_probability(float _p);

    int length();
    float t_probability();
    float f_probability();

    void print();
    void print_csv(std::string filename);
    std::vector <bool> items();

private:

    int l;
    int n;
    float p;
    float cp;
    std::vector <bool> data;
    std::vector <int> cluster;

};








#endif //DATASET