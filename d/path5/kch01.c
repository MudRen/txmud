// Room: /d/path5/kch01.c

inherit ROOM;

void create()
{
	set("short", "乡间小路");
	set("long", @LONG
这是一条高低不平且满是泥泞的乡间小路，十分不好走。你
不得不一脚深一脚浅的慢行，心中不停的抱怨着，干吗非要来这
个偏僻的穷山恶水的地方。北面就是南坪镇了。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"kch02",
  "north" : __DIR__"nanping",
]));
        set("outdoors", "path5");
	setup();
	replace_program(ROOM);
}
