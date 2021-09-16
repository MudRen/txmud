// Room: /d/hangzhou/zfgarden.c

inherit ROOM;

void create()
{
	set("short", "С��԰");
	set("long", @LONG
������һ�����µ�С��԰����԰��Ȼ���󣬵����ֻ��ݴ���
���£�һ����ɽ��ӳ������֮�У���ֻ��β��ȸ��Ѳ���⵽���
��ǰ������Ĵ������㡣
LONG
	);
	set("outdoors", "hangzhou");
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"zfpath3",
  "north" : __DIR__"zfpath4",
]));

	setup();
	replace_program(ROOM);
}
