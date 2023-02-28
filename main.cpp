#pragma once
#include "book_list.h"
#include "head.h"
using namespace std;

void QT()
{
    char choice;
    book_list bk_list;
    config conf;
    while(true){
    system("cls");
    bk_list.book_show();
    cout <<"0.退出\n" << "1.查询\n" << "2.添加\n" << "3.借书\n" << "4.还书\n" << "5.报备\n"<<"6.修改\n" << "请输入操作:" ;
    cin >> choice;
    switch (choice)
    {
    case '0':exit(0);
        break;
    case '1':bk_list.book_search();
        break;
    case '2':bk_list.book_add();
        break;
    case '3':bk_list.book_borrow();
        break;
    case '4':bk_list.book_return();
        break;
    case '5':bk_list.book_lost_find();
        break;
    case '6':bk_list.book_alter();
        break;
    default:cout<<"输入错误，请重新输入!"<<endl;
        break;
    }
    system("pause");
    }
}
int main()
{
    QT();
}
