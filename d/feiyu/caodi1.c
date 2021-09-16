// Room: /wiz/louth/a/caodi1.c

inherit ROOM;

void create()
{
	set("short", "���µ�");
	set("long", @LONG
���������µĵײ�����ǰ��һ���Ƕ�ֱ��ʯ��ͨ�����棬��
�ϳ����˰��˸ߵ���ݡ�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"yu70",
]));
        set("outdoors","feiyu");
	setup();
}

void init()
{
	add_action("do_climb","climb");
}

int do_climb(string arg)
{
	object me = this_player();

	if(arg != "����")
		return 0;

	message_vision("$N˳������������ȥ������\n\n",me);
	me->start_busy(6);
	call_out("greeting",5,me);
        return 1;
}

void greeting(object me)
{
	if(!objectp(me) || (environment(me) != this_object()))
		return;
	message_vision("$N�۵�����������������һ��ɽ������ڴ���\n",me);
	me->move(__DIR__"shandong1");
}
