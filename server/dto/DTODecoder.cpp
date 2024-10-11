/*
** EPITECH PROJECT, 2024
** R-Type-Reborn
** File description:
** DTODecoder.cpp
*/

#include "DTODecoder.hpp"
#include "../utils/BinaryVector.hpp"

DTODecoder::DTODecoder(): _dtoRegistry(nullptr)
{
}

DTODecoder::DTODecoder(DTORegistry *dtoRegistry): _dtoRegistry(dtoRegistry)
{
}

IDTO *DTODecoder::decode(std::vector<char> &data) const
{
	if (this->_dtoRegistry == nullptr) {
		// TODO: Throw exception
		return nullptr;
	}
	const int dtoId = BinaryConversion::consume<int>(data);
	IDTO *dto = this->_dtoRegistry->getDTOById(dtoId)->clone();
	dto->deserialize(data);
	return dto;
}

DTORegistry &DTODecoder::getDTORegistry() const
{
	return *this->_dtoRegistry;
}

void DTODecoder::setDTORegistry(DTORegistry *dtoRegistry)
{
	this->_dtoRegistry = dtoRegistry;
}