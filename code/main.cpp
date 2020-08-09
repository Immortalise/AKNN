#include <iostream>
#include <fstream>
#include "include/AKNN.h"
#include "include/mem_check.h"
#include "include/AKNN_with_mmap.h"




int main(int argc, char** argv) {
//    std::vector<value> test;
//    for(int i = 0; i < 10; i++){
//        value v;
//        v.s = 100-i;
//        v.u = 100-i;
//        auto it = std::lower_bound(test.begin(), test.end(), v);
//        test.insert(it, v);
//    }
//    for(int i = 0; i < 10; i++){
//        printf("%d\n",test[i].s);
//    }



    Config config;
    AKNN_with_mmap entity(config);

//    AKNN entity(config);

    std::cout<<get_mem_use()<<" MB used\n";
    while(1){
        // K: num of required neibors
        // L: num of candidate pool size
        // E: num of expansions (it is used in select neibor step)
        // T: num of greedy step (iter rounds)
        // R: num of rounds
        scanf("%d %d %d %d %d", &entity.config.K, &entity.config.L, &entity.config.E, &entity.config.T, &entity.config.R);
        if(entity.config.K == 0) break;
//        entity.search();
        entity.search_with_heap();
//        entity.search_with_insert();
    }

    return 0;
}
