#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "ɽ��");
	set("long", @LONG
�����ǿ�����Ĵ�ɽ�������ܵ�ʯ�����ʮ��ƽ��������
���ż�ֻ��ȼ�Ļ�ѣ���������ϸϸ��ɳ�ӣ�����ȥ�������ʡ�
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"shandong3",
]));
        set("item_desc",([
        "ʯ��" : "һ���ͺͺ��ʯ�ڣ��ϱ�����һ�Ѳ�֪���ı�����ֻ¶���˽�������ߡ�\n",
]));
	setup();
}

void init()
{
	add_action("do_get",({ "pull","ba" }));
}

int do_get (string arg)
{
	object me = this_player(),ob;

	if (arg != "sword" && arg != "��")
		return 0;

	ob = new(__DIR__"obj/windsword");
	if(!ob->valid_clone())
	{
		destruct(ob);
		return notify_fail("ʯ���ϵı����Ѿ����������ˡ�\n");
	}

	if(me->query("class") != "rain")
	{
		destruct(ob);
		return notify_fail("�����Ű���������ѽ������Ǻ��޷�Ӧ��\n");
	}

	if(me->query_skill("unarmed") < 120 || me->query("str") < 40)
	{
		destruct(ob);
		return notify_fail("��ı������β�����ѽ���\n");
	}

	if(me->query("force_factor") < 100 || me->query("force") < 100)
	{
		destruct(ob);
		return notify_fail("�����Ű��˰α����������˿������\n");
	}

	message_vision(HIC"$N�����������첲�����𣬴��һ�����γ�������ʯ���ϵı�����\n"NOR,me);
	me->add("force",-100);
	ob->move(me);
	return 1;
}
