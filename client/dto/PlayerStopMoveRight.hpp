/*
** EPITECH PROJECT, 2024
** R-Type-Reborn
** File description:
** PlayerStopMoveRight.hpp
*/

#ifndef PLAYERSTOPMOVERIGHT_HPP
#define PLAYERSTOPMOVERIGHT_HPP

#include "APlayerDTO.hpp"

/**
 * @class PlayerStopMoveRight
 * @brief Class for Player Start Shoot DTO
 * @inherit APlayerDTO
 * @version v0.1.0
 * @since v0.1.0
 * @author Aubane NOURRY
 */
class PlayerStopMoveRight final: public APlayerDTO {
public:
	/**
	 * @brief The constructor of the PlayerStopMoveRight class
	 * @note This constructor is used for deserialization
	 * (all the attributes are set to default values)
	 * @version v0.1.0
	 * @since v0.1.0
	 * @author Aubane NOURRY
	 */
	PlayerStopMoveRight();

	/**
	 * @brief The constructor of the PlayerStopMoveRight class
	 * @param playerID The id of the entity
	 * @param key The type of the entity
	 * @version v0.1.0
	 * @since v0.1.0
	 * @author Aubane NOURRY
	 */
	PlayerStopMoveRight(int playerID);

	/**
     * @brief The destructor of the PlayerStopMoveRight class
     * @version v0.1.0
     * @since v0.1.0
	 * @author Aubane NOURRY
     */
	~PlayerStopMoveRight() override = default;

	/**
     * @brief Clone the DTO (create a new instance of the DTO)
     * @return The cloned DTO
     * @version v0.1.0
     * @since v0.1.0
     * @author Aubane NOURRY
     */
	IDTO *clone() override;

	/**
     * @brief Serialize the DTO to a vector of char (binary)
     * @return The serialized entity
     * @version v0.1.0
     * @since v0.1.0
     * @author Aubane NOURRY
     */
    std::vector<char> serializePlayer() override;

	/**
     * @brief Deserialize the DTO from a vector of char (binary)
     * @note It will fill the attributes of the DTO with the data
     * @param data The data to deserialize
     * @version v0.1.0
     * @since v0.1.0
     * @author Aubane NOURRY
     */
	void deserializePlayer(std::vector<char>& data) override;
};

#endif //PLAYERSTOPMOVERIGHT_HPP
