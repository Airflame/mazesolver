#include "../include/Scores.h"

void Scores::insert(std::string name, float time)
{
    if (time == 0)
        return;
    if (scorestable.empty() or (scorestable.size() < 10 and scorestable[scorestable.size() - 1].second < time))
    {
        scorestable.push_back(std::make_pair(name, time));
        return;
    }
    for (int i = 0; i < scorestable.size(); i++)
    {
        if (scorestable[i].second > time)
        {
            scorestable.insert(scorestable.begin() + i, std::make_pair(name, time));
            break;
        }
    }
    if (scorestable.size() > 5)
        scorestable.pop_back();
}

void Scores::reset()
{
    scorestable.clear();
}

void Scores::load(std::string filename)
{
    filename = "maps/hs/" + filename;
    std::ifstream file;
    file.open(filename);
    if (!file.good())
        return;
    reset();
    while (!file.eof())
    {
        std::string n;
        file >> n;
        float t;
        file >> t;
        insert(n, t);
    }
    file.close();
}

void Scores::save(std::string filename)
{
    if (scorestable.empty())
        return;
    filename = "maps/hs/" + filename;
    std::ofstream file;
    file.open(filename);
    file << toString();
    file.close();
}

std::string Scores::toString()
{
    std::string res;
    for (int i = 0; i < scorestable.size(); i++)
    {
        res += scorestable[i].first;
        res += "   ";
        std::string stime = std::to_string(scorestable[i].second);
        res += stime.substr(0, stime.size() - 4);
        res += "\n";
    }
    return res;
}
