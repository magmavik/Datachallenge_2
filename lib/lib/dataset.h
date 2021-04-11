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
    Dataset(int lenght, int cluster_number , float data_probability , float sigma_cluster );
    ~Dataset();

    /**
     * Regenerate the dataset with its parameters.
     */
    void regenerate();
    // void regenerate(int _l);
    static void initialize_seed();


    void print();
    void print_csv(std::string filename);

    // Setter methods

    void set_probability(float _p);
    void set_clusternumber(int _n);
    void set_clustersigma(float _sigma);

    
    // Getter methods

    const int get_length();
    const float get_probability();
    const int get_clusternumber();
    const float get_clustersigma();
    
    const std::vector <bool> get_items();
    

private:

    int l;      // Dataset length.
    int n;      // Cluster number.
    float p;    // Base probability of getting true.
    float cp;   // Cluster gaussian sigma.

    std::vector <bool> data;    // Dataset.
    std::vector <int> cluster;  // Cluster positions.

};








#endif //DATASET