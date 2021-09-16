// Room: /u/w/wangs/b/kai80.c

inherit ROOM;

void create()
{
	set("short", "北街路口");
	set("long", @LONG
从这里往南望就是中心街，再往远处就是开封府的标志建筑
“商周铜鼎”了，北面是一条宽广的大道，那是开封府的北街。
路西边是个小茶馆，你伸头望了望，只见说书先生说得口沫横飞，
如火如荼，台下的听众便也眉飞色舞，如醉如痴。东面是个钱庄。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"kai83",
  "south" : __DIR__"kai77",
  "west" : __DIR__"kai81",
  "east" : __DIR__"kai82",
]));

	set("outdoors","kaifeng");
	setup();
	replace_program(ROOM);
}
