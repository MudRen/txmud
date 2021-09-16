// /d/changan/sroad6  华瑞街

inherit ROOM;

void create()
{
        set("short", "华瑞街");
        set("long", @LONG
这里是长安城的南大街，走到这里，人已经不是很多了，偶
然有几个牵着牲口的人匆匆的走过。看来在城门附近的生意比较
好做，而越是离城门远，做生意的人越少。不过你走这安静的大
街上，感觉却又是一番不同。由此向西和向东，仍然是南大街。
LONG
        );

	set("exits", ([
		"north" : __DIR__"zahuopu",
                "west" : __DIR__"sroad5",
                "east" : __DIR__"sroad7",
]) );

	set("outdoors","changan");

	set("objects",([
	__DIR__"npc/out_vendor" : 1,
]));

        setup();
	replace_program(ROOM);
}
