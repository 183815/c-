#pragma once
#include "book_list.h"
#include "head.h"
using namespace std;

void QT()
{
    char choice;
    book_list bk_list;
    while(true){
    system("cls");
    cout <<"0.退出\n" << "1.查询\n" << "2.添加\n" << "3.借书\n" << "4.还书\n" << "5.丢失报备\n" << "请输入操作:" ;
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
    case '5':bk_list.book_lost();
        break;
    default:
        break;
    }
    system("pause");
    }
}
int main()
{
    QT();
}
