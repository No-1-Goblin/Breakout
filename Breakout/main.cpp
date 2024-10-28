#include <SFML/Graphics.hpp>
#include "GameManager.h"
#include <iostream>
#include "SoundHandler.h"

int main()
{
    srand(time(0));
    sf::RenderWindow window(sf::VideoMode(1000, 800), "Breakout");
    sf::View defaultView(sf::FloatRect(sf::Vector2f(0, 0), sf::Vector2f(1000, 800)));
    window.setView(defaultView);
    SoundHandler soundHandler;
    GameManager gameManager(&window, &soundHandler);
    gameManager.initialize();

    sf::Clock clock;
    float deltaTime;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        deltaTime = clock.restart().asSeconds();

        gameManager.update(deltaTime);

        window.clear();
        gameManager.render();
        window.display();
    }

    return 0;
}
