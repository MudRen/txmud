// Room: /u/w/wangs/b/kai100.c

inherit ROOM;

void create()
{
	set("short", "�Ͻ�·��");
	set("long", @LONG
�������������������Ľ֣�����Զ�����ǿ��⸮�ı�־����
������ͭ�����ˣ�������һ�����Ĵ�������ǿ��⸮���Ͻ֡�
·������һ�ҵ��̣��ſڹ���һ�����ƣ�����д�š���ǡ�����
������һ��ľ�ĵꡣ
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"kai103",
  "north" : __DIR__"kai97",
  "west" : __DIR__"kai101",
  "east" : __DIR__"kai102",
]));
        set("objects",([
	NPC_DIR"stdnpc/stdnpc_1" : 2,
]));

	set("outdoors","kaifeng");
	setup();
	replace_program(ROOM);
}
