// Room: /u/w/wangs/b/kai7.c

inherit ROOM;

void create()
{
	set("short", "钓鱼池");
	set("long", @LONG
这儿是一个专供游人钓鱼的池塘。水很清，你可以看到水底
铺满了细纱，绿色的水草地水波荡漾中婆娑起舞。钓鱼也是一门
技巧，它可以陶冶人的性情，煅练人的耐力及反应速度，所以长
久以来人们已将钓鱼发展成一种专门的学问了。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"kai4",
]));

        set("objects",([
        __DIR__"npc/nian" : 1,
        __DIR__"npc/laozhe" : 1,
]));

	set("outdoors","kaifeng");
	setup();
	replace_program(ROOM);
}
