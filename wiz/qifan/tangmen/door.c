// Room: /d/tangmen/door.c

inherit ROOM;

void create()
{
	set("short", "大门");
	set("long", @LONG
这里是一处庄正高大石门，与众不同的是门两旁各摆着一个
青石雕刻的卧虎，门上还有不少的小孔，也不知道是做什么用的，
门的正上方的墙里嵌着一块石板，石板上刻着“唐家堡”三个苍
劲的大字，原来这里就是令武林人士变色的蜀中唐门。
LONG
	);
	set("exits", ([
  "north" : __DIR__"bridge1",
  "east" : __DIR__"lcd07",
]));

	set("outdoors", "tangmen");

	setup();
	replace_program(ROOM);
}
