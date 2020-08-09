//
// Created by Triste on 2020/8/4.
//

#include "../include/AKNN.h"

void AKNN::search_with_insert(){
    srand((unsigned)time(NULL));
    int total_match = 0;
    clock_t start_time, end_time;
    start_time = clock();
    for(int query_idx = 0; query_idx < config.query_data_num; query_idx++){
        // 此处实现的是最大堆（在value结构定义处实现了 < 的重载）

        std::vector<value> insert_array;

        int is_in[config.base_data_num];
        std::memset(is_in, 0, sizeof(is_in));
        int cur = 0;
        for(int round = 0; round < config.R; round++){
            int Yt = rand()%config.base_data_num;
//            printf("round %d, Yt %d\n",round, Yt);
            for(int t = 0; t < config.T; t++){
                float min_dist = 100000000;
                int nearest = -1;
                for(int i = 0; i < std::min(config.E, config.graph_k); i++){
                    int neibor = graph[Yt*config.graph_k+i];
                    if(!is_in[neibor]){
                        is_in[neibor] = 1;
                        value v;
                        v.s = neibor;
                        v.u = cal_dist(query_idx, neibor);

                        auto it = std::lower_bound(insert_array.begin(), insert_array.end(), v);
                        insert_array.insert(it, v);

                        if(v.u < min_dist){
                            min_dist = v.u;
                            nearest = v.s;
                        }
                        cur ++;
                    }
                }
                if(nearest == -1) break;
                else Yt = nearest;
            }
        }
        // 选出候选集中前K个元素
        int candidate[config.K];
        for(int i = 0; i < config.K; i++) candidate[config.K - i - 1] = insert_array[i].s;
        std::sort(candidate, candidate + config.K);

        // 选出ground truth中前K个元素
        int truth[config.K];
        std::memcpy(truth,ground_truth+query_idx*config.ground_truth_k, config.K*sizeof(int));
        std::sort(truth, truth+config.K);

        // 对候选集和ground truth进行比较
        int match = 0, c_idx = 0, t_idx = 0;
        while (c_idx < config.K && t_idx < config.K){
            if(candidate[c_idx] < truth[t_idx]){
                while(c_idx < config.K && candidate[c_idx] < truth[t_idx]) c_idx++;
            }
            else if(candidate[c_idx] > truth[t_idx]){
                while(t_idx < config.K && candidate[c_idx] > truth[t_idx]) t_idx++;
            }
            if(c_idx < config.K && t_idx < config.K){
                if(candidate[c_idx] == truth[t_idx]) {
                    match++;
                    c_idx++;
                    t_idx++;
                }

            }
        }
        total_match += match;
//        if(query_idx % 100 == 0) printf("Query point %d acc is %f\n",query_idx, 1.0*match/config.K);
    }
    end_time = clock();
    std::cout << "Total Time : " << (double)(end_time - start_time) / CLOCKS_PER_SEC << "s" << std::endl;
    printf("Total acc is %f\n\n", 1.0*total_match/config.query_data_num);
}

void AKNN::search_with_heap() {
    srand((unsigned)time(NULL));
    int total_match = 0;
    clock_t start_time, end_time;
    start_time = clock();
    for(int query_idx = 0; query_idx < config.query_data_num; query_idx++){
        // 此处实现的是最大堆（在value结构定义处实现了 < 的重载）
        std::priority_queue<value> fixed_size_heap;

        int is_in[config.base_data_num];
        std::memset(is_in, 0, sizeof(is_in));
        int cur = 0;
        for(int round = 0; round < config.R; round++){
            int Yt = rand()%config.base_data_num;
//            printf("round %d, Yt %d\n",round, Yt);
            for(int t = 0; t < config.T; t++){
                float min_dist = 100000000;
                int nearest = -1;
                for(int i = 0; i < std::min(config.E, config.graph_k); i++){
                    int neibor = graph[Yt*config.graph_k+i];
                    if(!is_in[neibor]){
                        is_in[neibor] = 1;
                        value v;
                        v.s = neibor;
                        v.u = cal_dist(query_idx, neibor);

                        // 在这里实现 fixed size
                        if(fixed_size_heap.size() == config.L){
                            if(v.u < fixed_size_heap.top().u) {
                                fixed_size_heap.pop();
                                fixed_size_heap.push(v);
                            }
                        }
                        else fixed_size_heap.push(v);

                        if(v.u < min_dist){
                            min_dist = v.u;
                            nearest = v.s;
                        }
                        cur ++;
                    }
                }
//                if(!query_idx && !round && !t) get_mem_use();
                if(nearest == -1) break;
                else Yt = nearest;
            }
        }
        // 选出候选集中前K个元素

        int candidate[config.K];

        for(int i = 0; i < fixed_size_heap.size()-config.K; i++) {
            if(i < 10){
                value v = fixed_size_heap.top();
                printf("check is max heap %f\n",v.u);
            }
            fixed_size_heap.pop();
        }
        for(int i = 0; i < config.K; i++) {
            candidate[config.K - i - 1] = fixed_size_heap.top().s;
            fixed_size_heap.pop();
        }
        std::sort(candidate, candidate + config.K);

        // 选出ground truth中前K个元素
        int truth[config.K];
        std::memcpy(truth,ground_truth+query_idx*config.ground_truth_k, config.K*sizeof(int));
        std::sort(truth, truth+config.K);

        // 对候选集和ground truth进行比较
        int match = 0, c_idx = 0, t_idx = 0;
        while (c_idx < config.K && t_idx < config.K){
            if(candidate[c_idx] < truth[t_idx]){
                while(c_idx < config.K && candidate[c_idx] < truth[t_idx]) c_idx++;
            }
            else if(candidate[c_idx] > truth[t_idx]){
                while(t_idx < config.K && candidate[c_idx] > truth[t_idx]) t_idx++;
            }
            if(c_idx < config.K && t_idx < config.K){
                if(candidate[c_idx] == truth[t_idx]) {
                    match++;
                    c_idx++;
                    t_idx++;
                }

            }
        }
        total_match += match;
//        if(query_idx % 100 == 0) printf("Query point %d acc is %f\n",query_idx, 1.0*match/config.K);
    }
    end_time = clock();
    std::cout << "Total Time : " << (double)(end_time - start_time) / CLOCKS_PER_SEC << "s" << std::endl;
    printf("Total acc is %f\n\n", 1.0*total_match/config.query_data_num);
}

