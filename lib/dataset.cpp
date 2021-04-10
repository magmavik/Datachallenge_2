#include "dataset.h"
#include <random>
#include <fstream>
#include <cstdlib>
#include <random>
#include <cmath>

#ifndef PI_BOX_MULLER
#define PI_BOX_MULLER 3.1415
#endif
double oneGauss(float x, float mu, float sigma)
{
    return (double)(exp(-(pow((x-mu), 2)/(2*pow(sigma, 2)))));
}

float randomGauss(float mu, float sigma)
{
    double u1,u2;
    int appo;
    do{
        appo=rand();
    }while(appo==0);

    u1 = (double) appo/RAND_MAX;
    u2 = (double) rand()/RAND_MAX;

    return  mu+ sigma *((float) (sqrt(-2.* log(u1)) * cos(2 * PI_BOX_MULLER * u2)));

}



Dataset::Dataset()
{
    srand(time(NULL));

    std::cout << "Insert lenght of generating dataset: ";
    std::cin >> l;
    while(l <= 0)
    {
        std::cerr << "ERROR: length of dataset cannot be less than 0. Please insert again: " << std::endl;
        std::cin >> l;
    }

    std::cout << "Insert wanted probability of getting true: ";
    std::cin >> p;
    while(p > 1 | p < 0)
    {
        std::cerr << "ERROR: probability can not be greater than one or less than zero. Please insert again: " << std::endl;
        std::cin >> p;
    }

    std::cout << "Insert number of wanted clusters: ";
    std::cin >> n;
    while(n > l | n < 0)
    {
        std::cerr << "ERROR: number of cluster can not exceed dataset length or be less than zero. Please insert again: " << std::endl;
        std::cin >> n;
    }
    
    std::cout << "Insert wanted cluster's gaussian sigma: ";
    std::cin >> cp;
    while(cp > l | cp < 0)
    {
        std::cerr << "ERROR: probability can not be greater than dataset length or less than zero. Please insert again: " << std::endl;
        std::cin >> cp;
    }



    regenerate();

}

Dataset::Dataset(int _l, int _n, float _p, float _cp)
{
    l = _l;
    n = _n;
    p = _p;
    cp = _cp;

    regenerate();
}

Dataset::~Dataset()
{  

}


void Dataset::regenerate()
{
    data.clear();

    for(int i=0; i<n; i++)
    {
        int appo = rand()%(l-1);
        std::cout << "Cluster position:" << appo << std::endl;
        cluster.push_back(appo);
    }

    for(int i=0; i<l; i++)
    {
        double p_added = 0;
        double p_i = 0;
        for(int j=0; j<n; j++)
        {
            p_added += oneGauss(i, cluster[j], cp)/n; 
        }
        
        
        p_i = (double)p + p_added*(1-p);

        bool appo = rand()/(RAND_MAX+1.0) < p_i;
        data.push_back(appo);
    }

}

// void Dataset::regenerate(int _l)
// {
//     data.clear();
//     l = _l;
    
//     regenerate();
// }



void Dataset::print()
{
    std::cout << std::endl << "Dataset: " << std::endl; 
    for(int i=0; i<l-1; i++)
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
        std::cerr << "ERROR: something went wrong with file" << filename << std::endl;
    }

    for(int i=0; i<l-1; i++)
    {
        file_out << data[i] << ",";
    }
    file_out << data[l-1];
}

// Setter methods

void Dataset::set_probability(float _p)
{
    p = _p;
}

void Dataset::set_clusternumber(int _n)
{
    n = _n;
}

void Dataset::set_clustersigma(float _sigma)
{
    cp = _sigma;
}


// Getter methods

const int Dataset::length()
{
    return l;
}

const std::vector <bool> Dataset::items()
{
    return data;
}

float Dataset::probability()
{
    return p;
}