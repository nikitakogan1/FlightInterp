//header file for Command interface
#ifndef COMMAND_H_
#define COMMAND_H_

#include "FlightInterp.h"
#include "Expression.h"
#include <vector>
#include <string>
#include <map>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

using namespace std;

struct threadsAndLock;

class ConditionParser;
class ShuntingYarder;
class Expression;
class Command;
class AssignCommand;
class OpenDataServerCommand;
class CreateVarCommand;
class BindCommand;
//Command interface
class Command
{	//various commands need various tools... will be set according to the specific command
	protected:
		vector<string> params;
		unsigned int ind;
		ShuntingYarder* sy;
		map<string, double>* sTable;
		map<string, string>* refs;
		map<string, string>* revRefs;
		ConditionParser* cp;
		vector<Command*> commands;
		bool* ifRun;
		bool* ifCreated;
		threadsAndLock* tAl;
		int* socketId;

	public:
		Command()
		{
			this->ind = 0;
			this->sy = nullptr;
			this->cp = nullptr;
			this->sTable = nullptr;
			this->refs = nullptr;
			this->revRefs = nullptr;
			this->ifRun = nullptr;
			this->ifCreated = nullptr;
			this->tAl = nullptr;
			this->socketId = nullptr;
		}
		virtual double execute() { return 0; };
		virtual void setParams(vector<string> &p) { this->params = p; };
		virtual void setShuntingYarder(ShuntingYarder* s) { this->sy = s; }
		virtual void setInd(unsigned int &i) { this->ind = i; };
		virtual void setTable(map<string, double>* m) { this->sTable = m; }
		virtual void setRefs(map<string, string>* r) { this->refs = r; }
		virtual void setRevRefs(map<string, string>* rR) { this->revRefs = rR; }
		virtual void setCondPar(ConditionParser* c) { this->cp = c; }
		virtual void setCommands(vector<Command*> &v) { this->commands = v; }
		virtual void setIfRun(bool* ir) { this->ifRun = ir; }
		virtual void setIfCreated (bool* ic) { this->ifCreated = ic; }
		virtual void setThreadsAndLock(threadsAndLock* t) { this->tAl = t; }
		virtual void setSockId(int* idArr) { this->socketId = idArr; }
		virtual ~Command(){};
};
//WhileCommand class
class WhileCommand : public Command
{
	public:
		WhileCommand() : Command(){}
		virtual double execute();
		virtual ~WhileCommand();
};
//OpenDataServerCommand class
class OpenDataServerCommand : public Command
{
	public:
		OpenDataServerCommand() : Command(){}
		virtual double execute();
		virtual ~OpenDataServerCommand(){};
};
//ifCommand class
class IfCommand : public Command
{
	public:
		IfCommand() : Command(){}
		virtual double execute();
		virtual ~IfCommand();
};

class RunFromFileCommand : public Command
{
	public:
		RunFromFileCommand() : Command(){}
		virtual double execute();
		virtual ~RunFromFileCommand(){};
};

class ExitCommand : public Command
{
	public:
		ExitCommand() : Command(){}
		virtual double execute();
		virtual ~ExitCommand(){};
};

class PrintCommand : public Command
{
	public:
		PrintCommand() : Command(){}
		virtual double execute();
		virtual ~PrintCommand(){};
};

class ConnectCommand : public Command
{
	public:
		ConnectCommand() : Command(){}
		virtual double execute();
		virtual ~ConnectCommand(){};
};

class AssignCommand : public Command
{
	public:
		AssignCommand() : Command(){}
		virtual double execute();
		virtual ~AssignCommand(){};
};

class VarCommand : public Command
{
	public:
		VarCommand() : Command(){}
		virtual double execute();
		virtual ~VarCommand(){};
};

class BindCommand : public Command
{
	public:
		BindCommand() : Command(){}
		virtual double execute();
		virtual ~BindCommand(){};
};

class SleepCommand : public Command
{
	public:
		SleepCommand() : Command(){}
		virtual double execute();
		virtual ~SleepCommand(){};
};
#endif
