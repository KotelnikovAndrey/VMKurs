#pragma once
#include <stdint.h>

#pragma  pack (push, 1)
struct CommandStructure
{
	uint8_t OperationCode : 6;
	uint8_t bb : 2;
	uint16_t adress1 : 12;
	uint16_t adress2 : 12;
};
#pragma pack(pop)

#pragma  pack (push, 1)
struct JumpStructure
{
	uint8_t OperationCode : 6;
	uint8_t bb : 2;
	uint16_t adress : 8;
};
#pragma pack(pop)
struct bitPSW
{
	uint16_t IP : 12;
	uint8_t ZF : 1;//нуля
	uint8_t SF : 1;//знака
};
struct Register
{
	bitPSW PSW;
	uint16_t RegM : 12;
	uint16_t RegB : 12;

};
union Word
{
	uint32_t Integer;
	uint16_t Integer16[2];
	CommandStructure Command;
	JumpStructure Jump;
};