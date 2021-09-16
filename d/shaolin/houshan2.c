// Room: /d/shaolin/houshan2.c

inherit ROOM;

void create()
{
	set("short", "后山");
	set("long", @LONG
这里是少室山的后山，东南面是一处宏大的寺庙，那就是名
满武林的少林寺了，北面是一片乱石岗，一条小径隐约可见。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"houshan1",
  "north" : __DIR__"luanlu1",
  "southwest" : __DIR__"qhs1",
]));

	setup();
	replace_program(ROOM);
}
