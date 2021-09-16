// Room: /d/renyi/renyi1.c

inherit ROOM;

inherit __DIR__"die";

void create()
{
	set("short", "过道");
	set("long", @LONG
这里是一条狭窄的过道，青砖铺就的地面已经磨的有些凹了
下去，东面有一扇竹门半开着。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"access_room",
  "west" : __DIR__"renyi2",
]));

	set(SAFE_ENV, 1);

	setup();
}
