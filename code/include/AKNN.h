//
// Created by Triste on 2020/8/4.
//

#ifndef AKNN_AKNN_H
#define AKNN_AKNN_H

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <stdint.h>
#include <immintrin.h>
#include <ctime>

#include "load.h"
#include "config.h"

// this struct is used for sort S and U conveniently
struct value{
    int s;
    float u;

    bool operator<(const value & v) const {
        return this->u < v.u;
    }
};

class AKNN {
protected:
    float * base_data = nullptr, * query_data = nullptr;
    int * graph = nullptr, * ground_truth = nullptr;

public:
    Config config;
    AKNN();
    AKNN(Config config);

    void search();
    void search_with_heap();
    void search_with_insert();

    ~AKNN();

private:
    virtual float cal_dist(int idx1, int idx2);
    float cal_dist_with_AVX(int idx1, int idx2);

};



#endif //AKNN_AKNN_H



