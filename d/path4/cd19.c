// Room: /d/path4/cd19.c

inherit ROOM;

void create()
{
	set("short", "�ٵ�");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : "/d/dali/out_dali_n",
  "north" : __DIR__"cd18",
]));
	set("outdoors", "path4");
	setup();
	replace_program(ROOM);
}
