// Room: /wiz/louth/c/xiaowu.c

inherit ROOM;

void create()
{
	set("short", "小屋");
	set("long", @LONG
这是一间简陋的小土屋，中央摆着一张破木桌，一条桌子腿
还是用土坯垫的，奇怪的是桌面非常的干净。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"dayuan",
]));

	set("objects", ([
	__DIR__"npc/crazy_woman" : 1,
]));

	setup();
	replace_program(ROOM);
}
