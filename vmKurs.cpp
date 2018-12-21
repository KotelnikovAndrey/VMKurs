#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <string>
#include "Processor.h"
#include "Command.h"
#include "Jump.h"

using namespace std;

void DO(Processor &p)
{
	Word w;
	uint16_t temp16 = 1;
	while (temp16 != 0)
	{
		w.Integer16[0] = p.Memory[p.reg.PSW.IP];
		temp16 = w.Jump.OperationCode;
		if (temp16 > 8)
		{
			p.jmp[temp16]->operator()(p, w.Jump.bb, w.Jump.adress);
		}
		else
		{
			uint16_t a1 = w.Command.adress1;
			uint16_t a2 = w.Command.adress2;
			w.Integer16[1] = p.Memory[p.reg.PSW.IP + 1];
			p.cmd[temp16]->operator()(p, w.Command.bb, w.Command.adress1, w.Command.adress2);
			cout << w.Command.OperationCode;
			cout << w.Command.bb;
			cout << w.Command.adress1;
			cout << w.Command.adress2;
			p.reg.PSW.IP = p.reg.PSW.IP + 2;
		}
	}
}

vector<string> getfile(std::string namefile)
{
	ifstream file;
	file.open(namefile);

	string s;
	vector <string> f;
	if (!file.is_open())
	{
		cerr << "File with name \"" << namefile << "\" not found!";
		return f;
	}
	while (!file.eof())
	{
		getline(file, s);
		f.push_back(s);
	}
		file.close();
	return f;
}
vector<string> Spliting(string s)
{
	vector<string> v;
	std::string NeW = "";
	std::string Space = " ";
	std::string Element;
	for (int i = 0; i < s.size(); i++)
	{
		Element = s[i];
		if (Element != Space)
		{
			NeW.push_back(s[i]);
		}
		else
		{
			v.push_back(NeW);
			NeW = "";
		}
	}
	return v;
}
void uploader(Processor &p, vector<string> fil, uint16_t &END)
{
	uint16_t uploadID = 0;
	uint16_t StartID = 0;
	string tempStr;
	string tempLine;
	string temp32;
	string temp16;
	uint32_t int32;
	uint16_t int16;
		for (int i = 0; i < fil.size(); i++)
		{
			Word W{};
			if (END == 0)
			{
				auto str = Spliting(fil[i]);
				if (str[0] == "i")
				{
					temp32 = str[1];
					int32 = stoi(temp32);
					W.Integer = int32;
					p.Memory[uploadID] = W.Integer16[0];
					uploadID++;
					p.Memory[uploadID] = W.Integer16[1];
					uploadID++;
				}
				if (str[0] == "f")
				{
					temp32 = str[1];
					W.Integer = stoi(temp32);
					p.Memory[uploadID] = W.Integer16[0];
					uploadID++;
					p.Memory[uploadID] = W.Integer16[1];
					uploadID++;
				}
				if (str[0] == "c")
				{
					temp16 = str[1];
					int16 = stoi(temp16);
					W.Command.OperationCode = int16;
					cout << W.Command.OperationCode;
					temp16 = str[2];
					int16 = stoi(temp16);
					W.Command.bb = int16; 
					cout << W.Command.bb;
					temp16 = str[3];
					int16 = stoi(temp16);
					W.Command.adress1 = int16;
					cout << W.Command.adress1;
					temp16 = str[4];
					int16 = stoi(temp16);
					W.Command.adress2 = int16;
					cout << W.Command.adress2;
					p.Memory[uploadID] = W.Integer16[0];
					temp16 = W.Integer16[0];
					uploadID++;
					p.Memory[uploadID] = W.Integer16[1];
					temp16 = W.Integer16[1];
					uploadID++;
				}
				if (str[0] == "j")
				{
					temp16 = str[1];
					int16 = stoi(temp16);
					W.Jump.OperationCode = int16;
					temp16 = str[2];
					int16 = stoi(temp16);
					W.Jump.bb = int16;
					temp16 = str[3];
					int16 = stoi(temp16);
					W.Jump.adress = int16;
					p.Memory[uploadID] = W.Integer16[0];
					uploadID++;
				}
				if (str[0] == "S")
				{
					p.reg.PSW.IP = uploadID;
				}
				if (str[0] == "E")
				{
					END = uploadID;
				}
			}
		}
}

int main()
{
	cout << sizeof(CommandStructure);
	Processor p;
	uint16_t END = 0;
	string namefile;
	cin >> namefile;
	uploader(p, getfile("program.txt"), END);
	if (END != 0)
	{
		DO(p);
	}
	else
	{
		cerr << "End of file \"" << namefile << "\" not found!" << endl;
	}
	system("pause");
	return 0;
}
