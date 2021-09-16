// she_cha.c

inherit ITEM;

void create()
{
	set_name("�߲�", ({ "she cha","cha"}) );
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else
	{
		set("unit", "֦");
		set("long", "����һ֦ľ�ʵ��߲棬ͷ�ϰ���һ��Сľ辣�
����������(cha)���ߵĶ���ʹ���޷��Ŷ���\n");
		set("value",500);
	}
}

void init()
{
	if(this_player()
	&& (environment() == this_player()))
		add_action("do_cha","cha");
}

int do_cha(string arg)
{
	object me = this_player(),ob;
	int status;

	if(environment() != me)
		return 0;

	if(!stringp(arg) || arg == "")
		return notify_fail("��Ҫ���߲��ʲô��\n");

	if(!ob = present(arg,environment(me)))
		return notify_fail("��Ҫ���߲��ʲô��\n");

	if( !function_exists("accept_shecha",ob) )
		return notify_fail("�ǲ���һ�����ߡ�\n");

	me->start_busy(1);
	if(!status = ob->accept_shecha(this_object()))
		return notify_fail(sprintf("�������߲泯��%s���˹�ȥ������û�в��С�\n",ob->name()));
	if(status < 0)
		return notify_fail(sprintf("%s�Ѿ�����ס�ˡ�\n",ob->name()));

	message_vision(sprintf("\n$N�����߲������%s���˹�ȥ���߲�һ���ӿ�ס�˶��١�\n\n",
		ob->name()),me);
	this_object()->move(environment(me));
	return 1;
}

int valid_get(object who)
{
	delete_temp("snake");
	return 1;
}
