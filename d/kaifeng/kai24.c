// Room: /u/w/wangs/b/kai24.c

inherit ROOM;

void create()
{
	set("short", "ľ����");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"kai23",
]));

        set("objects",([
        __DIR__"npc/mujiang" : 1,
]));

	setup();
	replace_program(ROOM);
}
