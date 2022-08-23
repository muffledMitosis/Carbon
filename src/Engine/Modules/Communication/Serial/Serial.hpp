#pragma once
#include "../../../Core.h"
#include <string>

namespace Carbon {

struct SerialInfo 
{
  int Baud;
  std::string port;
};

class C_API Serial
{
private:
  int port_nix;
public:
  SerialInfo info;
  Serial(const SerialInfo& info);
  void readBytes();
  ~Serial();
};

}
