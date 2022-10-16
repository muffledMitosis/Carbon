#pragma once
#include "../../../Core.h"
#include <string>

namespace Carbon::Module
{

struct SerialInfo
{
	int Baud;
	std::string port;
};

template<typename T, std::size_t len>
struct FixedBuff
{
	T data[len];
	std::size_t size = sizeof(this->data);
};

class C_API Serial
{
private:
	int port_nix;
	FixedBuff<char, 4096> read_buff;

public:
	SerialInfo info;
	Serial(const SerialInfo& info);
	void readLine();
	void writeTestArduino();
	void writeInt(int val);
	~Serial();
};

}	 // namespace Carbon::Module
