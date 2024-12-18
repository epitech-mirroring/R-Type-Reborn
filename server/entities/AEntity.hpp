/*
** EPITECH PROJECT, 2024
** R-Type-Reborn
** File description:
** AEntity.hpp
*/

#ifndef AENTITY_HPP
#define AENTITY_HPP

#include <vector>

#include "IEntity.hpp"

/**
 * @class AEntity
 * @brief Abstract class for all entities
 * @version v0.1.0
 * @since v0.1.0
 * @author Marius PAIN
 */
class AEntity : public IEntity {
public:

	/**
     * @brief The destructor of the AEntity class
     * @version v0.1.0
     * @since v0.1.0
     * @author Marius PAIN
     */
	~AEntity() override = default;

	/**
     * @brief The update function of the entity
     * This is meant to be runt by the parent object and update the entity every frame
     * @note This is a pure virtual function and must be implemented in the child class
     * @param elapsedTime The time elapsed since the last frame
     * @param entityManager The entity manager
     * @version v0.1.0
     * @since v0.1.0
     * @author Marius PAIN
    */
    void update(float elapsedTime, EntityManager &entityManager) override = 0;

	/**
     * @brief The collision function of the entity
     * This is meant to be runt by the parent object and check if the entity is colliding with another entity
     * @note This is a pure virtual function and must be implemented in the child class
     * @param entity The entity to check collision with
     * @return True if the entity is colliding with the other entity, false otherwise
     * @version v0.1.0
     * @since v0.1.0
     * @author Marius PAIN
     */
	bool isColliding(IEntity* entity) const override;

	/**
     * @brief The on collision function of the entity
     * This is meant to be runt by the parent object and do something when the entity is colliding with another entity
     * @note This is a pure virtual function and must be implemented in the child class
     * @param entity The entity to check collision with
     * @version v0.1.0
     * @since v0.1.0
     * @author Marius PAIN
     */
	void onCollision(IEntity* entity) override;

	/**
     * @brief Get the id of the entity
     * @return The id of the entity
     * @version v0.1.0
     * @since v0.1.0
     * @author Marius PAIN
     */
	[[nodiscard]] int getId() const override;

	/**
     * @brief Get the type of the entity
     * @return The type of the entity
     * @version v0.1.0
     * @since v0.1.0
     * @author Marius PAIN
     */
	[[nodiscard]] EntityType getEntityType() const override;

	/**
     * @brief Get the x position of the entity
     * @return The x position of the entity
     * @version v0.1.0
     * @since v0.1.0
     * @author Marius PAIN
     */
    [[nodiscard]] float getPosX() const override;

	/**
     * @brief Get the y position of the entity
     * @return The y position of the entity
     * @version v0.1.0
     * @since v0.1.0
     * @author Marius PAIN
     */
    [[nodiscard]] float getPosY() const override;

	/**
     * @brief Get the speed of the entity
     * @return The speed of the entity
     * @version v0.1.0
     * @since v0.1.0
     * @author Marius PAIN
     */
    [[nodiscard]] float getSpeed() const override;

	/**
     * @brief Get the width of the entity
     * @return The width of the entity
     * @version v0.1.0
     * @since v0.1.0
     * @author Marius PAIN
     */
    [[nodiscard]] int getWidth() const override;

	/**
     * @brief Get the height of the entity
     * @return The height of the entity
     * @version v0.1.0
     * @since v0.1.0
     * @author Marius PAIN
     */
    [[nodiscard]] int getHeight() const override;

	/**
     * @brief Get the direction of the entity
     * @return The direction of the entity
     * @version v0.1.0
     * @since v0.1.0
     * @author Marius PAIN
     */
    [[nodiscard]] std::vector<EntityDirection> getDirection() const override;

	/**
	 * @brief Get the damage that the entity does
	 * @return The damage that the entity does
	 * @version v0.1.0
	 * @since v0.1.0
	 * @author Marius PAIN
	 */
	[[nodiscard]] int getDamage() const override;

	/**
	 * @brief Get the life of the entity
	 * @return The life of the entity
	 * @version v0.1.0
	 * @since v0.1.0
	 * @author Marius PAIN
	 */
	[[nodiscard]] int getLife() const override;

	/**
     * @brief The setter for the id of the entity
     * @param entityId The id of the entity
     * @version v0.1.0
     * @since v0.1.0
     * @author Marius PAIN
     */
	void setId(int entityId) override;

