// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include <range.hpp>
#include <vector>
#include <string>
#include <iostream>

using std::ext::make_range;
using std::ext::reverse;

int main(int argc, char* argv[])
{
	std::vector<std::string> poem { "Marry", "had", "a", "little", "lamb" };

	for (auto && s : poem)
		std::cout << s << " ";
	std::cout << std::endl;

	for (auto && s : reverse(poem))
		std::cout << s << " ";
	std::cout << std::endl;

	for (auto && s : make_range(poem.begin() + 1, poem.end()))
		std::cout << s << " ";
	std::cout << std::endl;

	for (auto && s : make_range(poem.rbegin(), poem.rend() - 1))
		std::cout << s << " ";
	std::cout << std::endl;

	int args [] {0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	for (auto && a : args)
		std::cout << a << " ";
	std::cout << std::endl;

	for (auto && a : make_range(args + 2, args + 7)) // 2 .. 6, inclusive
		std::cout << a << " ";
	std::cout << std::endl;

	for (auto && a : reverse(args))
		std::cout << a << " ";
	std::cout << std::endl;

	return 0;
}

