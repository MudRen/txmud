
inherit ROOM;

void create()
{
   set("short", "破庙");
	set("long", @LONG
这里是破庙一个。丐帮的终极师傅就在这里了。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : "/wiz/gaoqi/gaibang/shulin4.c",
]));	setup();
}
