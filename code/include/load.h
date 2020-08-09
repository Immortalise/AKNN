//
// Created by Triste on 2020/8/2.
//

#ifndef AKNN_LOAD_H
#define AKNN_LOAD_H

#endif //AKNN_LOAD_H

#include <iostream>
#include <fstream>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>
#include <cstdlib>



//void load_float_data(char* filename, float *& data, unsigned& num, unsigned& dim);
//void load_int_data(char* filename, int *& data, unsigned& num, unsigned& dim);
void load_data_with_mmap(char* filename, float * & data, int & num, int & ndim);
void load_data_with_mmap(char* filename, int * & data, int & num, int & ndim);

void load_data(char* filename, float * & data, int & num, int & ndim);
void load_data(char* filename, int * & data, int & num, int & ndim);