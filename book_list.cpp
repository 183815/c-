#include "book_list.h"

book_list::book_list()
{
    book_read();
}

book_list::~book_list()
{

}

istream& operator>>(istream& cin, book& bk)
{
    cout << "请输入书籍编码:";
	cin >> bk.id;
	cout << "请输入书籍名称:";
	cin >> bk.name;
    cout << "请输入书籍价格:";
	cin >> bk.price;
	bk.status = 1;
	return cin;
}

ostream& operator<<(ostream& cout,list<book>::iterator bk_search)
{
	bk_search->set_status();
	cout << "书名：" << bk_search->name << "\n编号：" << bk_search->id << "\n状态：" << bk_search->status_out<< "\n价格：" << bk_search->price << endl;
	return cout;
}

ostream& operator<<(ostream& cout,book bk)
{
	bk.set_status();
	cout << "书名:" << bk.name << "\n编号" << bk.id << "\n状态:" << bk.status_out <<"\n价格:" << bk.price << endl;
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

void book_list::book_show()
{
    list<book>::iterator beg=bk_ls.begin();
    list<book>::iterator ed=bk_ls.end();
    while(beg!=ed)
    {
        cout<<beg++<<endl;
    }
}

//添加图书到链表中
void book_list::book_add()
{
    book bk;
    cin>>bk;
	pair<int, list<book>::iterator> result = search("###",bk.id);
	if (result.first ==0||result.first==-1)
	{
		bk_ls.push_back(bk);
		add_book(bk);
		cout << bk << "添加成功!" << endl;
	}
	else if(result.first ==1)
	{
		cout << bk.name<<"("<<bk.id<<")" << "已在馆!" << endl;
	}
}

void book_list::book_alter()
{
    book bk;
    cout<<"请输入需要修改书名和编号(格式:书名 编号)"<<endl;
    cin>>bk.name>>bk.id;
    pair<int, list<book>::iterator> result = search(bk.name,bk.id);
    if(result.first==1){
        cout<<result.second;
        cout<<"请输入修改的信息(格式：编号 名称 价格):";
        cin>>result.second->id>>result.second->name>>result.second->price;
        alter_book();
    }
    else if(result.first!=1){
        cout<<"未找到！"<<endl;
    }
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
				alter_book();
				cout << "借阅成功" << endl;
			}
		}
		else if(result.second->status == 0)
		{
			cout << "此书已被借阅!" << endl;
		}
	}
	else
	{
		cout << "此图书不存在" << endl;
	}
}

void book_list::book_return()
{
	string id;
	cout << "请输入归还图书号:";
	cin >> id;
	pair<int, list<book>::iterator> result = search("###", id);
	if (result.first ==0 )      //未找到
	{
		cout<<"此书未找到!"<<endl;
	}
	else if(result.first ==1 )      //找到
	{
		if(result.second->status==0)
        {
            cout<<result.second->name<< "归还成功!" << endl;
            alter_status(result.second,1);
        }
        else if(result.second->status==1)
        {
            cout <<result.second->name<< "已归还!请勿重复操作!" << endl;
        }
        else if(result.second->status==2)
        {
            cout<<result.second->name<< "该图书已遗失!若要归还请选择(遗失/找到)选项" << endl;
        }
        else if(result.second->status==3)
        {
            cout<<result.second->name<< "馆内从未收录此书!" << endl;
        }
	}
}

//遗失报备
void book_list::book_lost_find()
{
	string id;
	char choice;
    cout<<"1.遗失     "<<"2.找到    "<<"\n请输入选择:"<<endl;
    cin>>choice;
	if(choice=='1'){
    cout << "请输入图书编号:" << endl;
    cin >> id;
    pair<int, list<book>::iterator> result = search("####", id);
        if (result.first == 1)
        {
            if (result.second->status ==0||result.second->status ==1)
            {
                alter_status(result.second,2);
                cout<<result.second->name<<"报备成功(请联系管理支付图书赔偿金)"<<endl;
            }
            else if (result.second->status == 2)
            {
                cout << "该图书已报备!请勿重复操作!" << endl;
            }
            else if (result.second->status == 3)
            {
                cout << "馆内从未收录此书!" << endl;
            }
        }
        else
        {
            cout << "未找到该图书!请联系图书管理员进行报备!" << endl;
        }
	}
	else if(choice=='2')
    {
        pair<int, list<book>::iterator> result = search("####", id);
        if (result.first == 1)
        {
            if (result.second->status ==0||result.second->status ==1)
            {
                cout<<result.second->name<<"还未报备遗失!请先报备!"<<endl;
            }
            else if (result.second->status == 2)
            {
                alter_status(result.second,1);
                cout << "该图书归还成功!（请联系管理员归还赔偿金）" << endl;
            }
            else if (result.second->status == 3)
            {
                cout << "馆内从未收录此书!" << endl;
            }
        }
        else
        {
            cout << "未找到该图书!请联系图书管理员进行报备!" << endl;
        }
    }
    else
    {
        cout<<"选择错误，请重新输入!"<<endl;
    }
}

//本地化操作
//添加本地图书
void book_list::add_book(book bk)
{
    fstream fout(file_path,ios::out|ios::app);
    if(fout){
        fout<<bk.id<<" "<<bk.name<<" "<<bk.status<<" "<<bk.price<<endl;
        fout.close();
    }
    else {
        cout<<"文件打开失败！"<<endl;
    }
}

//更新本地图书信息
void book_list::alter_book()
{
    fstream fout(file_path,ios::out|ios::trunc);
    list<book>::iterator beg=bk_ls.begin();
    list<book>::iterator ed=bk_ls.end();
//    更新图书信息
    if(fout){
        while(beg!=ed){
           fout<<beg->id<<" "<<beg->name<<" "<<beg->status<<" "<<beg->price<<endl;
           beg++;
        }
        fout.close();
    }
    else {
        cout<<"文件打开失败！"<<endl;
    }
}

//设置图书状态，并保存到本地
void book_list::alter_status(list<book>::iterator bk_it,int status)
{
    bk_it->status=status;
    bk_it->set_status();
    alter_book();
}

//读取本地数据
void book_list::book_read()
{
    fstream fin(file_path,ios::in);
    book bk;
    //读取图书信息
    if(fin){
        while(fin>>bk.id>>bk.name>>bk.status>>bk.price){
            bk_ls.push_back(bk);
                }
            fin.close();
        }
    else {
        cout<<"文件读取失败！"<<endl;
    }
}
