// Room: /d/tangmen/fengd1.c

inherit __DIR__"fengd";

void create()
{
	set("short", "��ľ��");
	set("long", (: query_long :) );
	set("exits", ([
  "south" : __DIR__"fengdown5",
  "north" : __DIR__"fengd4",
  "west" : __DIR__"fengd2",
]));

	set("item_desc", ([
	"����" : (: query_item_desc :),
	"С����" : (: query_item_desc :),
]));
	set("outdoors", "tangmen");
	setup();
}
