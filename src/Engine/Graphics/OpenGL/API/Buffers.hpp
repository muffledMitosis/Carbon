#pragma once

#include "../../../Core.h"

#include <cstdint>
#include <vector>
#include <filesystem>
#include <unordered_map>

namespace Graphics
{

class C_API VBO
{
public:
	unsigned int id;
	VBO();
	void BufferData(std::vector<double>& data, int streamType);
	void Bind();
};

class C_API VAO
{
public:
	unsigned int id;
	VAO();
	void Bind();
	void spec(const int& index,
						const int& size,
						const int& dataType,
						const int& stride,
						const int& offset);
};

class C_API EBO
{
public:
	unsigned int id;
	EBO();
	void Bind();
	void BufferData(std::vector<unsigned int>& data, int streamType);
};

struct C_API ImageInfo
{
	int width, height, channelNum;
	unsigned char* image_data;
};

struct C_API TextureInfo
{
	int location;
	unsigned long long unit;
};

std::unordered_map<std::string, Graphics::TextureInfo> TexturePool;

class C_API Texture
{
private:
	unsigned int id;
	Graphics::ImageInfo imageInfo;

public:
	// Texture(std::filesystem::path texturePath, std::string varName);
	Texture(std::string textureName);
	void Bind();
	~Texture();
};

}	 // namespace Graphics
