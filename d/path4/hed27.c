// Room: /d/path4/hed27.c

inherit ROOM;

void create()
{
	set("short", "��ʯ���");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : "/d/dali/out_dali_e",
  "east" : __DIR__"hed26",
]));
	set("outdoors", "path4");
	setup();
	replace_program(ROOM);
}
