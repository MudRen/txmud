// yu63.c

inherit ROOM;

void create()
{
    set("short", "������");
	set("long", @LONG
������һ�����͵����£���˵ǰ�����������������
��ʧ�⣬�����ǲ�֪մ���˶���������ʿ��Ѫ�ı���������
�µף�����Ҳû�����ҵ���
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "southdown" : __DIR__"yu62",
]));
	set("outdoors","feiyu");
	setup();
}

void init()
{
        add_action("do_jump","jump");
}

int do_jump(string arg)
{
        object me = this_player();

	if(arg != "down")
		return 0;

	if(me->query_skill("dodge",1) < 110 || me->query("combat_exp") < 50000)
		return notify_fail("����ԥ��һ�£�û������ȥ��\n");

	message_vision("$N˫�۽��գ���������������..\n\n",me);
	me->move(__DIR__"yu68");
	return 1;
}
