// bupi.c
// by dicky

inherit ITEM;

void create()
{
        set_name("��ƥ", ({ "bu pi"}) );
	set("long", "����һ��ǳ���ʵ�Ĳ�ƥ��\n");
        set_weight(2);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
        }
        setup();
}

