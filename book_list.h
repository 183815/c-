#pragma once
#include "book.h"

class book_list
{
public:
	list<book> bk_ls;
	//将查询结果和指针封装为pair并返回
	pair<int, list<book>::iterator> search(string bk_name,string bk_id);
	void book_search();
	void book_add();
	void book_borrow();
	void book_return();
	void book_lost();
	void book_save();
	//void book_read();
};
