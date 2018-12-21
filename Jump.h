#pragma once

#include <stdint.h>
#include <string>
#include <iostream>
#include "Processor.h"

class Jump
{
public:
	Jump();
	virtual void operator () (class Processor &p, uint16_t bb, uint16_t adress) = 0;
};
class GoToAdress : public Jump
{
public:
	virtual void operator () (class Processor &p, uint16_t bb, uint16_t adress);
};
class GoToRegisterBack : public Jump
{
public:
	virtual void operator () (class Processor &p, uint16_t bb, uint16_t adress);
};
class GoToRegisterMov : public Jump
{
public:
	virtual void operator () (class Processor &p, uint16_t bb, uint16_t adress);
};
class DisplayInt : public Jump
{
public:
	virtual void operator () (class Processor &p, uint16_t bb, uint16_t adress);
};
class DisplayFloat : public Jump
{
public:
	virtual void operator () (class Processor &p, uint16_t bb, uint16_t adress);
};
class JMP : public Jump
{
public:
	virtual void operator () (class Processor &p, uint16_t bb, uint16_t adress);
};
