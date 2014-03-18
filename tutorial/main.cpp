#ifdef SFML_STATIC
#pragma comment(lib, "glew.lib")
#pragma comment(lib, "freetype.lib")
#pragma comment(lib, "jpeg.lib")
#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "winmm.lib")
#pragma comment(lib, "gdi32.lib")  
#endif // SFML_STATIC



////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <iostream>
#include <cstdlib>







void runTcpServer(unsigned short port);
void runTcpClient(unsigned short port);


////////////////////////////////////////////////////////////
/// Entry point of application
///
/// \return Application exit code
///
////////////////////////////////////////////////////////////
int main()
{
	// Choose an arbitrary port for opening sockets
	const unsigned short port = 50001;

	// TCP
	char protocol;

	// Client or server ?
	char who;
	std::cout << "Do you want to be a server (s) or a client (c) ? ";
	std::cin >> who;

	// Test the TCP protocol
	if (who == 's')
		runTcpServer(port);
	else
		runTcpClient(port);

	
	// Wait until the user presses 'enter' key
	std::cout << "Press enter to exit..." << std::endl;
	std::cin.ignore(10000, '\n');
	std::cin.ignore(10000, '\n');

	sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(shape);
		window.display();
	}


	return EXIT_SUCCESS;
}
