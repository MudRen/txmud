// zhandan.c

inherit ITEM;

void create()
{
	set_name("ջ��", ({ "zhan dan" }));
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("unit", "��");
		set("long", "һ�ſհ�ջ����\n");
	}
	setup();
}

int is_zhandan() { return 1; }
