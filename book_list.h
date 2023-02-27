#pragma once
#include "book.h"

class book_list
{
public:
	list<book> bk_ls;
	//����ѯ�����ָ���װΪpair������
	pair<int, list<book>::iterator> search(string bk_name,string bk_id);
	void book_search();
	void book_add();
	void book_borrow();
	void book_return();
	void book_lost();
	void book_save();
	//void book_read();
};
