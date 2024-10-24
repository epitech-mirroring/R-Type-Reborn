/*
** EPITECH PROJECT, 2024
** R-Type-Reborn
** File description:
** Server.hpp
*/

#ifndef SERVER_HPP
#define SERVER_HPP

#include "GameLogic.hpp"
#include "server/Server.hpp"
#include "dto/DTODecoder.hpp"
#include "dto/DTOEncoder.hpp"
#include "dto/entity/EntityPositionDTO.hpp"
#include "dto/entity/EntityCreationDTO.hpp"
#include "dto/entity/EntityDeletionDTO.hpp"

namespace RType
{
	class Server {
	public:
		Server(unsigned short tcpPort, unsigned short udpPort);
		~Server();

		void runServer();

		void createBufferedEntities() const;
		void deleteBufferedEntities() const;

		[[nodiscard]] int createNewPlayer() const;

		void handleClientInput() const;

	private:
		void sendUpdateEntities() const;

		Network::Server *_network;
		GameLogic *_gameLogic;
		DTOEncoder *_encoder;
		DTODecoder *_decoder;

		float _deltaTimeNetwork;
		float _minDeltaTimeNetwork;
		bool _isRunning;
		unsigned short _tcpPort;
		unsigned short _udpPort;
	#ifdef _WIN32
		std::chrono::steady_clock::time_point _end;
	#else
		std::chrono::system_clock::time_point _end;
	#endif

		std::thread *_networkThread{};
	};
}

#endif //SERVER_HPP
