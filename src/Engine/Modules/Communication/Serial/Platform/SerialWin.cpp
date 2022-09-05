#ifdef PLATFORM_WINDOWS

#include "../Serial.hpp"

namespace Carbon::Module {
	Serial::Serial(const SerialInfo& info)
	{

	}

	void Serial::readLine(){}
	void Serial::writeTestArduino() {}
	void Serial::writeInt(int val) {};
}

#endif // PLATFORM_WINDOWS
