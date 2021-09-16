// Room: /d/huashan/shiwu.c

inherit ROOM;

void create()
{
	set("short", "石屋");
	set("long", @LONG
这是一间石屋，屋里放着一个柜子，像是放书的书架，但现
在已经什么都没有了。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"dongtian",
]));

	setup();
	replace_program(ROOM);
}
