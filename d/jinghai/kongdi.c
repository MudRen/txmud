// Room: /d/jinghai/kongdi.c

inherit ROOM;

void create()
{
	set("short", "��̲��");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣

LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"houmen",
]));
        set("outdoors","jinghai");

	setup();
	replace_program(ROOM);
}
