// snake1.c
// by dicky

inherit ITEM;
int decayed;

void create()
{
        set_name("����", ({ "snake"}) );
	set("long", "һ���׺ݵĶ��ߣ���ʱ�����һ�š�\n");
	set("unit", "��" );
        if( clonep() )
                set_default_object(__FILE__);
		call_out("decay", 300, 1);
}

void decay(int phase)
{
	object me=this_object();
	decayed = phase;

	if(!environment())
	{
		destruct(me);
		return;
	}

	tell_object(environment(), "" + me->query("name") + "ͻȻ" +me->query("name")+ "��ȥ�ݴԲ����ˣ�����ȥץ���������Ѿ���������\n\n" );
        destruct(me);
}