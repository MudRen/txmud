// Room: /d/tangmen/fengd5.c

inherit __DIR__"fengd";

void create()
{
	set("short", "��ľ��");
	set("long", (: query_long :) );
	set("exits", ([
  "south" : __DIR__"fengd2",
  "north" : __DIR__"fengd8",
  "west" : __DIR__"fengd6",
  "east" : __DIR__"fengd4",
]));

	set("item_desc", ([
	"����" : (: query_item_desc :),
	"С����" : (: query_item_desc :),
]));
	set("outdoors", "tangmen");
	setup();
}