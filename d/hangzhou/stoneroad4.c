// Room: /d/hangzhou/stoneroad4.c

inherit ROOM;

void create()
{
	set("short", "石板路");
	set("long", @LONG
这是一条青石铺成的大路，路西有不少的民房，这些房屋虽
然有些旧了，可看起来还是满整齐的。路的东面不远处就是闻名
遐尔的苏堤了。
LONG
	);
	set("outdoors", "hangzhou");
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  //"southwest" : __DIR__"leifeng",
  "east" : __DIR__"paths1",
  "north" : __DIR__"stoneroad3",
]));

	set("objects",([
	NPC_DIR"stdnpc/stdnpc_3" : 4,
]));

	setup();
	replace_program(ROOM);
}
