// Room: /d/heifeng/mishi2.c

inherit LIGHT_ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"midao4",
]));

	setup();
}
