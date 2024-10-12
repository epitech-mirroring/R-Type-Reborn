/*
** EPITECH PROJECT, 2024
** R-Type-Reborn
** File description:
** BasicEnemy.cpp
*/

#include "BasicEnemy.hpp"

#include <algorithm>
#include "ClassicBullet.hpp"

BasicEnemy::BasicEnemy(const int entityId, const float posY) : AShip(entityId)
{
	this->_direction = LEFT;
	this->_speed = 5;
	this->_width = 50;
	this->_height = 50;
	this->_life = 1;
	this->_damage = 1;
	this->_isShooting = true;
	this->_shootCooldown = 0.8;
	this->_currentShootCooldown = 0;
	this->_posX = 1920;
	this->_posY = std::min<float>(std::max<float>(posY, 0.F), static_cast<float>(1080 - this->_height));
}

void BasicEnemy::update(const float elapsedTime, EntityManager &entityManager)
{
	this->move(elapsedTime);
	if (this->_isShooting) {
		this->_currentShootCooldown += elapsedTime;
		if (this->_currentShootCooldown >= this->_shootCooldown) {
			this->_currentShootCooldown = 0;
			IEntity *bullet = new ClassicBullet(entityManager.getNewId(), LEFT, this->_posX, this->_posY + (this->_height / 2));
			entityManager.addEntity(bullet);
		}
	}
}