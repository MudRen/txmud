// Room: /d/path3/k_s13.c

inherit DANGER_ROAD;

void create()
{
	set("short", "小竹林");
	set("long", @LONG
你走进一片竹林，只见四周密密麻麻的全是竹子，可能是刚
下过雨的缘故，一些竹子根部长出了嫩绿的竹笋。哗哗作响的竹
叶像是在说着什么，你四处张望了一下，什么都没有发现。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southwest" : __DIR__"k_s14",
  "north" : __DIR__"k_s12",
]));
        set("outdoors", "path3");
	setup();
	replace_program(ROOM);
}
