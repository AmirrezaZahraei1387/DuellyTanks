#include <iostream>
#include <SFML/Graphics.hpp>
#include "engine/roplayer/tank_char.hpp"

int main() {
    sf::RenderWindow window{sf::VideoMode::getDesktopMode(), "example"};

    sf::Texture bd{};
    bd.loadFromFile("Hull_01.png");
    sf::Texture hl{};
    hl.loadFromFile("Gun_07.png");
    sf::Texture on{};
    on.loadFromFile("ali.png");

    sf::Sprite bd_s{bd};
    sf::Sprite hl_s{hl};
    sf::Sprite on_s{on};
    on_s.setScale(0.2, 0.2);

    RoTankPlayer tankChar{bd_s, hl_s, on_s};
    tankChar.setPosition(300, 500);
    while(window.isOpen()){

        sf::Event event;
        while(window.pollEvent(event)){
            if(event.type == sf::Event::Closed){
                window.close();
            }else if(event.key.code == sf::Keyboard::W){
                tankChar.move(sf::Vector2f(0, -6));

            }else if(event.key.code == sf::Keyboard::S){
                tankChar.move(sf::Vector2f(0, 6));
            }
        }

        window.clear(sf::Color::White);
        window.draw(tankChar);
        window.display();
    }
    return 0;
}
