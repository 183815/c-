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
    cout <<"0.�˳�\n" << "1.��ѯ\n" << "2.���\n" << "3.����\n" << "4.����\n" << "5.��ʧ����\n" << "���������:" ;
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
