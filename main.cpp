#include "include/Maze.h"
#include "include/Grid.h"
#include "include/Text.h"
#include "include/Bonus.h"
#include <set>


struct Instruction
{
    std::string command;
    std::string argument;
    bool hold = false;
};

void console(Instruction *instruction)
{
    std::cout << "********************************" << std::endl;
    std::cout << "*         Maze Solver          *" << std::endl;
    std::cout << "*                              *" << std::endl;
    std::cout << "*     Wojciech Radzimowski     *" << std::endl;
    std::cout << "*   Politechnika Koszalinska   *" << std::endl;
    std::cout << "********************************" << std::endl;
    std::set<std::string> warg = {"load", "save", "play", "play+", "create"};
    while (instruction->command != "quit")
    {
        while (instruction->hold)
        {}
        if (instruction->command.empty())
        {
            std::cout << "\n>";
            std::cin >> instruction->command;
            if (warg.find(instruction->command) != warg.end())
                std::cin >> instruction->argument;
        }
    }
}

int main()
{
    srand(time(NULL));
    Maze maze;
    Grid grid;
    sf::Clock clock;
    float dt = 0;
    sf::RenderWindow window(sf::VideoMode(600, 600), "Maze solver");
    window.setFramerateLimit(30);
    auto *instruction = new Instruction;
    sf::Thread cthread(&console, instruction);
    cthread.launch();
    Text timer, scores;
    timer.setPosition(sf::Vector2f(10, 10));
    scores.setPosition(sf::Vector2f(50, 50));
    while (window.isOpen())
    {
        std::string stime = std::to_string(maze.getTime());
        timer.setString(stime.substr(0, stime.size() - 4));
        scores.setString(maze.scoresToString());
        sf::Event event{};
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                maze.stopPlaying();
                window.close();
            }
            if (event.type == sf::Event::KeyPressed and maze.isPlaying())
            {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
                    maze.move(1, 0);
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
                    maze.move(-1, 0);
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
                    maze.move(0, 1);
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
                    maze.move(0, -1);
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                {
                    maze.resetTime();
                    maze.stopPlaying();
                }
            }
        }
        grid.setState(maze.getStatemap(), maze.getVisitedmap());
        window.clear(sf::Color(25, 42, 86));
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Tab))
            window.draw(scores);
        else
        {
            grid.draw(&window);
            for (Bonus *b : maze.getBonuses())
                window.draw(*b);
        }
        dt = clock.restart().asSeconds();
        if (maze.isPlaying())
        {
            maze.addTime(dt);
            if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Tab))
                window.draw(timer);
        }
        else
            maze.resetTime();
        window.display();

        if (!maze.isPlaying())
        {
            instruction->hold = false;
            if (instruction->command == "load")
            {
                while (instruction->argument.empty())
                {}
                maze.load(instruction->argument);
                grid.setSize(maze.getSize());
                grid.setState(maze.getStatemap(), maze.getVisitedmap());
            }
            else if (instruction->command == "save")
            {
                while (instruction->argument.empty())
                {}
                maze.save(instruction->argument);
            }
            else if (instruction->command == "create")
            {
                while (instruction->argument.empty())
                {}
                maze.create(std::stoi(instruction->argument));
                grid.setSize(maze.getSize());
                grid.setState(maze.getStatemap(), maze.getVisitedmap());
            }
            else if (instruction->command == "solve")
            {
                maze.solve();
                grid.setState(maze.getStatemap(), maze.getVisitedmap());
            }
            else if (instruction->command == "reset")
            {
                maze.reset();
                grid.setState(maze.getStatemap(), maze.getVisitedmap());
            }
            else if (instruction->command == "play")
            {
                while (instruction->argument.empty())
                {}
                maze.reset();
                maze.resetTime();
                maze.startPlaying(instruction->argument, false);
                instruction->hold = true;
                clock.restart();
                instruction->argument = "";
            }
            else if (instruction->command == "play+")
            {
                while (instruction->argument.empty())
                {}
                maze.reset();
                maze.resetTime();
                maze.startPlaying(instruction->argument, true);
                instruction->hold = true;
                clock.restart();
                instruction->argument = "";
            }
            else if (instruction->command == "quit")
            {
                delete instruction;
                return 0;
            }
            if (!instruction->command.empty())
            {
                instruction->command = "";
                instruction->argument = "";
            }
        }
    }
    return 0;
}