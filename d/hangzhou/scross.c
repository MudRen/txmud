// Room: /d/hangzhou/scross.c

inherit ROOM;

void create()
{
	set("short", "��·��");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"spath2",
]));
	set("outdoors", "hangzhou");

	setup();
	replace_program(ROOM);
}
