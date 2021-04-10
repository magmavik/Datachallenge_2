#ifndef DATASET
#define DATASET

#include <iostream>
#include <vector>
#include "time.h"
#include <string>

/**
 * Boolean dataset with possibility
 * of creating clusters. 
 */
class Dataset
{
public:

    Dataset();
    Dataset(int _l, int _n, float _p, float _cp);
    ~Dataset();

    /**
     * Regenerate the dataset with its parameters.
     */
    void regenerate();
    // void regenerate(int _l);


    void print();
    void print_csv(std::string filename);

    // Setter methods

    void set_probability(float _p);
    void set_clusternumber(int _n);
    void set_clustersigma(float _sigma);

    
    // Getter methods

    /**
     * Gets dataset lenght.
     */
    const int length();

    /**
     * Gets dataset items.
     */
    const std::vector <bool> items();
    
    /**
     * Gets base probability of getting true.
     */
    float probability();

private:

    int l;      // Dataset length.
    int n;      // Cluster number.
    float p;    // Base probability of getting true.
    float cp;   // Cluster gaussian sigma.

    std::vector <bool> data;    // Dataset.
    std::vector <int> cluster;  // Cluster positions.

};








#endif //DATASET