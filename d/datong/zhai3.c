// Room: /d/datong/zhai3.c

inherit ROOM;

void create()
{
	set("short", "��Ժ");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣

LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "southwest" : __DIR__"zhai2",
]));

	set("objects",([
	__DIR__"npc/xiaocui" : 1,
]));
	setup();
	replace_program(ROOM);
}
