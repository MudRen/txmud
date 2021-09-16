// Room: /d/tangmen/xiaodao4.c

inherit ROOM;

void create()
{
	set("short", "丛林小道");
	set("long", @LONG
这是一条僻静的丛林小道，小道上满是枯枝败叶，踩上去非
常松软，四周静悄悄的，偶尔传来几声鸟鸣。
LONG
	);
	set("exits", ([
  "southeast" : __DIR__"xiaodao3",
  "north" : __DIR__"yaopu1",
]));

	set("outdoors", "tangmen");
	setup();
	replace_program(ROOM);
}
