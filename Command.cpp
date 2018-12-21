#include "stdafx.h"
#include "Command.h"
using namespace std;
Command::Command()
{
	//ctor
}
void Nope::operator()(class Processor &p, uint16_t bb, uint16_t adress1, uint16_t adress2)
{
	//lolkek no command
}
void SummInt::operator()(class Processor &p, uint16_t bb, uint16_t adress1, uint16_t adress2)
{
	uint32_t temp1;
	uint32_t temp2;
	Word w;
	p.reg.RegB = p.reg.PSW.IP;
	if (bb == 00 || bb == 01)
	{
		p.jmp[12]->operator()(p, 0, adress1);
	}
	else
	{
		p.jmp[12]->operator()(p, 1, adress1);
	}
	w.Integer16[0] = p.Memory[p.reg.PSW.IP];
	w.Integer16[1] = p.Memory[p.reg.PSW.IP + 1];
	temp1 = w.Integer;
	if (bb == 00 || bb == 10)
	{
		p.jmp[12]->operator()(p, 0, adress2);
	}
	else
	{
		p.jmp[12]->operator()(p, 1, adress2);
	}
	w.Integer16[0] = p.Memory[p.reg.PSW.IP];
	w.Integer16[1] = p.Memory[p.reg.PSW.IP + 1];
	temp2 = w.Integer;
	temp1 = temp1 + temp2;
	if (bb == 00 || bb == 01)
	{
		p.jmp[12]->operator()(p, 0, adress1);
	}
	else
	{
		p.jmp[12]->operator()(p, 1, adress1);
	}
	w.Integer = temp1;
	p.Memory[p.reg.PSW.IP] = w.Integer16[0];
	p.Memory[p.reg.PSW.IP + 1] = w.Integer16[1];
}
void SubInt::operator()(class Processor &p, uint16_t bb, uint16_t adress1, uint16_t adress2)
{
	uint32_t temp1;
	uint32_t temp2;
	Word w;
	p.reg.RegB = p.reg.PSW.IP;
	if (bb == 00 || bb == 01)
	{
		p.jmp[12]->operator()(p, 0, adress1);
	}
	else
	{
		p.jmp[12]->operator()(p, 1, adress1);
	}
	w.Integer16[0] = p.Memory[p.reg.PSW.IP];
	w.Integer16[1] = p.Memory[p.reg.PSW.IP + 1];
	temp1 = w.Integer;
	if (bb == 00 || bb == 10)
	{
		p.jmp[12]->operator()(p, 0, adress2);
	}
	else
	{
		p.jmp[12]->operator()(p, 1, adress2);
	}
	w.Integer16[0] = p.Memory[p.reg.PSW.IP];
	w.Integer16[1] = p.Memory[p.reg.PSW.IP + 1];
	temp2 = w.Integer;
	temp1 = temp1 - temp2;
	if (bb == 00 || bb == 01)
	{
		p.jmp[12]->operator()(p, 0, adress1);
	}
	else
	{
		p.jmp[12]->operator()(p, 1, adress1);
	}
	w.Integer = temp1;
	p.Memory[p.reg.PSW.IP] = w.Integer16[0];
	p.Memory[p.reg.PSW.IP + 1] = w.Integer16[1];
}
void MultInt::operator()(class Processor &p, uint16_t bb, uint16_t adress1, uint16_t adress2)
{
	uint32_t temp1;
	uint32_t temp2;
	Word w;
	p.reg.RegB = p.reg.PSW.IP;
	if (bb == 00 || bb == 01)
	{
		p.jmp[12]->operator()(p, 0, adress1);
	}
	else
	{
		p.jmp[12]->operator()(p, 1, adress1);
	}
	w.Integer16[0] = p.Memory[p.reg.PSW.IP];
	w.Integer16[1] = p.Memory[p.reg.PSW.IP + 1];
	temp1 = w.Integer;
	if (bb == 00 || bb == 10)
	{
		p.jmp[12]->operator()(p, 0, adress2);
	}
	else
	{
		p.jmp[12]->operator()(p, 1, adress2);
	}
	w.Integer16[0] = p.Memory[p.reg.PSW.IP];
	w.Integer16[1] = p.Memory[p.reg.PSW.IP + 1];
	temp2 = w.Integer;
	temp1 = temp1 * temp2;
	if (bb == 00 || bb == 01)
	{
		p.jmp[12]->operator()(p, 0, adress1);
	}
	else
	{
		p.jmp[12]->operator()(p, 1, adress1);
	}
	w.Integer = temp1;
	p.Memory[p.reg.PSW.IP] = w.Integer16[0];
	p.Memory[p.reg.PSW.IP + 1] = w.Integer16[1];
}
void SummFloat::operator()(class Processor &p, uint16_t bb, uint16_t adress1, uint16_t adress2)
{
	uint32_t temp1;
	uint32_t temp2;
	Word w;
	p.reg.RegB = p.reg.PSW.IP;
	if (bb == 00 || bb == 01)
	{
		p.jmp[12]->operator()(p, 0, adress1);
	}
	else
	{
		p.jmp[12]->operator()(p, 1, adress1);
	}
	w.Integer16[0] = p.Memory[p.reg.PSW.IP];
	w.Integer16[1] = p.Memory[p.reg.PSW.IP + 1];
	temp1 = w.Integer;
	if (bb == 00 || bb == 10)
	{
		p.jmp[12]->operator()(p, 0, adress2);
	}
	else
	{
		p.jmp[12]->operator()(p, 1, adress2);
	}
	w.Integer16[0] = p.Memory[p.reg.PSW.IP];
	w.Integer16[1] = p.Memory[p.reg.PSW.IP + 1];
	temp2 = w.Integer;
	temp1 = temp1 + temp2;
	if (bb == 00 || bb == 01)
	{
		p.jmp[12]->operator()(p, 0, adress1);
	}
	else
	{
		p.jmp[12]->operator()(p, 1, adress1);
	}
	w.Integer = temp1;
	p.Memory[p.reg.PSW.IP] = w.Integer16[0];
	p.Memory[p.reg.PSW.IP + 1] = w.Integer16[1];
}
void SubFloat::operator()(class Processor &p, uint16_t bb, uint16_t adress1, uint16_t adress2)
{
	uint32_t temp1;
	uint32_t temp2;
	Word w;
	p.reg.RegB = p.reg.PSW.IP;
	if (bb == 00 || bb == 01)
	{
		p.jmp[12]->operator()(p, 0, adress1);
	}
	else
	{
		p.jmp[12]->operator()(p, 1, adress1);
	}
	w.Integer16[0] = p.Memory[p.reg.PSW.IP];
	w.Integer16[1] = p.Memory[p.reg.PSW.IP + 1];
	temp1 = w.Integer;
	if (bb == 00 || bb == 10)
	{
		p.jmp[12]->operator()(p, 0, adress2);
	}
	else
	{
		p.jmp[12]->operator()(p, 1, adress2);
	}
	w.Integer16[0] = p.Memory[p.reg.PSW.IP];
	w.Integer16[1] = p.Memory[p.reg.PSW.IP + 1];
	temp2 = w.Integer;
	temp1 = temp1 - temp2;
	if (bb == 00 || bb == 01)
	{
		p.jmp[12]->operator()(p, 0, adress1);
	}
	else
	{
		p.jmp[12]->operator()(p, 1, adress1);
	}
	w.Integer = temp1;
	p.Memory[p.reg.PSW.IP] = w.Integer16[0];
	p.Memory[p.reg.PSW.IP + 1] = w.Integer16[1];
}
void MultFloat::operator()(class Processor &p, uint16_t bb, uint16_t adress1, uint16_t adress2)
{
	uint32_t temp1;
	uint32_t temp2;
	Word w;
	p.reg.RegB = p.reg.PSW.IP;
	if (bb == 00 || bb == 01)
	{
		p.jmp[12]->operator()(p, 0, adress1);
	}
	else
	{
		p.jmp[12]->operator()(p, 1, adress1);
	}
	w.Integer16[0] = p.Memory[p.reg.PSW.IP];
	w.Integer16[1] = p.Memory[p.reg.PSW.IP + 1];
	temp1 = w.Integer;
	if (bb == 00 || bb == 10)
	{
		p.jmp[12]->operator()(p, 0, adress2);
	}
	else
	{
		p.jmp[12]->operator()(p, 1, adress2);
	}
	w.Integer16[0] = p.Memory[p.reg.PSW.IP];
	w.Integer16[1] = p.Memory[p.reg.PSW.IP + 1];
	temp2 = w.Integer;
	temp1 = temp1 * temp2;
	if (bb == 00 || bb == 01)
	{
		p.jmp[12]->operator()(p, 0, adress1);
	}
	else
	{
		p.jmp[12]->operator()(p, 1, adress1);
	}
	w.Integer = temp1;
	p.Memory[p.reg.PSW.IP] = w.Integer16[0];
	p.Memory[p.reg.PSW.IP + 1] = w.Integer16[1];
}
void DivInt::operator()(class Processor &p, uint16_t bb, uint16_t adress1, uint16_t adress2)
{
	uint32_t temp1;
	uint32_t temp2;
	Word w;
	p.reg.RegB = p.reg.PSW.IP;
	if (bb == 00 || bb == 01)
	{
		p.jmp[12]->operator()(p, 0, adress1);
	}
	else
	{
		p.jmp[12]->operator()(p, 1, adress1);
	}
	w.Integer16[0] = p.Memory[p.reg.PSW.IP];
	w.Integer16[1] = p.Memory[p.reg.PSW.IP + 1];
	temp1 = w.Integer;
	if (bb == 00 || bb == 10)
	{
		p.jmp[3]->operator()(p, 0, adress2);
	}
	else
	{
		p.jmp[3]->operator()(p, 1, adress2);
	}
	w.Integer16[0] = p.Memory[p.reg.PSW.IP];
	w.Integer16[1] = p.Memory[p.reg.PSW.IP + 1];
	temp2 = w.Integer;
	if (temp2 == 0)
	{
		cerr << "ERR";
	}
	else
	{
		temp1 = temp1 / temp2;
		if (bb == 00 || bb == 01)
		{
			p.jmp[12]->operator()(p, 0, adress1);
		}
		else
		{
			p.jmp[12]->operator()(p, 1, adress1);
		}
		w.Integer = temp1;
		p.Memory[p.reg.PSW.IP] = w.Integer16[0];
		p.Memory[p.reg.PSW.IP + 1] = w.Integer16[1];
	}
}
void DivFloat::operator()(class Processor &p, uint16_t bb, uint16_t adress1, uint16_t adress2)
{
	uint32_t temp1;
	uint32_t temp2;
	Word w;
	p.reg.RegB = p.reg.PSW.IP;
	if (bb == 00 || bb == 01)
	{
		p.jmp[12]->operator()(p, 0, adress1);
	}
	else
	{
		p.jmp[12]->operator()(p, 1, adress1);
	}
	w.Integer16[0] = p.Memory[p.reg.PSW.IP];
	w.Integer16[1] = p.Memory[p.reg.PSW.IP + 1];
	temp1 = w.Integer;
	if (bb == 00 || bb == 10)
	{
		p.jmp[12]->operator()(p, 0, adress2);
	}
	else
	{
		p.jmp[12]->operator()(p, 1, adress2);
	}
	w.Integer16[0] = p.Memory[p.reg.PSW.IP];
	w.Integer16[1] = p.Memory[p.reg.PSW.IP + 1];
	temp2 = w.Integer;
	if (temp2 == 0)
	{
		cerr << "ERR";
	}
	else
	{
		temp1 = temp1 / temp2;
		if (bb == 00 || bb == 01)
		{
			p.jmp[12]->operator()(p, 0, adress1);
		}
		else
		{
			p.jmp[12]->operator()(p, 1, adress1);
		}
		w.Integer = temp1;
		p.Memory[p.reg.PSW.IP] = w.Integer16[0];
		p.Memory[p.reg.PSW.IP + 1] = w.Integer16[1];
	}
}
void STOP::operator()(class Processor &p, uint16_t bb, uint16_t adress1, uint16_t adress2)
{

}
