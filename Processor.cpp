#include "stdafx.h"
#include "Processor.h"


using namespace std;

Processor::Processor()
{
	uint32_t TEMPZERO = 0;
	for (uint16_t i = 0; i < 4096; i++)
	{
		Memory.push_back(TEMPZERO);
	}
	cmd[0] = new STOP();
	cmd[1] = new SummInt();
	cmd[2] = new SubInt();
	cmd[3] = new MultInt();
	cmd[4] = new DivInt();
	cmd[5] = new SummFloat();
	cmd[6] = new SubFloat();
	cmd[7] = new MultFloat();
	cmd[8] = new DivFloat();
	jmp[9] = new GoToAdress();
	jmp[10] = new GoToRegisterBack();
	jmp[11] = new GoToRegisterMov();
	jmp[12] = new JMP();
	jmp[13] = new DisplayInt();
	jmp[14] = new DisplayFloat();
}
