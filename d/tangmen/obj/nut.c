// nut.c

inherit ITEM;

void create()
{
        set_name("������", ({ "hai song zi" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ��Сָ�׸Ǵ����ɫ���ӡ�\n");
        }
}

void init()
{
	add_action("do_eat", "eat");
}

int do_eat(string arg)
{
	object me = this_player();
	
	if(!id(arg))
		return 0;

	message_vision("$N�Ѻ����ӷ���������˽������������üͷ��\n", me);

	me->apply_condition("mabi", 5);
	destruct(this_object());
	return 1;
}
