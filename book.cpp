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
	case 0:status_out = "½è³ö";
		break;
	case 1:status_out = "ÔÚ¹İ";
		break;
	case 2:status_out = "ÒÅÊ§";
		break;
	default:status_out = "´íÎó";
		break;
	}
}
