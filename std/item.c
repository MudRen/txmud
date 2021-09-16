// item.c

#include <dbase.h>
#include <move.h>
#include <name.h>

inherit F_CLEAN_UP;
inherit F_DBASE;
inherit F_MOVE;
inherit F_NAME;


protected int credit_point_flag = 0;

void set_credit_point_flag() { credit_point_flag = 1; }

int query_credit_point_flag()
{ return credit_point_flag?1:0; }

void setup()
{
	seteuid(getuid());
}

varargs string long(int raw)
{
	string desc;

	desc = ::long(raw);

	if(credit_point_flag)
	{
		if(!desc)
			desc = "[1;32m->���õ���Ʒ<-[2;37;0m";
		else
			desc += "[1;32m->���õ���Ʒ<-[2;37;0m";
	}
	return desc;
}
