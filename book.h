#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
#include <list>
#include <utility>
using namespace std;
class book
{
public:
	book();
	~book();
	void set_status();
	string name;
	string id ;
	//״̬:0->���;1->�ڹ�(Ĭ��);2->��ʧ
	int status=1;
	string status_out;
	double price;
};
