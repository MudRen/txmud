// Room: /d/heifeng/mishi1.c

inherit LIGHT_ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣
LONG
	);


	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"midao2",
]));

	setup();
}
