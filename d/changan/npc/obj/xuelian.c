// xuelian.c

inherit ITEM;

void create()
{
        set_name("��ɽѩ��", ({ "tianshan xuelian"}) );
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else
	{
		set("unit", "��");
		set("long", "��ɽѩ��\n");
	}
}
