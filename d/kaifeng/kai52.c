// Room: /u/w/wangs/b/kai52.c

inherit ROOM;

void create()
{
	set("short", "杂货铺");
	set("long", @LONG
一间老字号的杂货铺。祖孙三代经营下来，在开封城南一带
已经有了一些小名气。这里无论是油盐酱醋，还是大米白面，老
百姓日常生活需要的东西一样都不少。再加上这里的老掌柜待客
如宾，生意一向都很好。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"kai166",
]));
        set("objects",([
        __DIR__"npc/zhboss" : 1,
]));

	setup();
	replace_program(ROOM);
}
