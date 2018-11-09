#include "../include/Grid.h"

Grid::Grid()
{
    setSize(1);
}

void Grid::setSize(int n)
{
    float d = 1000.0f / (float) n;
    tiles = std::vector<std::vector<Tile>>(n, std::vector<Tile>(n, Tile(d)));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            tiles[i][j].setPosition(sf::Vector2f(j * d, i * d));
        }
    }
}

void Grid::draw(sf::RenderWindow *window)
{
    for (auto row : tiles)
    {
        for (auto tile : row)
        {
            window->draw(tile);
        }
    }
}

void Grid::setState(std::vector<std::vector<bool>> &maze, std::vector<std::vector<bool>> &visited)
{
    for (int y = 0; y < maze.size(); y++)
    {
        for (int x = 0; x < maze[y].size(); x++)
        {
            tiles[y][x].setState(maze[y][x]);
            if (visited[y][x])
                tiles[y][x].setState(2);
        }
    }
}
