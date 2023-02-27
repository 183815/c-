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
	//◊¥Ã¨:0->ΩË≥ˆ;1->‘⁄π›(ƒ¨»œ);2->“≈ ß
	int status=1;
	string status_out;
	double price;
};
