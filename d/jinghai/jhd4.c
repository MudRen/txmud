// Room: /d/jinghai/jhd4.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣

LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "southwest" : __DIR__"jhd3",
]));
        set("outdoors","jinghai");

	setup();
	replace_program(ROOM);
}
