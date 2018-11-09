#include <utility>
#include "../include/Maze.h"

Maze::Maze()
{
    size = 1;
    statemap = std::vector<std::vector<bool>>(size, std::vector<bool>(size, true));
    visitedmap = std::vector<std::vector<bool>>(size, std::vector<bool>(size, false));
}

void Maze::load(std::string filename)
{
    mazename = filename;
    scores.reset();
    scores.load(mazename);
    filename = "maps/" + filename;
    std::ifstream file;
    file.open(filename);
    if (!file.good())
    {
        std::cout << "File not found" << std::endl;
        file.close();
        return;
    }
    statemap.clear();
    size = 1000;
    for (int i = 0; i < size; i++)
    {
        std::vector<bool> row;
        std::string srow;
        getline(file, srow);
        if (i == 0)
            size = srow.size();
        for (char c : srow)
        {
            switch (c)
            {
                case '#':
                    row.push_back(true);
                    break;

                case ' ':
                    row.push_back(false);
                    break;
            }
        }
        statemap.push_back(row);
    }
    file.close();
    visitedmap = std::vector<std::vector<bool>>(size, std::vector<bool>(size, false));
    for (int i = 0; i < size; i++)
    {
        if (!statemap[0][i])
            in = i;
        if (!statemap[size - 1][i])
            out = i;
    }
    reset();
}

void Maze::save(std::string filename)
{
    reset();
    mazename = filename;
    scores.save(mazename);
    filename = "maps/" + filename;
    std::ofstream file;
    file.open(filename);
    file << toString();
    file.close();
}

void Maze::create(int s)
{
    mazename = "";
    scores.reset();
    if (s % 2 != 1)
    {
        s -= s % 2;
        s += 1;
    }
    size = s;
    statemap.clear();
    statemap = std::vector<std::vector<bool>>(size, std::vector<bool>(size, true));
    visitedmap = std::vector<std::vector<bool>>(size, std::vector<bool>(size, false));
    in = rand() % s;
    if (in < 3)
        in = 3;
    if (in > size - 4)
        in = size - 3;
    for (int i = 0; i <= 2; i++)
        statemap[i][in] = false;
    createRec(2, in);
    bool temp = false;
    for (int y = size - 1; y > 0; y--)
    {
        for (int x = 0; x < size; x++)
        {
            if (!statemap[y][x])
            {
                out = x;
                temp = true;
                break;
            }
        }
        if (temp)
            break;
    }
    for (int y = size - 1; statemap[y][out]; y--)
        statemap[y][out] = false;
    reset();
}

void Maze::createRec(int y, int x)
{
    int dir1 = rand() % 4;
    int dir2 = dir1;
    while (dir2 == dir1)
        dir2 = rand() % 4;
    if (y >= size - 1)
    {
        int diff = size - y;
        for (int i = 0; i < diff; i++)
        {
            statemap[y + i][x] = true;
        }
        return;
    }
    switch (dir1)
    {
        case 0:
            if (y <= 5)
                break;
            if (!statemap[y - 1][x] or !statemap[y - 2][x])
                break;
            else
            {
                statemap[y - 1][x] = false;
                statemap[y - 2][x] = false;
                createRec(y - 2, x);
            }
            break;

        case 1:
            if (y >= size - 5)
                break;
            if (!statemap[y + 1][x] or !statemap[y + 2][x])
                break;
            else
            {
                statemap[y + 1][x] = false;
                statemap[y + 2][x] = false;
                createRec(y + 2, x);
            }
            break;

        case 2:
            if (x <= 5)
                break;
            if (!statemap[y][x - 1] or !statemap[y][x - 2])
                break;
            else
            {
                statemap[y][x - 1] = false;
                statemap[y][x - 2] = false;
                createRec(y, x - 2);
            }
            break;

        case 3:
            if (x >= size - 5)
                break;
            if (!statemap[y][x + 1] or !statemap[y][x + 2])
                break;
            else
            {
                statemap[y][x + 1] = false;
                statemap[y][x + 2] = false;
                createRec(y, x + 2);
            }
            break;
    }
    switch (dir2)
    {
        case 0:
            if (y <= 5)
                break;
            if (!statemap[y - 1][x] or !statemap[y - 2][x])
                break;
            else
            {
                statemap[y - 1][x] = false;
                statemap[y - 2][x] = false;
                createRec(y - 2, x);
            }
            break;

        case 1:
            if (y >= size - 5)
                break;
            if (!statemap[y + 1][x] or !statemap[y + 2][x])
                break;
            else
            {
                statemap[y + 1][x] = false;
                statemap[y + 2][x] = false;
                createRec(y + 2, x);
            }
            break;

        case 2:
            if (x <= 5)
                break;
            if (!statemap[y][x - 1] or !statemap[y][x - 2])
                break;
            else
            {
                statemap[y][x - 1] = false;
                statemap[y][x - 2] = false;
                createRec(y, x - 2);
            }
            break;

        case 3:
            if (x >= size - 5)
                break;
            if (!statemap[y][x + 1] or !statemap[y][x + 2])
                break;
            else
            {
                statemap[y][x + 1] = false;
                statemap[y][x + 2] = false;
                createRec(y, x + 2);
            }
            break;
    }
}

