// shengzi.c
// by dicky

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name("绳子",({"sheng zi"}));
	set_weight(500);
	if(clonep())
		set_default_object(__FILE__);
	else {
	set("unit","条");
	set("value",50);
	set("long","一条用麻布搓成的绳子。\n");
	}

	setup();
}