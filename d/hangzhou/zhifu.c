// Room: /d/hangzhou/zhifu.c

inherit ROOM;

void create()
{
	set("short", "知府大门");
	set("long", @LONG
你面前是杭州府的知府衙门，果然气派非凡，红漆大门上面
镶满了黄铜门钉，大门上面挂着一个黑色牌匾，上书“杭州府”
三个金色大字。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"guotaiw2",
  "north" : __DIR__"zfyuanzi",
]));

	setup();
	replace_program(ROOM);
}
