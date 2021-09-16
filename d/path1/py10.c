// Room: /d/path1/py10.c

inherit ROOM;

void create()
{
	set("short", "枫晓亭");
	set("long", @LONG
这里就是枫晓亭，在路的北边，长满了枫树。每当秋天到来
的时候，片片红叶使人留恋难已离去。从这里向东通向鹿马集，
西去通向长安城，穿过北面的树林，可以到山海关。
LONG
	);

	set("exits", ([
  "south" : __DIR__"lmj1",
  "east" : __DIR__"py9",
  "north" : __DIR__"lu_cross1",
]));
	set("outdoors", "path1");
	setup();

	replace_program(ROOM);
}
