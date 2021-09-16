// Room: /u/w/wangs/b/kai13.c

inherit ROOM;

void create()
{
	set("short", "柳中河畔");
	set("long", @LONG
走在柳林中的小道上，耳畔是涓涓流水之声，鼻端是泥土的
清香，细柔的柳枝被微风吹动轻轻拂在面上，几条小鱼在深垂河
水之中的柳条间追逐嬉戏，你不由得心神皆醉。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"kai14",
  "southwest" : __DIR__"kai12",
]));
        set("objects",([
        __DIR__"npc/xianren": 1,
]));
        set("resource/water",1);

	set("outdoors","kaifeng");
	setup();
	replace_program(ROOM);
}
