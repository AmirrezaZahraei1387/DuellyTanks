//
// Created by KAVOSH on 12/6/2023.
//
#ifndef WINT_TANK_CHAR_HPP
#define WINT_TANK_CHAR_HPP
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class RoTankPlayer: public sf::Drawable{

public:

    explicit RoTankPlayer(sf::Sprite& tkBody, sf::Sprite& tkHull, sf::Sprite& tkOwner)
    :tkBody_p(tkBody),
    tkHull_p(tkHull),
    tkOwner_p(tkOwner)
    {
        setHullOwner();
    }

    void setPosition(float x, float y);

    void draw(sf::RenderTarget& target, sf::RenderStates states)  const override;

    void move(sf::Vector2f offset);

private:

    void setHullOwner();

    sf::Sprite tkBody_p{};
    sf::Sprite tkHull_p{};
    sf::Sprite tkOwner_p{};
};
#endif //WINT_TANK_CHAR_HPP
