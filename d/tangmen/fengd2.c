// Room: /d/tangmen/fengd2.c

inherit __DIR__"fengd";

void create()
{
	set("short", "��ľ��");
	set("long", (: query_long :) );
	set("exits", ([
  "west" : __DIR__"fengd3",
  "east" : __DIR__"fengd1",
  "north" : __DIR__"fengd5",
]));

	set("item_desc", ([
	"����" : (: query_item_desc :),
	"С����" : (: query_item_desc :),
]));
	set("outdoors", "tangmen");
	setup();
}
