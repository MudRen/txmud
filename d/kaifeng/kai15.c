// Room: /u/w/wangs/b/kai15.c

inherit ROOM;

void create()
{
	set("short", "���к���");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "southwest" : __DIR__"kai14",
]));
        set("objects",([
        __DIR__"npc/songy": 1,
]));

	set("outdoors","kaifeng");
	setup();
	replace_program(ROOM);
}
