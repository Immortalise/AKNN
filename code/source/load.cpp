//
// Created by Triste on 2020/8/2.
//
#include "../include/load.h"

void load_data_with_mmap(char* filename, float * & data, int & num, int & ndim) {
    // 先读取向量的数目以及维度
    std::ifstream in(filename, std::ios::binary);

    if (!in.is_open()) {
        std::cout << "open file error" << std::endl;
        exit(-1);
    }
    //读取向量维度
    in.read((char*)&ndim, 4);
    printf("vector dim: %d\n", ndim);

    //光标定位到文件末尾
    in.seekg(0, std::ios::end);
    //获取文件大小（多少字节）
    std::ios::pos_type ss = in.tellg();
    int fsize = (size_t)ss;
    //数据的个数
    num = (unsigned)(fsize / (ndim + 1) / 4);
    printf("vector num: %d\n", num);
    in.close();

    int fd = open(filename, O_RDONLY);
    data = (float *)mmap(nullptr, fsize, PROT_READ, MAP_SHARED, fd, 0);

}

void load_data_with_mmap(char* filename, int * & data, int & num, int & ndim) {
    // 先读取向量的数目以及维度
    std::ifstream in(filename, std::ios::binary);

    if (!in.is_open()) {
        std::cout << "open file error" << std::endl;
        exit(-1);
    }
    //读取向量维度
    in.read((char*)&ndim, 4);
    printf("vector dim: %d\n", ndim);

    //光标定位到文件末尾
    in.seekg(0, std::ios::end);
    //获取文件大小（多少字节）
    std::ios::pos_type ss = in.tellg();
    int fsize = (size_t)ss;
    //数据的个数
    num = (unsigned)(fsize / (ndim + 1) / 4);
    printf("vector num: %d\n", num);
    in.close();

    int fd = open(filename, O_RDONLY);
    data = (int *)mmap(nullptr, fsize, PROT_READ, MAP_SHARED, fd, 0);
}

void load_data(char* filename, float * & data, int & num, int & ndim) {
    //以二进制的方式打开文件
    std::ifstream in(filename, std::ios::binary);

    if (!in.is_open()) {
        std::cout << "open file error" << std::endl;
        exit(-1);
    }
    //读取向量维度
    in.read((char*)&ndim, 4);
    printf("vector dim: %d\n", ndim);

    //光标定位到文件末尾
    in.seekg(0, std::ios::end);
    //获取文件大小（多少字节）
    std::ios::pos_type ss = in.tellg();
    int fsize = (size_t)ss;
    //数据的个数
    num = (unsigned)(fsize / (ndim + 1) / 4);
    printf("vector num: %d\n", num);

    data = new float[(size_t)num * (size_t)ndim];
    printf("%s data addr %x\n",filename, data);

    in.seekg(0, std::ios::beg);	//光标定位到起始处
    for (size_t i = 0; i < num; i++) {
        in.seekg(4, std::ios::cur);	//光标向右移动4个字节
        in.read((char*)(data + i * ndim), ndim * 4);	//读取数据到一维数据data中
    }
    printf("read sucesss!\n\n");
    in.close();
}

void load_data(char* filename, int * & data, int & num, int & ndim) {
    //以二进制的方式打开文件
    std::ifstream in(filename, std::ios::binary);

    if (!in.is_open()) {
        std::cout << "open file error" << std::endl;
        exit(-1);
    }
    //读取向量维度
    in.read((char*)&ndim, 4);
    printf("vector dim: %d\n", ndim);

    //光标定位到文件末尾
    in.seekg(0, std::ios::end);

    //获取文件大小（多少字节）
    std::ios::pos_type ss = in.tellg();
    int fsize = (size_t)ss;

    //数据的个数
    num = (unsigned)(fsize / (ndim + 1) / 4);
    printf("vector num: %d\n", num);

    data = new int[(size_t)num * (size_t)ndim];
    printf("%s data addr %x\n",filename, data);

    in.seekg(0, std::ios::beg);	//光标定位到起始处
    for (size_t i = 0; i < num; i++) {
        in.seekg(4, std::ios::cur);	//光标向右移动4个字节
        in.read((char*)(data + i * ndim), ndim * 4);	//读取数据到一维数据data中
    }
//    for(int i = 0; i < ndim; i++){
//        printf("%d\n",data[i]);
//    }
    printf("read sucesss!\n\n");
    in.close();
}