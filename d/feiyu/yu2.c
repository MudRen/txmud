// Room: /u/w/wangs/a/yu2.c

inherit ROOM;

void create()
{
	set("short", "绯雨阁前院");
	set("long", @LONG
这里是绯雨阁的前院，相当宽敞。左右靠墙各建有两间
低矮的平房，像是家人的住处。院中种满了各种花草，清风
吹来，香气袭人。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"yu5",
  "north" : __DIR__"yu1",
  "west" : __DIR__"yu3",
  "east" : __DIR__"yu4",
]));
       set("outdoors","feiyu");

	setup();
	replace_program(ROOM);
}
