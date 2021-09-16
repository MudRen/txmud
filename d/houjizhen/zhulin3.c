// zhulin6.c
//by dicky

inherit ROOM;

void create()
{
	set("short", "竹林小道");
	set("long", @LONG
走到这里，你突然感觉眼前一亮，一条小路出现在你的眼前，
你的头脑顿时恢复了清醒，一座小镇隐隐约约就在前面。
LONG
	);
        set("outdoors", "houjizhen");

	set("exits", ([
		"south" :  __DIR__"zhulin2",
		"north" :  __DIR__"xiaolu1",
	]));

	setup();
	replace_program(ROOM);
}
