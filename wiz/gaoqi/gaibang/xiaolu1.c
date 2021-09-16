
inherit ROOM;

void create()
{
   set("short", "小路");
	set("long", @LONG
这是小路1，北面是草场，南面是个小土坡。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : "/wiz/gaoqi/gaibang/caochang.c",
  "south" : "/wiz/gaoqi/gaibang/tupo.c",
]));	setup();
}
