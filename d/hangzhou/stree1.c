// Room: /d/hangzhou/stree1.c

inherit ROOM;

void create()
{
	set("short", "树林");
	set("long", @LONG
这是杭州城外的一片树林，林中小鸟在不停地叽叫，仿佛在
向你说着什么。在烈日的当午，这里可是乘凉的好地方。东面是
城外的黄土大道。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"spath1",
]));
	set("outdoors", "hangzhou");

	setup();
	replace_program(ROOM);
}
