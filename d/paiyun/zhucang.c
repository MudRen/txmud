// Room: /d/paiyun/zhucang.c

inherit ROOM;

void create()
{
	set("short", "贮藏室");
	set("long", @LONG
这间屋子里乱七八糟堆放着木头、砍柴斧子之类的东西，看
样子是一间储藏室。
LONG
);

	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"lu10",
]));

	setup();
	replace_program(ROOM);
}
