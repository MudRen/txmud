// Room: /d/path1/py5.c

inherit ROOM;

string go_enter(object me);

void create()
{
	set("short", "山路");
	set("long", @LONG
你延着崎岖的山路缓步而行。抬头看去，北面是一座高山，
山上绿色的丛林中好像有什么东西在晃动，你心中一动，不由得
加快脚步。
LONG
	);

	set("exits", ([ /* sizeof() == 2 */
  "southwest" : __DIR__"py6",
  "east" : __DIR__"py4",
  "north" : (: go_enter :),
]));
	set("outdoors", "path1");
	setup();
}

string go_enter(object me)
{
	if(!me || !me->query_temp("pass_changan_dutu"))
		return __DIR__"shanao";

	//me->delete_temp("pass_changan_dutu");
	return "/d/paiyun/up1";
}
