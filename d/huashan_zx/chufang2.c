// Room: cufang2.c by pian

inherit ROOM;
void create()
{
	set("short","厨房");
	set("long",@LONG
这里靠墙盘着两孔大灶，屋里烟熏火燎，还是先出去等吧。
LONG
);
	set("exits", ([ /* sizeof() == 2 */
	"west" : __DIR__"chufang1",
]));
	setup();
	replace_program(ROOM);
}