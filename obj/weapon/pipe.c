// sword.c : an example weapon

#include <weapon.h>

inherit SWORD;

void create()
{
	set_name("����", ({ "pipe" }) );
	set_weight(2000);
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("unit", "��");
		set("long", "һ��Լ�����೤�������Ө͸�����������������е�һ������!\n");
		set("material", "stone");
		set("wield_msg", "ֻ���׹�һ��������$N����ͻȻ����һ�����\n");
		set("unwield_msg", "$N�������µ�վ�ţ����е�����ȴ�Ѳ�����\n");
	}

	init_sword(25);
	setup();
}

void init()
{
	add_action("do_play", ({ "play", "blow" }) );
}

int do_play(string arg)
{
	if( !id(arg) )
		return 0;

	message_vision("$N����һֻ����,����Ĵ�������,����ĵ���Ʈ��ÿ�����ӵ��ģ�Ʈ��ңԶ�Ĺ��硣\n",
		this_player() );
	environment(this_player())->pipe_notify();
        return 1;
}