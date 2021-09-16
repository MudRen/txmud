// Room: /u/w/wangs/b/kai30.c

inherit ROOM;

void create()
{
	set("short", "民居");
	set("long", @LONG
这是一户普通人家，男主人在虹日路开了一家小店铺，所以
日子过得倒还殷实。两名孩童正在院子里扑蝶为乐，一个青衣妇
人坐在窗前，她面带微笑，走针如飞，将孩子们天真童稚之态绣
入画绢之中。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"kai29",
]));
        set("objects",([
        __DIR__"npc/zfuren": 1,
        __DIR__"npc/zhangnn": 1,
]));

	setup();
	replace_program(ROOM);
}
