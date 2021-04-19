#include <stdio.h>
#include <unistd.h>

#include <iostream>

int main(int argc, char **argv, char **env)
{
	std::string body;
	char buffer[1000];
	int bytes;
	if ((bytes = read(0, buffer, sizeof buffer)) > 0)
		body = std::string(buffer, bytes);

	std::cout << "Status: 226\r\n"
			  //   << "Content-Type: test/plain\r\n\r\n";
			  << "Content-Type: CGI/MINE\r\n\r\n";

	for (int i = 0; env[i]; ++i)
		std::cout << env[i] << "\n";
	std::cout << "\n"
			  << body
			  << "\n";
	return 0;
}
