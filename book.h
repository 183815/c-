#pragma once
#include "head.h"
using namespace std;
class book
{
public:
	book();
	~book();
	void set_status();
    string id ;
	string name;
    double price=0;
	//0->借出;1->在馆;2->遗失;3->错误
	int status=1;
	string status_out;
};
