// Room: /wiz/louth/a/yu70.c

inherit ROOM;

void create()
{
	set("short", "���µ�");
	set("long", @LONG
�����ǰ��һ����ֱ��ɽ�壬����ǧ�ɣ��嶥��������
��Լ�ɼ��������Ի����м������������ٴ������ϴ��£���
����һƬ����ݵء�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"caodi1",
  "south" : __DIR__"yu69",
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

	if(arg != "����" && arg != "cliff")
		return 0;

	message_vision("$Nץס�����ϵ����٣�������ȥ������\n",me);
	me->start_busy(6);
	call_out("greeting",6,me);
	return 1;
}

void greeting(object me)
{
	if(!objectp(me) || (environment(me) != this_object()))
		return;

	message_vision("$N����һ�����������������¡�\n",me);
        me->stop_busy();
	me->move(__DIR__"yu63");
}
