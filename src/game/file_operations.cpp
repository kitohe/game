#include <fstream>
#include <iostream>

#include "file_operations.h"


std::string file_operations::read_file(const std::string& filename)
{	
	if (filename.empty())
	{
		std::cout << "File: " << filename << "doesn't exists." << std::endl;
		return ""; 
	}

	std::ifstream file_stream(filename, std::ios::in);
	
	if (!file_stream.is_open())
	{
		std::cout << "Couldn't open file: " << filename << std::endl;
		return "";
	}

	std::string current_line;
	std::string content;
	
	while (std::getline(file_stream, current_line))
	{
		content += current_line.append("\n");
	}

	return content;
}
