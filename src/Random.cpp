#include <random>
#include "Random.h"

double Random::randomDouble(double min, double max){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> dist(min, max);
    return dist(gen);
}

double Random::randomDouble(double max){
    return Random::randomDouble(0, max);
}

double Random::randomDouble(){
    return Random::randomDouble(0, 1);
}

int Random::randomInt(int min, int max){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(min, max);
    return dist(gen);
}