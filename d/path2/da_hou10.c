// Room: /d/path2/da_hou10.c

inherit ROOM;

void create()
{
	set("short", "土路");
	set("long", @LONG
这是一条黄土小路，一辆马车停在路旁，几个大桶翻倒在路
边，许多人正围着观看。你走近前去，一股酸味迎面扑来，原来
是送醋的车翻了，怪不得那么大的酸味。你继续向前走去。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"da_hou9",
  "south" : "/d/houmaji",
]));
	set("no_clean_up", 0);
	set("outdoors", "path2");
	setup();
	replace_program(ROOM);
}
