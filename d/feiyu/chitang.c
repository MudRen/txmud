// Room: /d/feiyu/chitang.c

inherit ROOM;

void create()
{
	set("short", "С����");
	set("long", @LONG
����һ��СС�ĳ������������ˮ�峺���ס������ܿ����
���ĵ�������ˮͰ�������(fill)ˮȥ������
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
	"south" : __DIR__"yu16",
]));

	set("outdoors","feiyu");
	setup();
}

void init()
{
	add_action("do_fill","fill");
}

int do_fill(string arg)
{
	object me = this_player(),ob;

	if(!objectp(ob = present("water bucket",me)) || !ob->id(arg))
		return notify_fail("��Ҫ��ʲô��ˮ��\n");

	if(ob->is_full())
		return notify_fail("ˮͰ�Ѿ��������ˡ�\n");

	message_vision("$N����ˮͰ�ڳ��������������һͰ��ˮ��\n",me);
	ob->set_full(1);
	return 1;
}
