// daliwan.c

inherit ITEM;

void create()
{
        set_name("������", ({"dali wan","wan"}));
        set("long", "һ�ŻƳȳȵĴ����衣\n");
        set("unit", "��");
        set("weight", 800);
        set("value", 800);
}

void init()
{
	add_action("do_eat","eat");
}

int do_eat(string arg)
{
	object me = this_player();

	if(environment() != me)
		return 0;

	if(!arg || !id(arg))
		return notify_fail("��Ҫ��ʲô��\n");

	if( me->is_busy() )
		return notify_fail(BUSY_MESSAGE);

	tell_object(me,"������һ�Ŵ����������ȥ�����ú��𣬴���Ǻ�������ġ�\n");
	me->add("food",25);
        destruct(this_object());

	return 1;
}
