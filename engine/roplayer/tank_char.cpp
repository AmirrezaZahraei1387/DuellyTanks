//
// Created by KAVOSH on 12/12/2023.
//
#include "tank_char.hpp"

void RoTankPlayer::setPosition(float x, float y){
    tkBody_p.setPosition(x, y);
    setHullOwner();
}

void RoTankPlayer::draw(sf::RenderTarget& target, sf::RenderStates states) const{
    target.draw(tkBody_p);
    target.draw(tkHull_p);
    target.draw(tkOwner_p);
}

void RoTankPlayer::move(const sf::Vector2f offset){
    tkBody_p.move(offset);
    tkHull_p.move(offset);
    tkOwner_p.move(offset);
}

void RoTankPlayer::setHullOwner(){
    // setting the position of the hull and the picture of the owner
    float x , y;

    x = tkBody_p.getPosition().x+tkBody_p.getTexture()->getSize().x/2;
    y = tkBody_p.getPosition().y+tkBody_p.getTexture()->getSize().y/2;

    tkHull_p.setPosition(x-tkHull_p.getTexture()->getSize().x/2,
                         y-tkHull_p.getTexture()->getSize().y/2);
    tkOwner_p.setPosition(x,y);
}