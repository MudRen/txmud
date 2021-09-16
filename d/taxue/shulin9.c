// shulin3.c
// by dicky

inherit ROOM;

void create()
{
  set ("short", "松林深处");
  set ("long", @LONG
四周古树参天，荆棘密布。浓密宽厚的树叶遮蔽了日月星辰，使人分不出
昼夜。四下如死一般的寂静，只有风吹过树梢的沙沙之声。偶尔一两声虎啸狼
嚎随着腥风飘至耳际。
LONG);

	set("outdoors", "taxue");

	set("exits",([
             "northwest" : __DIR__"shulin10",
             "south" : __DIR__"shulin6",
             "west"  : __DIR__"shulin8",
	]));

	setup();
	replace_program(ROOM);
}
