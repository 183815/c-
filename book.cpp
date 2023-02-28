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
	case 0:status_out = "借出";
		break;
	case 1:status_out = "在馆";
		break;
	case 2:status_out = "遗失";
		break;
	default:status_out = "错误";
		break;
	}
}
