/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelabbas <zelabbas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 14:45:56 by zelabbas          #+#    #+#             */
/*   Updated: 2024/08/17 14:46:47 by zelabbas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <boost/asio.hpp>
#include <iostream>

using boost::asio::ip::tcp;

int main() {
    try {
        // Step 1: Create an I/O context
        boost::asio::io_context io_context;

        // Step 2: Resolve the server name to an IP address
        tcp::resolver resolver(io_context);
        tcp::resolver::results_type endpoints = resolver.resolve("example.com", "http");

        // Step 3: Create and open a socket
        tcp::socket socket(io_context);
		boost::asio::connect(socket, endpoints);

        // Step 4: Formulate the HTTP request
        std::string request = 
            "GET / HTTP/1.1\r\n"
            "Host: example.com\r\n"
            "Connection: close\r\n\r\n";

        // Step 5: Send the HTTP request to the server
        boost::asio::write(socket, boost::asio::buffer(request));

        // Step 6: Read the response from the server
        boost::asio::streambuf response;
        boost::asio::read_until(socket, response, "\r\n");

        // Step 7: Check if the response is OK (HTTP/1.1 200 OK)
        std::istream response_stream(&response);
        std::string http_version;
        response_stream >> http_version;
        unsigned int status_code;
        response_stream >> status_code;
        std::string status_message;
        std::getline(response_stream, status_message);

        if (!response_stream || http_version.substr(0, 5) != "HTTP/") {
            std::cout << "Invalid response\n";
            return 1;
        }

        if (status_code != 200) {
            std::cout << "Response returned with status code " << status_code << "\n";
            return 1;
        }

        // Step 8: Read and print the rest of the response headers
        boost::asio::read_until(socket, response, "\r\n\r\n");
        std::string header;
        while (std::getline(response_stream, header) && header != "\r") {
            std::cout << header << "\n";
        }
        std::cout << "\n";

        // Step 9: Read and print the response body
        boost::asio::read(socket, response, boost::asio::transfer_all());
        std::string body;
        while (std::getline(response_stream, body)) {
            std::cout << body << "\n";
        }

    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << "\n";
    }

    return 0;
}
