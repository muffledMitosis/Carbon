#pragma once
#include "../Core.h"
#include <string>
#include <filesystem>

namespace fs = std::filesystem;

namespace Utils
{
std::string C_API readFile(fs::path path);
bool C_API isAccessible(fs::path path);
}	 // namespace Utils
