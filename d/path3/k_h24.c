// Room: /d/path3/k_h24.c

inherit ROOM;

void create()
{
	set("short", "土路");
	set("long", @LONG
这是一条黄土大路，路的东北面是一片郁郁葱葱的树林，西
面是块块的稻田。几头水牛正在田里悠闲地转来转去。偶尔传来
嘹亮的歌声。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"k_h25",
  "north" : __DIR__"k_h23",
]));
	set("no_clean_up", 0);
	set("outdoors", "path3");
	setup();
	replace_program(ROOM);
}
