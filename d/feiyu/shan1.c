// Room: /wiz/louth/a/shan1.c

inherit ROOM;

void create()
{
	set("short", "崎岖山路");
	set("long", @LONG
这是一条崎岖的山路，边上是陡峭的悬崖，悬崖上还长着一
些小花草，山风吹的你摇摇晃晃。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "westup" : __DIR__"shan2",
  "southdown" : __DIR__"shanlu5",
]));
       set("outdoors","feiyu");
	setup();
	replace_program(ROOM);
}
