// Room: /u/w/wangs/b/kai140.c

inherit ROOM;

void create()
{
	set("short", "衙门");
	set("long", @LONG
开封城最高的行政机构　这里负责管理城里的大事小情。无
论是偷鸡摸狗的小贼，还是放火杀人的强盗，都会在这里受到应
有的处罚。大堂上方有一幅长匾，写着“清正廉名”四个烫金大
字。一张大公案后面坐着知府大人。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"kai138",
]));
        set("objects",([
        __DIR__"npc/zhifu": 1,
]));

	setup();
	replace_program(ROOM);
}
