// Room: /d/jinghai/xuanya1.c

inherit ROOM;

void create()
{
	set("short", "���¾�ͷ");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣

LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"xuanya",
]));
        set("outdoors","jinghai");

	setup();
	replace_program(ROOM);
}
