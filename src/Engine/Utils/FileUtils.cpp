#include "FileUtils.hpp"
#include <string>
#include <filesystem>
#include <fstream>
#include <iostream>

namespace fs = std::filesystem;

namespace Utils
{
// TODO: Implement file accessibity check
bool isAccessible(fs::path path)
{
	return false;
}

std::string readFile(fs::path path)
{
	std::ifstream ifs;
	std::string fileContents = "";
	std::string temp				 = "";

	if(fs::exists(path) && fs::is_regular_file(path))
	{
		ifs.open(path, std::ios::in);
		if(ifs)
		{
			while(!ifs.eof())
			{
				std::getline(ifs, temp);
				fileContents += temp + "\n";
			}
		}
		ifs.close();
		return fileContents;
	}
	else
	{
		return "not a regular file";
	}
}
}	 // namespace Utils
