// Room: /wiz/louth/a/shan7.c

inherit ROOM;

void create()
{
	set("short", "问天崖");
	set("long", @LONG
你正站在一处高耸入云的山崖上，边上是陡峭的石壁，向下
望去云雾缭绕。左面是一间小茅草屋，屋门口一块石头上深深的
刻着“问天崖”三个大字。
LONG
);

	set("exits", ([ /* sizeof() == 2 */
  "westdown" : __DIR__"shan6",
  "west" : __DIR__"maowu",
]));

	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/shenmi" : 1,
]));

	set("outdoors","feiyu");

	setup();
	replace_program(ROOM);
}
