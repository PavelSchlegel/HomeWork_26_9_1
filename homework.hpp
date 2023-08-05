#ifndef HOMEWORK
#define HOMEWORK
#include <iostream>
#include <thread>
#include <vector>
#include <random>
#include <cassert>

int random(int low, int high)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(low, high);
    return dist(gen);
}

void sum(int* result, int* array, int first, int lost) {
    for (int i = first; i < lost; ++i) {
        *result += array[i];
    }
}

class HomeWork {
    private:
    int m_result = 0;
    int* m_array = nullptr;
    public:
        HomeWork() = delete;
        HomeWork(unsigned int N,unsigned int M);
        ~HomeWork();
        int get_result() noexcept;
};

HomeWork::HomeWork(uint N,uint M) {
    assert(N > 0 && "ERROR HomeWork variable N NULL or NEGATIV");
    assert(N < 42 && "ERROR HomeWork variable N > 42 input!");
    if ((M > N || M == N) || M > (N / 2)) {
        M = 2;
    }
    while(true) {
        m_array = new(std::nothrow) int[N];
        if (m_array) {
        for (int i = 0; i < N; ++i) {
            m_array[i] = random(10, 100);
            }
        }
        for (int i = 0; i < N; ++i) {
            std::cout << m_array[i] << ' ';
        }
        std::cout << std::endl;
        break;
    }
    std::vector<std::thread> T;
    uint start = 0;
    uint end = N / M;
    if ((N % M) == 0) {
        for (int i = 0; i < M; ++i) {
            T.push_back(std::thread(sum, &m_result, m_array, *&start, *&end));
            start += N / M;
            end += N / M; //при последней интерации выходит за диапазон но более не используется
        }
    }
    if ((N % M) != 0) {
        for (int i = 0; i < M; ++i) {
            T.push_back(std::thread(sum, &m_result, m_array, *&start, *&end));
            start += N / M;
            end += N / M; //аналогично чётному случаю
        }
        //тут передаём фактический конец массива *&N тем самым end более не опасен
        T.push_back(std::thread(sum, &m_result, m_array, *&start, *&N));
    }
    for (auto it = T.begin(); it != T.end(); ++it) {
        if (it->joinable()) {
            it->join();
        }
    }
}

HomeWork::~HomeWork() {
    delete [] m_array;
}

int HomeWork::get_result() noexcept {
    return m_result;
}
#endif