#ifndef SCORES_H
#define SCORES_H
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <utility>


class Scores
{
public:
    Scores() = default;
    void insert(std::string,float);
    void reset();
    void load(std::string);
    void save(std::string);
    std::string toString();

private:
    std::vector<std::pair<std::string,float>> scorestable;

};

#endif
