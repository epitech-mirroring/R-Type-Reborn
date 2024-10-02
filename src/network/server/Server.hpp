/*
** EPITECH PROJECT, 2024
** R-Type-Reborn
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#ifndef SERVER_HPP
#define SERVER_HPP

#include <asio.hpp>
#include <vector>
#include <unordered_map>

/**
 * @namespace Network
 * @brief Main namespace for the network library
 * @details This namespace contains all the classes, functions and enums for the network library
 * @version 0.1.0
 * @since 0.1.0
 * @author Simon GANIER-LOMBARD
 */
namespace Network {

    /**
     * @class Server
     * @brief Represents a network server
     * @details This class handles the network server operations such as starting, stopping, sending, and receiving data.
     * @version 0.1.0
     * @since 0.1.0
     * @author Simon GANIER-LOMBARD
     */
    class Server {
        using callback = std::function<void(const std::vector<uint8_t> &data,
         const asio::ip::udp::endpoint &client_endpoint)>;
        public:
            /**
             * @brief Constructs a new Server object
             * @param TCP_port The TCP port to use
             * @param UDP_port The UDP port to use
             * @version 0.1.0
             * @since 0.1.0
             * @author Simon GANIER-LOMBARD
             */
            explicit Server(unsigned short TCP_port, unsigned short UDP_port);

            /**
             * @brief Starts the server listening for incoming connections
             * @param function The callback function to handle received data
             * @version 0.1.0
             * @since 0.1.0
             * @author Simon GANIER-LOMBARD
             */
            void start(callback function);

            /**
             * @brief Stops the server and closes all connections
             * @version 0.1.0
             * @since 0.1.0
             * @author Simon GANIER-LOMBARD
             */
            void stop();

            /**
             * @brief Sends data to a client with a specific endpoint in UDP mode
             * @param data The data to send
             * @param client_endpoint The endpoint of the client to send data to
             * @version 0.1.0
             * @since 0.1.0
             * @author Simon GANIER-LOMBARD
             */
            void send(const std::vector<uint8_t> &data, const asio::ip::udp::endpoint &client_endpoint);

            /**
             * @brief Accepts a new TCP connection
             * @version 0.1.0
             * @since 0.1.0
             * @author Simon GANIER-LOMBARD
             */
            void acceptTCP();

            /**
             * @brief Reads data from a TCP connection
             * @param tcp_socket The TCP socket to read from
             * @param id The client ID
             * @version 0.1.0
             * @since 0.1.0
             * @author Simon GANIER-LOMBARD
             */
            void readTCP(asio::ip::tcp::socket &tcp_socket, int8_t id);

            /**
             * @brief Receives data from a UDP connection
             * @version 0.1.0
             * @since 0.1.0
             * @author Simon GANIER-LOMBARD
             */
            void receiveUDP();

            /**
             * @brief Creates a new client ID
             * @return The new client ID
             * @version 0.1.0
             * @since 0.1.0
             * @author Simon GANIER-LOMBARD
             */
            static int8_t create_client_id();

           /**
            * @brief Gets the host IP address
            * @return The host IP address on the current network
            * @version 0.1.0
            * @since 0.1.0
            * @author Simon GANIER-LOMBARD
            */
            std::string getHostIP() const;

        private:
            unsigned short _TCP_port; ///< The TCP port
            unsigned short _UDP_port; ///< The UDP port

            asio::io_context _io_context; ///< The IO context
            asio::ip::tcp::acceptor _acceptor; ///< The TCP acceptor for incoming connections
            asio::ip::udp::socket _socket; ///< The UDP socket for incoming connections

            std::unordered_map<std::int8_t, asio::ip::udp::endpoint> _clients; ///< The clients map with their ID and endpoint
            std::vector<uint8_t> _recv_buffer; ///< The receive buffer for incoming data
            asio::ip::udp::endpoint _remote_endpoint; ///< The remote endpoint
            callback _callback; ///< The callback function
    };
}

#endif // SERVER_HPP
