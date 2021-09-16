// Room: /d/hangzhou/lingarden.c

inherit ROOM;

void create()
{
	set("short", "后花园");
	set("long", @LONG
这里是林家的后花园，不过这里已经是杂草丛生，花木繁杂
应该是很久没有人打理了，花园的角落有一座一人多高的假山，
旁边还有一口水井。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"linmishi",
  "west" : __DIR__"linpath3",
]));
	set("outdoors", "hangzhou");
	set("resource/water",1);
	setup();
	replace_program(ROOM);
}
