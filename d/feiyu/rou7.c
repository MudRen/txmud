// rou7.c

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����һ��������ŵ����ң�������ڷ���һ�ѹ��ӵĹ�
�٣��ٵ�һ�˺������չ��ĺۼ��������Ǵ�˵�еĽ�β���٣�
��������ѵõĹ�����Ҳ������һչ���֡�
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"rou6",
]));
        set("objects", ([ /* sizeof() == 4 */
  __DIR__"obj/se" : 1,
]));
	setup();
}

void init()
{
	add_action("do_move","move");
}

int do_move(string arg)
{
        object me = this_player(),ob;

	if(!ob = present("gu qin",this_object()))
		return 0;

	if( !ob->id(arg) && arg != "����")
		return notify_fail("��ҪŲʲô��\n");

	message_vision("$NС�ĵ�Ų��Ų���������ϵ��ǰѹ��١�\nֻ������¡һ����ǽ�ڵ�һ�ߺ�Ȼ����һ���š�\n",me);
	set("exits/enter",__DIR__"rou8");
	call_out("guanmen",8);
	return 1;
}

void guanmen()
{
	if(query("exits/enter"))
	{
		write("ǽ�������ĺ����ˡ�\n");
		delete("exits/enter");
	}
}
