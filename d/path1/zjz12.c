// Room: /d/path1/zjz12.c

inherit ROOM;

void create()
{
	set("short", "小土路");
	set("long", @LONG
这是一条黄土小路，北面则是一片树林。风一吹过，一条向
北的林间小路若有若无，西面不远就是左家村。再向东去，就是
渤海湾了。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"zjz11",
  "north" : __DIR__"zjz13",
]));
	set("outdoors", "path1");
	setup();
	replace_program(ROOM);
}
