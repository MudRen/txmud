// Room: /d/path1/tch_ft11.c

inherit ROOM;

void create()
{
	set("short", "裕岭");
	set("long", @LONG
这里就是裕岭，是位于山海关东面的又一要道。向西的方向
通往山海关，向东则一直通向奉天府。另有一条小路向南而去。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"tch_ft10",
  "northeast" : __DIR__"tch_ft12",
  "southeast" : __DIR__"ft_s1",
]));
	set("outdoors", "path1");
	setup();
	replace_program(ROOM);
}
