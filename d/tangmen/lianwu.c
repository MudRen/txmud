// Room: /d/tangmen/lianwu.c

inherit ROOM;

void create()
{
	set("short", "���䳡");
	set("long", @LONG
����������ŵĵ���ƽʱ�����ĵط������ٵ����������ȭ
���ȡ�������һ��һ�˶�ߵ�÷��׮(zhuang)���������(jump)
��ȥ��׮��ϰ�Ṧ��
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"tulu1",
]));

	set("NO_NPC", 1);

	setup();
}

void init()
{
	add_action("do_jump", "jump");
}

int do_jump(string arg)
{
	object me = this_player();
	string out;

	if(arg != "zhuang" && arg != "÷��׮")
	{
		write("��Ҫ�������\n");
		return 1;
	}

	out = "$N��������÷��׮��\n";

	if(me->query_skill("dodge", 1) < 30)
	{
		out += "���ӻ��˼��£�ˤ��������\n";
		message_vision(out, me);
		me->receive_wound("kee", me->query("max_kee")/4, "trip");
		me->start_busy(2);
		return 1;
	}

	message_vision(out, me);
	if(!me->move(__DIR__"zhuang1"))
	{
		tell_object(me, "�㿴�˿�������̫�࣬�����˻�ȥ��\n");
		tell_room(__FILE__, me->name()+"����������\n", ({me}));
		return 1;
	}

	me->start_busy(2);
	return 1;
}
