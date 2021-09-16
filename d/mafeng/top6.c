// Room: /d/path3/top6.c

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
  "south" : __DIR__"top3",
  "north" : __DIR__"top9",
  "east" : __DIR__"top5",
]));

	set("outdoors", "mafeng");
	setup();
}

#include "kill.h";