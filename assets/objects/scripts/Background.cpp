/*
** EPITECH PROJECT, 2024
** R-Type-Reborn
** File description:
** Background.cpp
*/

#include "Background.hpp"

Background::Background(IObject *owner, const json::IJsonObject *data) : CPPMonoBehaviour(owner) {}

void Background::start() {
    startTime = clock();
    auto *transform = getParentComponent<Transform>();
    transform->setPosition(Vector3(0, 0, 0));
}
#include <iostream>

void Background::update() {
    clock_t actualTime = clock();
    if ((actualTime - startTime) > 3000) {
        auto *transform = getParentComponent<Transform>();
        transform->setPosition(Vector3(transform->getPosition().x - 10, transform->getPosition().y, -10));
        if (transform->getPosition().x <= -1920)
            transform->setPosition(Vector3(0, transform->getPosition().y, -10));
        startTime = actualTime;
    }
}

void Background::setSpeed(float newSpeed) {
    speed = newSpeed;
}

float Background::getSpeed() {
    return speed;
}

IComponent *Background::clone (IObject *owner) const {
    return nullptr;
}

void Background::deserialize(const json::IJsonObject *data) {}

void Background::end() {}

json::IJsonObject *Background::serializeData() {
    return nullptr;
}