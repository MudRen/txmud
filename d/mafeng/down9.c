// Room: /d/mafeng/down9.c

inherit ROOM;

protected void send_msg()
{
	object room;
	string file;

	if( objectp(room = find_object(file=__DIR__"control"))
	|| objectp(room = load_object(file)) )
		room->check_rooms();
}

void create()
{
	set("short", "ʯ��");
	set("long", @LONG
����һ�����ʯ�ң����ܶ����ô�ĥ�ķǳ�ƽ������ʯ��
�ɵģ��м���һ��ʯ��������ʯ�������ĸ����ѣ�������ʯ��
�յĵƻ�ͨ���������ǽ�ϻ������һ����ͷ��
LONG
	);

	set("item_desc", ([
	"��ͷ" : "һ����ʯͷ��̵����������Ļ�ͷ������ǳ��Ĺ⻬��\n",
]));

	set("exits", ([ /* sizeof() == 1 */
  "northwest" : __DIR__"down8",
]));

	setup();
}

void reset() { }

void init()
{
	add_action("do_push", "push");
}

int do_push(string arg)
{
	object me;

	if(arg != "��ͷ")
		return notify_fail("��Ҫ��ʲô��\n");

	me = this_player();

	message_vision("$N��������һ�»�ͷ����ͷ������ƶ���һ�¡�
һ���������ͻȻ���µ�ʯ�������Էֿ���$N������ȥ��\n", me);

	me->move(__DIR__"out1");

	if(find_call_out("send_msg") == -1)
		call_out("send_msg", 3);
	return 1;
}

#include "kill.h";