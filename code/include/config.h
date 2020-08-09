//
// Created by Triste on 2020/8/4.
//

#ifndef AKNN_CONFIG_H
#define AKNN_CONFIG_H

class Config{
public:
    char base_data_path[256] = "/Users/triste/MarchingOn/project/sift/sift_base.fvecs";
    char query_data_path[256] = "/Users/triste/MarchingOn/project/sift/sift_query.fvecs";
    char ground_truth_path[256] = "/Users/triste/MarchingOn/project/sift/sift_groundtruth.ivecs";
    char graph_path[256] = "/Users/triste/MarchingOn/project/sift_100NN_100.graph";
    char save_path[256] = "";

    // The following is the hyper parameters of AKNN
    int base_data_num, query_data_num;
    int ndim, graph_k, ground_truth_k;

    // K: num of required neibors
    // L: num of candidate pool size
    // E: num of expansions (it is used in select neibor step)
    // T: num of greedy step (iter rounds)
    // R: num of rounds
    int K = 100;
    int L = 1000;
    int E = 100;
    int T = 60;
    int R = 3;
};

#endif //AKNN_CONFIG_H
