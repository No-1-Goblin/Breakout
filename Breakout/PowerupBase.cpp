#include "PowerupBase.h"
#include <cmath>
#include <iostream>

PowerupBase::PowerupBase(sf::RenderWindow* window, Paddle* paddle, Ball* ball)
    : _time(0.0f) // Initialize the time variable
{
    _window = window;
    _paddle = paddle;
    _sprite.setRadius(RADIUS);
    _isAlive = true;
    _ball = ball;
    for (int i = 0; i < 3; i++) {
        _colours[i] = rand() % 255;
        _colourChangeDir[i] = rand() % 2 == 1 ? 1 : -1;
    }

    // Initial position and direction with some variability
    float initialX = rand() % (int)window->getView().getSize().x * 0.9 + (int)window->getView().getSize().x * 0.05;
    _sprite.setPosition(initialX, 5);
    _direction = { 0.0f, FLOAT_DOWN_SPEED };

}

PowerupBase::~PowerupBase()
{
}

void PowerupBase::update(float dt)
{
    _time += dt; // Increment time

    // Smooth side-to-side movement using a sine wave
    float sineWave = std::sin(_time * 2.0f); // Adjust the frequency as needed
    _direction.x = sineWave * AMPLITUDE_OF_FALL; // Adjust the amplitude as needed

    // Move the power-up
    _sprite.move(_direction.x * dt, _direction.y * dt);

    // Smooth color changes
    for (int i = 0; i < 3; ++i)
    {
        _colours[i] += 50 * dt * _colourChangeDir[i]; // Increment smoothly over time
        if (_colours[i] > 255) {
            _colours[i] = 255;
            _colourChangeDir[i] = -1; // Reverse colour change direction
        }
        else if (_colours[i] < 0) {
            _colours[i] = 0;
            _colourChangeDir[i] = 1; // Reverse colour change direction
        }
    }
    _sprite.setFillColor(sf::Color(static_cast<sf::Uint8>(_colours[0]), static_cast<sf::Uint8>(_colours[1]), static_cast<sf::Uint8>(_colours[2]), 255));

    // Collide with floor (i.e., was missed)
    if (_sprite.getPosition().y + RADIUS * 2 >= _window->getView().getSize().y)
    {
        _isAlive = false;
    }

}

void PowerupBase::render()
{
    _window->draw(_sprite);
}

bool PowerupBase::checkCollisionWithPaddle()
{
    if (_sprite.getGlobalBounds().intersects(_paddle->getBounds()))
    {
        _isAlive = false;
        return true;
    }
    return false;
}

void PowerupBase::setAlive(bool alive)
{
    _isAlive = alive;
}

bool PowerupBase::isAlive()
{
    return _isAlive;
}