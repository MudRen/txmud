// Room: /d/path5/ccg35.c

inherit ROOM;

void create()
{
	set("short", "通麦");
	set("long", @LONG
这里是通麦，由此向东过了山区就是川中领地了，向西不远
处像是有一个村落。穿过北面茫茫的草原，可以到那曲。路的一
边有一块牌子(pai)。
LONG
	);
	set("outdoors", "chengdu_w");
	set("exits", ([
  "west" : __DIR__"ccg36",
  "east" : __DIR__"ccg34",
  "north" : "/d/path6/lna01",
]));
	set("cannot_build_home", 1);
	set("item_desc", ([
	"pai" : "
	north        昌都
	east         怒江
	west         林芝 
\n",
	"牌子" : "
	north        昌都
	east         怒江
	west         林芝 
\n",
]));

	setup();
	replace_program(ROOM);
}
