
inherit ROOM;

void create()
{
	set("short", "��繤����");
	set("long", @LONG
����һ���շ��䡣
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : "/d/xueting/inn",
]));	setup();
}
