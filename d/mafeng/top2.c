// Room: /d/path3/top2.c

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
  "west" : __DIR__"top3",
  "east" : __DIR__"top1",
  "north" : __DIR__"top5",
  "southdown" : __DIR__"up10",
]));

	set("outdoors", "mafeng");
	setup();
}

#include "kill.h";