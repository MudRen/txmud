// Room: /d/path3/top5.c

inherit ROOM;
inherit __DIR__"top";

void create()
{
	set("short", "ɽ���յ�");
	set("long", (: query_long :));

	set("item_desc", ([
	"ʯͷ" : (: query_desc_shitou :),
	"����" : (: query_desc_tieban :),
]));

	set("exits", ([
  "south" : __DIR__"top2",
  "north" : __DIR__"top8",
  "west" : __DIR__"top6",
  "east" : __DIR__"top4",
]));

	set("outdoors", "mafeng");
	setup();
}

#include "kill.h";