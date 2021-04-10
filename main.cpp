#include <iostream>
#include "./lib/dataset.h"
#include "./lib/data_cluster.h"

int main()
{
    Dataset data(10000,0.001);

    data_cluster clust(data.get_data_vector(),  data.get_data_length());

    clust.print_distance_histogram();


    return 0;
}