// Room: /d/hangzhou/dock2.c

inherit ROOM;

void create()
{
	set("short", "东岸码头");
	set("long", @LONG
这里是西湖东岸的一个小码头，西湖水浅，大船不能行，所
以这里多是一些小渔船，搭载客人到湖中心的荷花塘一游，生意
却着实不错。在这你也可以打 (fill) 些湖水带着。
LONG
	);
	set("outdoors", "hangzhou");
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"rockroad2",
]));

	set("resource/water",1);

	setup();
	replace_program(ROOM);
}
