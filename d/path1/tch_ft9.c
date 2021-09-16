// Room: /d/path1/tch_ft9.c

inherit ROOM;

void create()
{
	set("short", "山海关");
	set("long", @LONG
这是就是山海关了，几个守卫的官兵正在仔细地盘查着过往
的行人。一些等待检查的商人正在抱怨着，由于连年的战事，生
意越来越不好做了。向北有一条小路，不过现在已被封上了。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"tch_ft8",
  "east" : __DIR__"tch_ft10",
]));
	set("outdoors", "path1");

	set("objects",([
	__DIR__"npc/bing" : 2,
]));

	setup();
	replace_program(ROOM);
}
