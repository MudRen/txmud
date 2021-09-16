// shulin4.c
// by dicky

inherit ROOM;

void create()
{
  set ("short", "松林深处");
  set ("long", @LONG
这是一片茂密的树林。很多棵几十丈高的大树聚在一块，象一把把琼天
大伞，连日月都被遮蔽得暗然无光。树林中还不时可以听到大自然发出的声
响。偶尔传来一两声虎啸，回荡在山谷中，使你不觉加快了脚步。
LONG);
	set("outdoors", "taxue");

	set("exits",([
             "northeast" : __DIR__"shulin10",
             "south" : __DIR__"shulin4",
             "east"  : __DIR__"shulin8",
	]));

	setup();
	replace_program(ROOM);
}
