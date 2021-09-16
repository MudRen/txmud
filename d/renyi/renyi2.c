// Room: /d/renyi/renyi2.c

inherit ROOM;

inherit __DIR__"die";

void create()
{
	set("short", "小院");
	set("long", @LONG
这是一个安静的小院子，一条碎石子路穿于其间，边上全是
轻轻的绿草长得非常的整齐，看样子主人经常修剪。
LONG
	);

	set(SAFE_ENV, 1);
	set("no_memory", 1);

	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"renyi1",
  "south" : __DIR__"renyi3",
]));

	set("outdoors", "renyi");

	setup();
}
