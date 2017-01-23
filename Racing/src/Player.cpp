//
//  Player.cpp
//  Racing
//
//  Created by Joseph Persie on 1/22/17.
//  Copyright © 2017 StartupMedia. All rights reserved.
//
#include <SFML/Graphics.hpp>
#include <math.h>
#include "ResourcePath.hpp"
#include <iostream>
#include "Player.hpp"
#include "Screen.hpp"
#include <SFML/Audio.hpp>

void Player::createSprite(const Screen *screen) {
    
    sf::Texture playerTexture;
    std::string filePath = resourcePath() + "mercedesspritesheets.png";
    playerTexture.loadFromFile(filePath);
    playerTexture.setSmooth(true);
    
    sprite.setTexture(playerTexture);

    sprite.setTextureRect(sf::IntRect(407, 0, 40, 43));
    sprite.setPosition(screen->width/2 - 20, 500);
    sprite.setScale(3, 3);
}

void Player::turnRight(const float turnWeight) {
    x += turnWeight;

    sprite.setTextureRect(sf::IntRect(407 + 44, 0, 40, 43));
}

void Player::turnLeft(const float turnWeight) {
    x -= turnWeight;

    sprite.setTextureRect(sf::IntRect(407 - 44, 0, 40, 43));
}

void Player::steerStraight(void) {
    
    sprite.setTextureRect(sf::IntRect(407, 0, 40, 43));
}

void Player::playIdleSound(void) {

    
    if(idleSound.getStatus() == idleSound.Playing) return;
    
    if(brakeSound.getStatus() == brakeSound.Playing) {
        brakeSound.stop();
    }
    else if(accelerateSound.getStatus() == accelerateSound.Playing) {
        accelerateSound.stop();
    }
    
    idleSound.setLoop(true);

    if(speed > 200.0f) {
        idleSound.setPitch(1.4f);
    }
    else {
        idleSound.setPitch(1.0f);
    }
    
    idleSound.play();
}

void Player::playBrakeSound(void) {
    
    if(brakeSound.getStatus() == brakeSound.Playing) return;
    
    
    if(idleSound.getStatus() == idleSound.Playing) {
        idleSound.stop();
    }
    else if(accelerateSound.getStatus() == accelerateSound.Playing) {
        accelerateSound.stop();
    }
    brakeSound.play();
}

void Player::playAccelerateSound(void) {
    
    if(accelerateSound.getStatus() == accelerateSound.Playing) return;
    
    if(brakeSound.getStatus() == brakeSound.Playing) {
        brakeSound.stop();
    }
    else if(idleSound.getStatus() == idleSound.Playing) {
        idleSound.stop();
    }
    
    if(speed > 200.0f) {
       accelerateSound.setPitch(1.2f);
    }
    else {
       accelerateSound.setPitch(1.0f);
    }
    
    accelerateSound.play();
}

Player::Player() {

    
    printf("contsructor called\n");
    
    if (!brakeSound.openFromFile(resourcePath() + "car1-braking.ogg")) {
    }


    if (!accelerateSound.openFromFile(resourcePath() + "car1-accelerating.ogg")) {
    }
    

    if (!idleSound.openFromFile(resourcePath() + "car1-idle.ogg")) {
    }
    
    speed = 0.0f;
}