void AKNN::search() {
    srand((unsigned)time(NULL));
    int total_match = 0;
    clock_t start_time, end_time;
    start_time = clock();
    for(int query_idx = 0; query_idx < config.query_data_num; query_idx++){
        value values[config.T * config.R * config.E];
        int is_in[config.base_data_num];
        std::memset(is_in, 0, sizeof(is_in));
        int cur = 0;
        for(int round = 0; round < config.R; round++){
            int Yt = rand()%config.base_data_num;
//            printf("round %d, Yt %d\n",round, Yt);
            for(int t = 0; t < config.T; t++){
                float min_dist = 100000000;
                int nearest = -1;
                for(int i = 0; i < std::min(config.E, config.graph_k); i++){
                    int neibor = graph[Yt*config.graph_k+i];
                    if(!is_in[neibor]){
                        is_in[neibor] = 1;
                        values[cur].s = neibor;
                        values[cur].u = cal_dist(query_idx, neibor);
                        if(values[cur].u < min_dist){
                            min_dist = values[cur].u;
                            nearest = values[cur].s;
                        }
                        cur ++;
                    }
                }
                if(nearest == -1) break;
                else Yt = nearest;
            }
        }
        // sort候选集并与ground truth进行对比求出准确率

        std::sort(values, values+cur);
        int candidate[config.K];
        for(int i = 0; i < config.K; i++) candidate[i] = values[i].s;
        std::sort(candidate, candidate + config.K);


        int truth[config.K];
        std::memcpy(truth,ground_truth+query_idx*config.ground_truth_k, config.K*sizeof(int));
        std::sort(truth, truth+config.K);
        int match = 0, c_idx = 0, t_idx = 0;
        while (c_idx < config.K && t_idx < config.K){
            if(candidate[c_idx] < truth[t_idx]){
                while(c_idx < config.K && candidate[c_idx] < truth[t_idx]) c_idx++;
            }
            else if(candidate[c_idx] > truth[t_idx]){
                while(t_idx < config.K && candidate[c_idx] > truth[t_idx]) t_idx++;
            }
            if(c_idx < config.K && t_idx < config.K){
                if(candidate[c_idx] == truth[t_idx]) {
                    match++;
                    c_idx++;
                    t_idx++;
                }

            }
        }
        total_match += match;
//        if(query_idx % 100 == 0) printf("Query point %d acc is %f\n",query_idx, 1.0*match/config.K);
    }
    end_time = clock();
    std::cout << "Total Time : " << (double)(end_time - start_time) / CLOCKS_PER_SEC << "s" << std::endl;
    printf("Total acc is %f\n", 1.0*total_match/config.query_data_num);
}



/*
 * idx1为需要计算的点在query data中的下标，idx2是base data中的下标，计算他们之间的距离
 * */
float AKNN::cal_dist(int idx1, int idx2) {
    int vec1 = idx1*config.ndim, vec2 = idx2*config.ndim;
    float dist = 0;
    for(int i = 0; i < config.ndim; i++)
        dist += (query_data[i+vec1]-base_data[i+vec2])*(query_data[i+vec1]-base_data[i+vec2]);
    dist = sqrtf(dist);
    return dist;
}

float AKNN::cal_dist_with_AVX(int idx1, int idx2) {
//    double sum = 0;
//    uint32_t i = 0;
//    uint32_t end;
//    end = config.ndim & (-7);
//    float * a = query_data+idx1*config.ndim, * b = base_data+idx2*config.ndim;
//    for(;i<end;i+=8)
//    {
//        __m256 tmp=_mm256_dp_ps(_mm256_load_ps(a+i),_mm256_load_ps(b+i),0xf1);
//        sum+=tmp[0]+tmp[4];
//    }
//    end = config.ndim & (~3);
//    for(;i<end;i+=4)
//    {
//        __m128 C=_mm_dp_ps(_mm_load_ps(a+i),_mm_load_ps(b+i),0xf1);
//        sum+=C[0];
//    }
//    for(; i < config.ndim; i++) sum+=a[i]*b[i];
//    return (float)sum;
}

AKNN::AKNN() {

}


AKNN::AKNN(Config config) {

    load_data(config.base_data_path, base_data, config.base_data_num, config.ndim);
    load_data(config.query_data_path, query_data, config.query_data_num, config.ndim);
    load_data(config.graph_path, graph, config.base_data_num, config.graph_k);
    load_data(config.ground_truth_path, ground_truth, config.query_data_num, config.ground_truth_k);
    this->config = config;
    printf("\n");
    for(int i = 0; i < 10; i++){
        printf("%f ",base_data[i]);
    }
    printf("\n");
    printf("Init AKNN sucess\n");
}


AKNN::~AKNN(){
    delete [] base_data;
    delete [] query_data;
    delete [] graph;
}





