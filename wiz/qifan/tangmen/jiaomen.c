// Room: /d/tangmen/jiaomen.c

inherit ROOM;

void create()
{
	set("short", "角门");
	set("long", @LONG
这里是唐家堡的一处后角门，门上挂着一把打铁锁好像很久
没有开动过的样子，看样子很少有人来这里。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"ssl4",
]));

	set("outdoors", "tangmen");
	setup();
	replace_program(ROOM);
}
