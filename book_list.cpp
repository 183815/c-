#include "book_list.h"
istream& operator>>(istream& cin, book& bk)
{
	cout << "�������鼮����:";
	cin >> bk.name;
	cout << "�������鼮���:";
	cin >> bk.id;
	bk.status = 1;
	return cin;
}

ostream& operator<<(ostream& cout,list<book>::iterator bk_search)
{
	bk_search->set_status();
	cout << "\n������" << bk_search->name << "\n��ţ�" << bk_search->id << "\n״̬��" << bk_search->status_out << endl;
	return cout;
}

ostream& operator<<(ostream& cout,book bk)
{
	bk.set_status();
	cout << "\n����:" << bk.name << "\n���" << bk.id << "\n״̬:" << bk.status_out << endl;
	return cout;
}

pair<int, list<book>::iterator> book_list::search(string bk_name="###",string bk_id="###")//###��ʾ�����ֵ
{
	list<book>::iterator bk_search = bk_ls.begin();
	pair<int, list<book>::iterator> result;
	if(bk_ls.size()!=0)
	{
		while (bk_search != bk_ls.end())
		{
			if (bk_search->name == bk_name || bk_search->id == bk_id)
			{
                return result = make_pair(1, bk_search);//�ҵ�
			}
			bk_search++;
		}
        return result = make_pair(0, bk_search);//δ�ҵ�
	}
	else
    {
    return result = make_pair(-1, bk_search);//���
    }
}

void book_list::book_search()
{
	string bk_name;
	cout << "���������ѯ�鼮����:";
	cin >> bk_name;
	pair<int,list<book>::iterator> result = search(bk_name,"###");
	if (result.first==1) cout << result.second << endl;
	else if (result.first==0) cout<<"δ�ҵ�"<<endl;
	else if (result.first==-1) cout<<"���Ϊ��"<<endl;
}

void book_list::book_add()
{
    book bk;
    cin>>bk;
	pair<int, list<book>::iterator> result = search(bk.name,"###");
	if (result.first ==0||result.first==-1)
	{
		bk_ls.push_front(bk);
		cout << bk << "��ӳɹ�!" << endl;
	}
	else if(result.first ==1)
	{
		cout << bk.name<<"("<<bk.id<<")" << "���ڹ�!" << endl;
	}
}

void book_list::book_save()
{
    string file_name="book.dat";

}

void book_list::book_borrow()
{
	string id;
	cout << "������ͼ����:";
	cin >> id;
	pair<int, list<book>::iterator> result = search("###", id);
	if (result.first==1)
	{
		if (result.second->status == 1)
		{
			char choice;
			cout << "\n�Ƿ����:" << result.second<< endl;
			cout << "(1.��    " << "2.��)" << endl;
			cin >> choice;
			if (choice == '1')
			{
				result.second->status=0;
				result.second->set_status();
				cout << "���ĳɹ�" << endl;
			}
		}
		else if(result.second->status == 0)
		{
			cout << "���ڹ�,�޷�����!" << endl;
		}
	}
	else
	{
		cout << "��ͼ�鲻�ڹ���" << endl;
	}
}

void book_list::book_return()
{
	string id;
	cout << "������黹ͼ���:";
	cin >> id;
	pair<int, list<book>::iterator> result = search("###", id);
	if (result.first == 0)
	{
		cout <<result.second->name<< "�黹�ɹ�!" << endl;
		result.second->status = 1;
		result.second->set_status();
	}
	else
	{
		cout <<result.second->name<< "�黹ʧ��!" << endl;
	}
}

void book_list::book_lost()
{
	string id;
	cout << "��������ʧͼ����:" << endl;
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
			cout << "��ͼ���ѱ���!" << endl;
		}
	}
	else
	{
		cout << "δ�ҵ���ͼ��!����ϵͼ�����Ա���б���!" << endl;
	}
}
