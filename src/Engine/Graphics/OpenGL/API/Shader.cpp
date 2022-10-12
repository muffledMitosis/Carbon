#include "Shader.hpp"
#include <iostream>
#include "../../../Utils/FileUtils.hpp"
#include <glad/glad.h>

namespace Graphics
{

void compileShader(Graphics::ShaderInfo& shaderInfo)
{
	const char* src = shaderInfo.source.c_str();
	glShaderSource(shaderInfo.id, 1, &src, NULL);
	glCompileShader(shaderInfo.id);
}

Shader::Shader(std::filesystem::path vertexFile,
							 std::filesystem::path fragmentFile)
{
	initializeShaderInfo(vertexFile, fragmentFile);
	Graphics::compileShader(this->vertex);
	Graphics::compileShader(this->fragment);

	Shader::checkShaderCompilation(this->vertex.id, "VERTEX");
	Shader::checkShaderCompilation(this->fragment.id, "FRAGMENT");

	this->program = glCreateProgram();
	glAttachShader(this->program, this->vertex.id);
	glAttachShader(this->program, this->fragment.id);
	glLinkProgram(this->program);
	glUseProgram(this->program);

	// this->getUniformLocations();
}

void Shader::initializeShaderInfo(std::filesystem::path vertexFile,
																	std::filesystem::path fragmentFile)
{
	this->vertex.id = glCreateShader(GL_VERTEX_SHADER);
	this->fragment.id = glCreateShader(GL_FRAGMENT_SHADER);
	this->vertex.sourcePath = vertexFile;
	this->fragment.sourcePath = fragmentFile;
	this->vertex.source = Utils::readFile(this->vertex.sourcePath.string());
	this->fragment.source = Utils::readFile(this->fragment.sourcePath.string());
}

Shader::~Shader() {}
}		// namespace Graphics
