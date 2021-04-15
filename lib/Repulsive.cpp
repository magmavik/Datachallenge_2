#include "Repulsive.h"
#include <random>
#include <fstream>
#include <cstdlib>
#include <random>
#include <cmath>

#include <bits/stdc++.h>

#ifndef PI_BOX_MULLER
#define PI_BOX_MULLER 3.1415
#endif


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

void Repulsive::initialize()
{
    srand(time(NULL));
}

// Repulsive::Repulsive()
// {
//     std::cout << "Insert lenght of generating Repulsive: ";
//     std::cin >> l;
//     while(l <= 0)
//     {
//         std::cerr << "ERROR: length of Repulsive cannot be less than 0. Please insert again: " << std::endl;
//         std::cin >> l;
//     }

//     std::cout << "Insert wanted probability of getting true: ";
//     std::cin >> p;
//     while(p > 1 | p < 0)
//     {
//         std::cerr << "ERROR: probability can not be greater than one or less than zero. Please insert again: " << std::endl;
//         std::cin >> p;
//     }

//     std::cout << "Insert number of wanted clusters: ";
//     std::cin >> n;
//     while(n > l | n < 0)
//     {
//         std::cerr << "ERROR: number of cluster can not exceed Repulsive length or be less than zero. Please insert again: " << std::endl;
//         std::cin >> n;
//     }
    
//     std::cout << "Insert wanted cluster's gaussian sigma: ";
//     std::cin >> cp;
//     while(cp > l | cp < 0)
//     {
//         std::cerr << "ERROR: sigma can not be greater than Repulsive length or less than zero. Please insert again: " << std::endl;
//         std::cin >> cp;
//     }



//     regenerate();

// }

/**
 * cluster are generated gaussian like 
*/
Repulsive::Repulsive(int length, float base_probability, float force)
{
    if(length>=0)
    {
        l = length;
    }
    else
    {
        std::cerr << "ERROR: length of Repulsive cannot be less than 0." << std::endl;
    }

    if(base_probability>=0 && base_probability<=1)
    {
        p = base_probability;
    }
    else
    {
        std::cerr << "ERROR: probability can not be greater than one or less than zero." << std::endl;
    }

    f = force;

    regenerate();
}

Repulsive::~Repulsive()
{  

}


// void Repulsive::regenerate()
// {
//     data.clear();
    
//     for(int i=0; i<l; i++)
//     {
//         bool appo = false;
//         data.push_back(appo);
//     }


//     int n = int(p*l);
//     float pos[n+2];
//     int F[n];

//     for(int i=0; i<n; i++)
//     {
//         for(int j=0; j<n; j++)
//         {
//             if(i==j)
//             {
//                 break;
//             }

//             do
//             {
//                 pos[i] = rand()/(RAND_MAX+1.0)*l;
//             } while(int(pos[i]) == int(pos[j]));
//         }
//     }

//     pos[n] = -1.0;
//     pos[n+1] = 1.0;

//     int t_max = 10000;
//     for(int t=0; t<t_max; t++)
//     {
//         for(int i=0; i<n; i++)
//         {
//             F[i] = 0;
//             for(int j=0; j<n+2; j++)
//             {
//                 if(j==i)
//                 {
//                     break;
//                 }
//                 else
//                 {
//                     F[i] += f/(pow((pos[i]-pos[j]), 2))*sgn(pos[i]-pos[j]);
//                 }
//             }
//         }

//         for(int i=0; i<n; i++)
//         {
//             if(pos[i]>=0 && pos[i]<l)
//             {
//                 pos[i] += 0.5*F[i]*pow(t, 2);
//             }
//         }

//     }

//     for(int i=0; i<n; i++)
//     {
//         if(pos[i] >= 0 && pos[i] <= l)
//         {
//             if(data[int(pos[i])] == true){std::cout << "Merdadio" << std::endl;}
//             data[int(pos[i])] = true;
//         }
//     }

// }

void Repulsive::regenerate()
{
    data.clear();
    
    for(int i=0; i<l; i++)
    {
        bool appo = false;
        data.push_back(appo);
    }

    int n = int(p*l);
    int pos[n];
    int space[n+1];
    pos[0] = round(rand()/(RAND_MAX+1.0)*l);
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(i==j)
            {
                break;
            }

            do
            {
                pos[i] = round(rand()/(RAND_MAX+1.0)*l);
            } while(pos[i] == pos[j]);
        }
    }

    std::sort(pos, pos+n);
    for(int i=0; i<n; i++)
    {
        std::cout << pos[i] << std::endl;
    }
    std::cout << std::endl;

    space[0] = pos[0];
    for(int i=1; i<n; i++)
    {
        space[i] = pos[i] - pos[i-1];
    }
    space[n] = l - pos[n-1];

    for(int i=0; i<n+1; i++)
    {
        std::cout << space[i] << std::endl;
    }

    int t_max = 1;
    int m_space = round(l/n+1);
    for(int t=0; t<=t_max; t++)
    {
        for(int i=0; i<n+1; i++)
        {
            if(space[i] != m_space)
            {
                space[i] += sgn(m_space - space[i])*1;
            }
        }
    }

    std::cout << std::endl;
    int semidist=0;
    for(int j=0; j<n; j++)
    {
        semidist += space[j];
        std::cout << space[j] << std::endl;
        pos[j] = semidist;
        data[pos[j]] = true;
    }


}


// void Repulsive::regenerate(int _l)
// {
//     data.clear();
//     l = _l;
    
//     regenerate();
// }



void Repulsive::print()
{
    std::cout << std::endl << "Repulsive: " << std::endl; 
    for(int i=0; i<l-1; i++)
    {
        std::cout << data[i] << ", ";
    }
    std::cout << data[l-1] << std::endl << std::endl;
}

void Repulsive::print_csv(std::string filename)
{
    std::ofstream file_out;
    file_out.open(filename);
    if(!file_out.good())
    {
        std::cerr << "ERROR: something went wrong with file" << filename << std::endl;
    }

    file_out << "data" << std::endl;
    for(int i=0; i<l-1; i++)
    {
        file_out << data[i] << std::endl;
    }
    file_out << data[l-1];
}

// Setter methods

void Repulsive::set_length(int _l)
{
    if(_l>=0)
    {
        l = _l;
    }
    else
    {
        std::cerr << "ERROR: length of Repulsive cannot be less than 0." << std::endl;
    }
}

void Repulsive::set_probability(float _p)
{
    if(_p>=0 & _p<=1)
    {
        p = _p;
    }
    else
    {
        std::cerr << "ERROR: probability can not be greater than one or less than zero." << std::endl;
    }
}


// Getter methods

const int Repulsive::get_length()
{
    return l;
}

const float Repulsive::get_probability()
{
    return p;
}

const float Repulsive::get_force()
{
    return f;
}

const std::vector <bool> Repulsive::get_items()
{
    return data;
}