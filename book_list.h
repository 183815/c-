#pragma once
#include "book.h"

class book_list
{
public:
    book_list();
    ~book_list();
	list<book> bk_ls;
	//将查询结果和指针封装为pair并返回
	pair<int, list<book>::iterator> search(string bk_name,string bk_id);
	void book_show();
	void book_search();
	void book_add();
	void book_alter();
	void book_borrow();
	void book_return();
	void book_lost_find();
//本地化操作
	void add_book(book bk);
	void alter_book();
	void alter_status(list<book>::iterator bk_it,int status);
	void book_read();
};
