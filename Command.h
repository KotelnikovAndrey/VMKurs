#pragma once

#include <stdint.h>
#include <string>
#include <iostream>
#include "Processor.h"

class Command
{
public:
	Command();
	virtual void operator () (class Processor &p, uint16_t bb, uint16_t adress1, uint16_t adress2) = 0;
};
class Nope : public Command
{
public:
	virtual void operator () (class Processor &p, uint16_t bb = 0, uint16_t adress1 = 0, uint16_t adress2 = 0);
};
class SummInt : public Command
{
public:
	virtual void operator () (class Processor &p, uint16_t bb, uint16_t adress1, uint16_t adress2);
};
class SubInt : public Command
{
public:
	virtual void operator () (class Processor &p, uint16_t bb, uint16_t adress1, uint16_t adress2);
};
class MultInt : public Command
{
public:
	virtual void operator () (class Processor &p, uint16_t bb, uint16_t adress1, uint16_t adress2);
};
class SummFloat : public Command
{
public:
	virtual void operator () (class Processor &p, uint16_t bb, uint16_t adress1, uint16_t adress2);
};
class SubFloat : public Command
{
public:
	virtual void operator () (class Processor &p, uint16_t bb, uint16_t adress1, uint16_t adress2);
};
class MultFloat : public Command
{
public:
	virtual void operator () (class Processor &p, uint16_t bb, uint16_t adress1, uint16_t adress2);
};
class DivInt : public Command
{
public:
	virtual void operator () (class Processor &p, uint16_t bb, uint16_t adress1, uint16_t adress2);
};
class DivFloat : public Command
{
public:
	virtual void operator () (class Processor &p, uint16_t bb, uint16_t adress1, uint16_t adress2);
};
class STOP : public Command
{
public:
	virtual void operator () (class Processor &p, uint16_t bb, uint16_t adress1, uint16_t adress2 = 0);
};