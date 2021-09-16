// Room: /d/renyi/renyi3.c

inherit ROOM;

inherit __DIR__"die";

void create()
{
	set("short", "过道");
	set("long", @LONG
这里是一条狭窄的过道，青砖铺就的地面已经磨的有些凹了
下去，北面是一个安静的小院。
LONG
	);

	set(SAFE_ENV, 1);

	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"renyi2",
  "south" : __DIR__"renyi4",
]));

	setup();
}
