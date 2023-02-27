#include "book_list.h"
istream& operator>>(istream& cin, book& bk)
{
	cout << "请输入书籍名称:";
	cin >> bk.name;
	cout << "请输入书籍编号:";
	cin >> bk.id;
	bk.status = 1;
	return cin;
}

ostream& operator<<(ostream& cout,list<book>::iterator bk_search)
{
	bk_search->set_status();
	cout << "\n书名：" << bk_search->name << "\n编号：" << bk_search->id << "\n状态：" << bk_search->status_out << endl;
	return cout;
}

ostream& operator<<(ostream& cout,book bk)
{
	bk.set_status();
	cout << "\n书名:" << bk.name << "\n编号" << bk.id << "\n状态:" << bk.status_out << endl;
	return cout;
}

pair<int, list<book>::iterator> book_list::search(string bk_name="###",string bk_id="###")//###表示传入空值
{
	list<book>::iterator bk_search = bk_ls.begin();
	pair<int, list<book>::iterator> result;
	if(bk_ls.size()!=0)
	{
		while (bk_search != bk_ls.end())
		{
			if (bk_search->name == bk_name || bk_search->id == bk_id)
			{
                return result = make_pair(1, bk_search);//找到
			}
			bk_search++;
		}
        return result = make_pair(0, bk_search);//未找到
	}
	else
    {
    return result = make_pair(-1, bk_search);//库空
    }
}

void book_list::book_search()
{
	string bk_name;
	cout << "请输入待查询书籍名称:";
	cin >> bk_name;
	pair<int,list<book>::iterator> result = search(bk_name,"###");
	if (result.first==1) cout << result.second << endl;
	else if (result.first==0) cout<<"未找到"<<endl;
	else if (result.first==-1) cout<<"书库为空"<<endl;
}

void book_list::book_add()
{
    book bk;
    cin>>bk;
	pair<int, list<book>::iterator> result = search(bk.name,"###");
	if (result.first ==0||result.first==-1)
	{
		bk_ls.push_front(bk);
		cout << bk << "添加成功!" << endl;
	}
	else if(result.first ==1)
	{
		cout << bk.name<<"("<<bk.id<<")" << "已在馆!" << endl;
	}
}

void book_list::book_save()
{
    string file_name="book.dat";

}

void book_list::book_borrow()
{
	string id;
	cout << "请输入图书编号:";
	cin >> id;
	pair<int, list<book>::iterator> result = search("###", id);
	if (result.first==1)
	{
		if (result.second->status == 1)
		{
			char choice;
			cout << "\n是否借阅:" << result.second<< endl;
			cout << "(1.是    " << "2.否)" << endl;
			cin >> choice;
			if (choice == '1')
			{
				result.second->status=0;
				result.second->set_status();
				cout << "借阅成功" << endl;
			}
		}
		else if(result.second->status == 0)
		{
			cout << "不在馆,无法借阅!" << endl;
		}
	}
	else
	{
		cout << "此图书不在馆内" << endl;
	}
}

void book_list::book_return()
{
	string id;
	cout << "请输入归还图书号:";
	cin >> id;
	pair<int, list<book>::iterator> result = search("###", id);
	if (result.first == 0)
	{
		cout <<result.second->name<< "归还成功!" << endl;
		result.second->status = 1;
		result.second->set_status();
	}
	else
	{
		cout <<result.second->name<< "归还失败!" << endl;
	}
}

void book_list::book_lost()
{
	string id;
	cout << "请输入遗失图书编号:" << endl;
	cin >> id;
	pair<int, list<book>::iterator> result = search(NULL, id);
	if (result.first == 2)
	{
		if (result.second->status != 2)
		{
			result.second->status = 2;
			result.second->set_status();
		}
		else
		{
			cout << "该图书已报备!" << endl;
		}
	}
	else
	{
		cout << "未找到该图书!请联系图书管理员进行报备!" << endl;
	}
}
