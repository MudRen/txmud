// Room: /d/tangmen/fengd8.c

inherit __DIR__"fengd";

void create()
{
	set("short", "��ľ��");
	set("long", (: query_long :) );
	set("exits", ([
  "south" : __DIR__"fengd5",
  "west" : __DIR__"fengd9",
  "east" : __DIR__"fengd7",
]));

	set("item_desc", ([
	"����" : (: query_item_desc :),
	"С����" : (: query_item_desc :),
]));
	set("outdoors", "tangmen");
	setup();
}
