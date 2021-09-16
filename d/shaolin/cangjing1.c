// Room: /d/shaolin/cangjing1.c

inherit ROOM;

void create()
{
	set("short", "藏经阁一层");
	set("long", @LONG
这里是少林寺的藏经阁一层，一层多是一些极为普通的佛经，
如《金刚经》、《华莲经》，每天的早课晚课时，从这里请经，
功课完毕后，再将经送回藏经阁。而二楼是多是一些深奥的佛经
和武功秘义。有几个武艺高强的僧兵在这里守卫着。向西是青石
的甬道，从楼梯上二楼是藏经阁二楼。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "up" : __DIR__"cangjing2",
  "west" : __DIR__"yongdao3",
]));

	set(SAFE_ENV,1);
	set("objects", ([
	__DIR__"npc/seng_bing" : 2,
]));

	setup();
}

int valid_leave(object me,string arg)
{
	if( arg =="up"
	&& !wizardp(me)
	&& (me->query("class") != "shaolin"
	|| !me->query("is_bonze")) )
		return notify_fail("僧兵喝道：“本寺规定非本寺出家弟子不得进入藏经阁二楼！”\n");

	else
		return ::valid_leave(me,arg);
}