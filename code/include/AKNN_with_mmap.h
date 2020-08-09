//
// Created by Triste on 2020/8/8.
//

#ifndef AKNN_AKNN_WITH_MMAP_H
#define AKNN_AKNN_WITH_MMAP_H

#include "AKNN.h"

class AKNN_with_mmap : public AKNN{
public:
    AKNN_with_mmap(Config config);
    float cal_dist(int idx1, int idx2);
};

#endif //AKNN_AKNN_WITH_MMAP_H
