//
// Created by Triste on 2020/8/9.
//

#include "../include/AKNN.h"
#include "../include/AKNN_with_mmap.h"


AKNN_with_mmap::AKNN_with_mmap(Config config) : AKNN() {
    load_data_with_mmap(config.base_data_path, base_data, config.base_data_num, config.ndim);
    load_data_with_mmap(config.query_data_path, query_data, config.query_data_num, config.ndim);
    load_data_with_mmap(config.graph_path, graph, config.base_data_num, config.graph_k);
    load_data_with_mmap(config.ground_truth_path, ground_truth, config.query_data_num, config.ground_truth_k);
    this->config = config;

//    for(int i = 1; i <= 10; i++){
//        printf("%f ",base_data[i]);
//    }
//    printf("\n");

    printf("Init AKNN sucess\n");
}

/*
 * idx1为需要计算的点在query data中的下标，idx2是base data中的下标，计算他们之间的距离
 * */
float AKNN_with_mmap::cal_dist(int idx1, int idx2) {
    int vec1 = idx1*config.ndim+1, vec2 = idx2*config.ndim+1;
    float dist = 0;
    for(int i = 0; i < config.ndim; i++)
        dist += (query_data[i+vec1]-base_data[i+vec2])*(query_data[i+vec1]-base_data[i+vec2]);
    dist = sqrtf(dist);
    return dist;
}
