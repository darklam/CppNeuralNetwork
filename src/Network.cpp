#include "Network.h"
#include <fstream>
#include <string>

typedef std::vector<std::string> stringArray;

Network::Network(const std::string &fileName){

    std::ifstream i(fileName);

    json j;

    i >> j;

    i.close();

    std::vector<std::string> layers = j["layers"];

    

}