// Room: /d/hangzhou/linchild.c

inherit ROOM;

void create()
{
	set("short", "少爷卧房");
	set("long", @LONG
这里是林家少爷的卧房，林家少爷自小溺爱，长大后更是顽
劣异常，仗着家里有钱，横行乡里，无恶不作。屋里陈设杂乱无
章，东面的窗户边摆了两个鸟笼。
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"linpath4",
]));

	set("objects",([
	__DIR__"npc/lin_sy" : 1,
]));

	setup();
	replace_program(ROOM);
}
