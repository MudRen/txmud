// Room: /wiz/uudd/path2/tree.c

inherit ROOM;

void create()
{
	set("short", "树林");
	set("long", @LONG
你走在树林里环顾四周，眼见四周一片生气勃勃，不时有一
些小动物一闪而过，眼下一片绿草油油，你不禁深深吸了一口大
自然的空气。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"k_s14",
]));

	setup();
	set("outdoors", "shaolin");
	replace_program(ROOM);
}
