// zhandan.c

inherit ITEM;

void create()
{
	set_name("栈单", ({ "zhan dan" }));
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("unit", "张");
		set("long", "一张空白栈单。\n");
	}
	setup();
}

int is_zhandan() { return 1; }
