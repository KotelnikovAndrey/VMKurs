#include "stdafx.h"
#include "Jump.h"
using namespace std;
Jump::Jump()
{
	//ctor
}
void GoToAdress::operator()(class Processor &p, uint16_t bb, uint16_t adress)
{
	if (bb == 0)
	{
		p.reg.PSW.IP = adress;
	}
	if (bb == 1)
	{
		p.reg.PSW.IP = adress + p.reg.RegM;
	}
}
void GoToRegisterBack::operator()(class Processor &p, uint16_t bb, uint16_t adress)
{
	p.reg.PSW.IP = p.reg.RegB;
}
void GoToRegisterMov::operator()(class Processor &p, uint16_t bb, uint16_t adress)
{
	p.reg.PSW.IP = p.reg.RegM;
}
void DisplayInt::operator()(class Processor &p, uint16_t bb, uint16_t adress)
{
	Word w;
	int I;
	w.Integer16[0] = p.Memory[adress];
	w.Integer16[1] = p.Memory[adress + 1];
	I = w.Integer;
	cout << I;
	p.reg.PSW.IP = p.reg.PSW.IP + 1;
}
void DisplayFloat::operator()(class Processor &p, uint16_t bb, uint16_t adress)
{
	Word w;
	float F;
	w.Integer16[0] = p.Memory[adress];
	w.Integer16[1] = p.Memory[adress + 1];
	F = w.Integer;
	cout << F;
	p.reg.PSW.IP = p.reg.PSW.IP + 1;
}
void JMP::operator()(class Processor &p, uint16_t bb, uint16_t adress)
{
	if (bb == 00)
	{
		p.reg.PSW.IP = p.reg.PSW.IP + adress;
	}
	if (bb == 01)
	{
		p.reg.PSW.IP = p.reg.RegM + adress;
	}
	if (bb == 10)
	{
		p.reg.PSW.IP = p.reg.RegB + adress;
	}
}