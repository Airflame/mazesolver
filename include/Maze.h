#ifndef MAZE_H
#define MAZE_H
#include <math.h>
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <queue>
#include <map>
#include <utility>
#include <SFML/System.hpp>
#include "Scores.h"


class Maze
{
    public:
        Maze();
        void load(std::string);
        void save(std::string);
        void create(int);
        void solve();
        void reset();
        int getSize();
        std::vector<std::vector<bool>>& getStatemap();
        std::vector<std::vector<bool>>& getVisitedmap();
        std::string toString();
        void startPlaying(std::string);
        void stopPlaying();
        bool isPlaying();
        void move(int,int);
        void addTime(float);
        void resetTime();
        float getTime();
        std::string scoresToString();

    private:
        void bfs();
        void drawPath();
        void resetVisitedmap();
        void createRec(int,int);
        std::map<std::pair<int,int>,std::pair<int,int>> path;
        std::vector<std::vector<bool>> statemap;
        std::vector<std::vector<bool>> visitedmap;
        std::string mazename, playername;
        int size, in, out, px, py;
        bool solved = false;
        bool playing = false;
        float time = 0;
        Scores scores;
};

#endif
