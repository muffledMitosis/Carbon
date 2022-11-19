#pragma once
#include "../../../Core.h"
#include <filesystem>
#include <string>
#include <iostream>
#include <glad/glad.h>

namespace fs = std::filesystem;

namespace Graphics
{

struct C_API ShaderInfo
{
	std::filesystem::path sourcePath;
	std::string source;
	unsigned int id;
};

using ShaderProgram = unsigned int;

void compileShader(Graphics::ShaderInfo& shaderInfo);

class C_API Shader
{
private:
	Graphics::ShaderProgram program;
	Graphics::ShaderInfo vertex, fragment;
	void initializeShaderInfo(std::filesystem::path vertexFile,
														std::filesystem::path fragmentFile);

public:
	Shader(std::filesystem::path vertexFile, std::filesystem::path fragmentFile);
	static void checkShaderCompilation(unsigned int shaderID, std::string type)
	{
		int success;
		char infoLog[512];
		glGetShaderiv(shaderID, GL_COMPILE_STATUS, &success);
		if(!success)
		{
			glGetShaderInfoLog(shaderID, 512, NULL, infoLog);
			std::cout << "SHADER comp failed " << infoLog << "\n"
								<< type << std::endl;
		}
	}
	Graphics::ShaderProgram getProgram();
	~Shader();

private:
};
}	 // namespace Graphics
