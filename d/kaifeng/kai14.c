// Room: /u/w/wangs/b/kai14.c

inherit ROOM;

void create()
{
	set("short", "柳中河畔");
	set("long", @LONG
走在柳林中的小道上，耳畔是涓涓流水之声，鼻端是泥土的
清香，细柔的柳枝被微风吹动轻轻拂在面上，几条小鱼在深垂河
水之中的柳条间追逐嬉戏，你不由得心神皆醉。清清的柳中河从
这里拐了道弯，伸进城市的中心去了。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "northwest" : __DIR__"kai13",
  "northeast" : __DIR__"kai15",
]));

	set("outdoors","kaifeng");
	setup();
	replace_program(ROOM);
}
