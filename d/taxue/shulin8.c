// shulin5.c
// by dicky

inherit ROOM;

void create()
{
  set ("short", "松林深处");
  set ("long", @LONG
这里是茂密的森林。四周都是数不清的长草，一股阴森恐怖的
气氛。远处不时传来野兽的嚎叫，回荡在山谷中给你一种恐怖的感
觉，你实在不想在这里多留。
LONG);

	set("outdoors", "taxue");

	set("exits",([
             "south" : __DIR__"shulin5",
             "west"  : __DIR__"shulin7",
             "east"  : __DIR__"shulin9",
	]));

	setup();
	replace_program(ROOM);
}
