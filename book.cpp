#include "book.h"
book::book()
{
    set_status();
}

book::~book()
{

}

void book::set_status()
{
	switch (status)
	{
	case 0:status_out = "���";
		break;
	case 1:status_out = "�ڹ�";
		break;
	case 2:status_out = "��ʧ";
		break;
	default:status_out = "����";
		break;
	}
}