	/**
     * @brief The setter for the type of the entity
     * @param entityType The type of the entity
     * @version v0.1.0
     * @since v0.1.0
     * @author Marius PAIN
     */
	void setEntityType(EntityType entityType) override;

	/**
	 * @brief The setter for the x position of the entity
	 * @param posX The x position of the entity
	 * @version v0.1.0
	 * @since v0.1.0
	 * @author Marius PAIN
	 */
	void setPosX(float posX) override;

	/**
	 * @brief The setter for the y position of the entity
	 * @param posY The y position of the entity
	 * @version v0.1.0
	 * @since v0.1.0
	 * @author Marius PAIN
	 */
	void setPosY(float posY) override;

	/**
	 * @brief The setter for the speed of the entity
	 * @param speed The speed of the entity
	 * @version v0.1.0
	 * @since v0.1.0
	 * @author Marius PAIN
	 */
	void setSpeed(float speed) override;

	/**
	 * @brief The setter for the width of the entity
	 * @param width The width of the entity
	 * @version v0.1.0
	 * @since v0.1.0
	 * @author Marius PAIN
	 */
	void setWidth(int width) override;

	/**
	 * @brief The setter for the height of the entity
	 * @param height The height of the entity
	 * @version v0.1.0
	 * @since v0.1.0
	 * @author Marius PAIN
	 */
	void setHeight(int height) override;

	/**
	 * @brief The setter for the direction of the entity
	 * @param direction The direction of the entity
	 * @version v0.1.0
	 * @since v0.1.0
	 * @author Marius PAIN
	 */
	void setDirection(std::vector<EntityDirection> direction) override;

	/**
     * @brief The setter for the direction of the entity
     * @param direction The direction of the entity
     * @version v0.1.0
     * @since v0.1.0
     * @author Marius PAIN
     */
	void addDirection(EntityDirection direction) override;

	/**
     * @brief The setter for the direction of the entity
     * @param direction The direction of the entity
     * @version v0.1.0
     * @since v0.1.0
     * @author Marius PAIN
     */
	void removeDirection(EntityDirection direction) override;

	/**
	 * @brief Set the damage that the entity does
	 * @param damage The damage that the entity does
	 * @version v0.1.0
	 * @since v0.1.0
	 * @author Marius PAIN
	 */
	void setDamage(int damage) override;

	/**
     * @brief Set the life of the entity
     * @param life The life of the entity
     * @version v0.1.0
     * @since v0.1.0
     * @author Marius PAIN
     */
	void setLife(int life) override;

protected:
	/**
     * @brief The constructor of the AEntity class
     * @note This is a protected constructor and can only be called by the child class
     * @param entityId The id of the entity
     * @param entityType The type of the entity
     * @param posX The x position of the entity
     * @param posY The y position of the entity
     * @param speed The speed of the entity
     * @param width The width of the entity
     * @param height The height of the entity
     * @param damage The damage that the entity does
     * @param life The life of the entity
     * @param direction The list of directions of the entity
     * @version v0.1.0
     * @since v0.1.0
     * @author Marius PAIN
     */
	AEntity(int entityId, EntityType entityType, float posX, float posY, int width, int height, float speed, int damage, int life, const std::vector<EntityDirection>& direction);

	/**
	 * @brief The move function of the entity
	 * This is meant to be runt by the parent object and update the entity position
	 * @param elapsedTime The time elapsed since the last frame
	 * @version v0.1.0
	 * @since v0.1.0
	 * @author Marius PAIN
	 */
	void move(float elapsedTime);

	/**
     * @brief The id of the entity
     */
    int _id;

	/**
     * @brief The type of the entity
     */
	EntityType _entityType;

	/**
     * @brief The x position of the entity
     */
    float _posX;

	/**
     * @brief The y position of the entity
     */
	float _posY;

	/**
     * @brief The speed of the entity
     */
    float _speed;

	/**
     * @brief The width of the entity
     */
    int _width;

	/**
     * @brief The height of the entity
     */
    int _height;

	/**
     * @brief The damage that the entity does
     */
	int _damage;

	/**
     * @brief The life of the entity
     */
	int _life;

	/**
     * @brief The direction of the entity
     */
    std::vector<EntityDirection> _directions;
};

#endif //AENTITY_HPP
