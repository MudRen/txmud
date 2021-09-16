// Room: /d/hangzhou/zfyuanzi.c

inherit ROOM;

void create()
{
	set("short", "天井");
	set("long", @LONG
绕过一堵影壁墙，你的眼前是一个大天井，一条青石板大路
一直通到大堂，路边的大树下有一个兵器架，整整齐齐的挂着一
排水火棍。
LONG
	);
	set("outdoors", "hangzhou");
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"zfpath3",
  "south" : __DIR__"zhifu",
  "east" : __DIR__"zfpath1",
  "north" : __DIR__"zfdatang",
]));

	setup();
	replace_program(ROOM);
}
