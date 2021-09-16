// Room: /u/w/wangs/b/kai12.c

inherit ROOM;

void create()
{
	set("short", "柳中河畔");
	set("long", @LONG
顾名思意，柳中河畔种的自然全是柳树了。自远处看到不觉
得什么，置身河边你才发现柳中河缘何得名了。河岸边到处都是
有数百年树龄的柳树，盘根交错，枝桠斜伸，有的柳树竟然生长
在河水之中，在河道狭窄的地方，两岸的柳条竟缠绕在一起。在
柳条轻拂中，一条翠绿小河蜿蜒而出，可不就是柳中之河么。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "northwest" : __DIR__"kai11",
  "northeast" : __DIR__"kai13",
]));

	set("outdoors","kaifeng");
	setup();
	replace_program(ROOM);
}
