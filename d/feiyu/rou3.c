// rou3.c

#include <ansi.h>;
inherit ROOM;

void create ()
{
	set("short", "����ի");
	set ("long", @LONG
���Ĵ���ƬƬ��磬��Ȼ�����ǰ������������ȴ��ȫ��
��һ������������Ǵ���ɫ��ʯ���ӣ���ϸ��ȥ����ߵ�������
��ǳ��⻪�����󾭳����˴�����
LONG);

	set("item_desc",([
	"����" : "�㷢�������Ϻ�����һ���ط�������ȥ�����񾭳����˰�����\n",
]));

	set("exits", ([ /* sizeof() == 1 */
	"out" : __DIR__"rou2",
]));

	set(SAFE_ENV,1);

	setup();
}

void init()
{
	add_action("do_an","an");
}

int do_an(string arg)
{
	object me = this_player();

	if(arg != "����"&& arg != "zhuzi")
		return 0;

	message_vision("����ͻȻ�ѿ�һ������ֻ��$N������ȥ��\n",me);
	tell_room(__DIR__"rou4",sprintf("%s���������������\n",me->name()));
	me->move(__DIR__"rou4");
	return 1;
}
