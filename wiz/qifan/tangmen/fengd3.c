// Room: /d/tangmen/fengd3.c

inherit __DIR__"fengd";

void create()
{
	set("short", "��ľ��");
	set("long", (: query_long :) );
	set("exits", ([
  "north" : __DIR__"fengd6",
  "east" : __DIR__"fengd2",
]));

	set("item_desc", ([
	"����" : (: query_item_desc :),
	"С����" : (: query_item_desc :),
]));
	set("outdoors", "tangmen");
	setup();
}