void Maze::solve()
{
    if (!solved)
    {
        bfs();
        drawPath();
        solved = true;
    }
}

void Maze::bfs()
{
    std::vector<std::vector<bool>> wstatemap = statemap;
    std::queue<int> qy;
    std::queue<int> qx;
    wstatemap[0][in] = 1;
    int x = in;
    int y = 1;
    path[std::make_pair(1, in)] = std::make_pair(0, in);
    while (x != out or y != size - 1)
    {
        wstatemap[y][x] = 1;
        if (wstatemap[y + 1][x] == 0)
        {
            qy.push(y + 1);
            qx.push(x);
            path[std::make_pair(y + 1, x)] = std::make_pair(y, x);
        }
        if (wstatemap[y - 1][x] == 0)
        {
            qy.push(y - 1);
            qx.push(x);
            path[std::make_pair(y - 1, x)] = std::make_pair(y, x);
        }
        if (wstatemap[y][x + 1] == 0)
        {
            qy.push(y);
            qx.push(x + 1);
            path[std::make_pair(y, x + 1)] = std::make_pair(y, x);
        }
        if (wstatemap[y][x - 1] == 0)
        {
            qy.push(y);
            qx.push(x - 1);
            path[std::make_pair(y, x - 1)] = std::make_pair(y, x);
        }
        y = qy.front();
        x = qx.front();
        qy.pop();
        qx.pop();
    }
}

void Maze::drawPath()
{
    int y = size - 1;
    int x = out;
    visitedmap[y][x] = true;
    while (y != 0)
    {
        std::pair<int, int> prev = path[std::make_pair(y, x)];
        y = prev.first;
        x = prev.second;
        visitedmap[y][x] = true;
    }
}

void Maze::reset()
{
    solved = false;
    path.clear();
    resetVisitedmap();
}

void Maze::resetVisitedmap()
{
    for (int y = 0; y < size; y++)
    {
        for (int x = 0; x < size; x++)
        {
            visitedmap[y][x] = false;
        }
    }
}

int Maze::getSize()
{
    return size;
}

std::vector<std::vector<bool>> &Maze::getStatemap()
{
    return statemap;
}

std::vector<std::vector<bool>> &Maze::getVisitedmap()
{
    return visitedmap;
}

std::string Maze::toString()
{
    std::string result;
    for (auto row : statemap)
    {
        for (auto n : row)
        {
            char c;
            if (n)
                c = '#';
            else
                c = ' ';
            result += c;
        }
        result += "\n";
    }
    return result;
}

void Maze::startPlaying(std::string name)
{
    playername = std::move(name);
    reset();
    playing = true;
    py = 0;
    px = in;
    visitedmap[py][px] = true;
}

void Maze::stopPlaying()
{
    scores.insert(playername, time);
    scores.save(mazename);
    playing = false;
    reset();
}

bool Maze::isPlaying()
{
    return playing;
}

void Maze::move(int dy, int dx)
{
    if ((dy == -1 and py == 0) or statemap[py + dy][px + dx] or visitedmap[py + dy][px + dx])
        return;
    visitedmap[py][px] = false;
    py += dy;
    px += dx;
    visitedmap[py][px] = true;
    if (py == size - 1)
        stopPlaying();
}

void Maze::addTime(float dt)
{
    time += dt;
    time = roundf(time * 100) / 100;
}

void Maze::resetTime()
{
    time = 0;
}

float Maze::getTime()
{
    return time;
}

std::string Maze::scoresToString()
{
    return scores.toString();
}