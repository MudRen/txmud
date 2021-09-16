// Room: /d/path5/kch46.c

inherit ROOM;

void create()
{
	set("short", "牧区");
	set("long", @LONG
这里是一片草地，草儿长得十分茂盛，草场上一群群的牛羊
正悠闲的跺着小步，看来这里是当地人放牧的地方。不时传来牧
笛的声音，悠扬地飘向远空。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "eastdown" : __DIR__"kch47",
  "north" : __DIR__"kch45",
]));
        set("outdoors", "path5");
	setup();
	replace_program(ROOM);
}
