#ifndef REPULSIVE
#define REPULSIVE

#include <iostream>
#include <vector>
#include "time.h"
#include <string>

/**
 * Boolean dataset with possibility
 * of creating repulsive clusters. 
 */
class Repulsive
{
public:

    static void initialize();

    Repulsive();
    Repulsive(int length, float base_probability, float force);
    ~Repulsive();

    /**
     * Regenerate the Repulsive with its parameters.
     */
    void regenerate();
    // void regenerate(int _l);


    void print();
    void print_csv(std::string filename);

    // Setter methods

    void set_length(int _l);
    void set_probability(float _p);
    void set_clusternumber(int _n);
    void set_clustersigma(float _sigma);

    
    // Getter methods

    const int get_length();
    const float get_probability();
    const float get_force();
    
    const std::vector <bool> get_items();
    

private:

    int l;  // Dataset lengt
    float p;
    float f;    // Repulsive force

    std::vector <bool> data;    // Dataset.

};








#endif //Repulsive