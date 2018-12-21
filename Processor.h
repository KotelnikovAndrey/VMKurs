#pragma once
#include <stdint.h>
#include <string>
#include <iostream>
#include <vector>
#include <cinttypes>
#include "Command.h"
#include "Structures.h"
#include "Jump.h"

using namespace std;

class Processor
{
	/*word w;
	w.Integer = tvoya_pamyat;
	int cop = w.Command1.OperationCode;*/
public:
	Processor();
	vector <uint16_t> Memory;
	Register reg;
	class Jump* jmp[256];
	class Command* cmd[256];
};

