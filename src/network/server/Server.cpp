/*
** EPITECH PROJECT, 2024
** R-Type-Reborn
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "Server.hpp"
#include <cstdint>
#include <iostream>
#include <asio/error_code.hpp>
#include <asio/ip/udp.hpp>

Network::Server::Server(unsigned short TCP_port, unsigned short UDP_port)
    :_io_context(), _acceptor(_io_context, asio::ip::tcp::endpoint(asio::ip::tcp::v4(), TCP_port)),
      _socket(_io_context, asio::ip::udp::endpoint(asio::ip::udp::v4(), UDP_port)) {
    _TCP_port = TCP_port;
    _UDP_port = UDP_port;
    _recv_buffer.resize(1024);
}

void Network::Server::start(callback function) {
    _callback = std::move(function);

    std::cout << "Server started on TCP port " << _TCP_port << " and UDP port " << _UDP_port << std::endl;
    std::cout << "Server hostname: " << asio::ip::host_name() << std::endl;
    acceptTCP();
    receiveUDP();
    _io_context.run();
}

void Network::Server::stop() {
    _io_context.stop();
    if (_socket.is_open()) {
        _socket.close();
    }
}

void Network::Server::send(const std::vector<uint8_t>& data, const asio::ip::udp::endpoint& client_endpoint) {
    _socket.async_send_to(asio::buffer(data), client_endpoint,
        [](const asio::error_code& error, std::size_t bytes_transferred) {
            if (error) {
                std::cerr << "Error: " << error.message() << std::endl;
            }
        }
    );
}

void Network::Server::acceptTCP() {
    auto socket = std::make_shared<asio::ip::tcp::socket>(_io_context);

    _acceptor.async_accept(*socket, [this, socket](const asio::error_code& error) {
        if (!error) {
            int8_t id = 0; // create_client_id();
            while (_clients.find(id) != _clients.end()) {
                id++; // id = create_client_id();
            }
            _clients[id] = asio::ip::udp::endpoint();
            readTCP(*socket, id);

            asio::write(*socket, asio::buffer(&id, sizeof(id)));
            acceptTCP();
        }
    });
}

void Network::Server::readTCP(asio::ip::tcp::socket& tcp_socket, int8_t id) {
    asio::async_read_until(tcp_socket, asio::dynamic_buffer(_recv_buffer), '\n',
        [this, &tcp_socket, id](const asio::error_code& error, std::size_t bytes_transferred) {
            if (error) {
                if (error == asio::error::eof) {
                    std::cout << "Client disconnected" << std::endl;
                } else {
                    std::cerr << "Error: " << error.message() << std::endl;
                }
                _clients.erase(id);
            } else {
                readTCP(tcp_socket, id);
            }
        }
    );
}

void Network::Server::receiveUDP() {
    _socket.async_receive_from(asio::buffer(_recv_buffer), _remote_endpoint,
        [this](const asio::error_code& error, std::size_t rc_bytes) {
            if (!error && rc_bytes > 0) {
                try {
                    std::string message(_recv_buffer.begin(), _recv_buffer.begin() + rc_bytes);
                    std::cout << "Received: " << message << std::endl;
                } catch (std::exception& e) {
                    std::cerr << "Exception: " << e.what() << std::endl;
                }
            }
            receiveUDP();
        }
    );
}

std::string Network::Server::getHostIP() const {
    return asio::ip::host_name();
}

int8_t Network::Server::create_client_id() {
    static int8_t id = 0;
    return id++;
}
