// Room: /d/huashan/luoyanpo.c

inherit ROOM;

void create()
{
        set("short", "落雁坡");
        set("long", @LONG
这里是一个不太大的陡坡，坡上树高林密，南飞的大雁常在
这里稍作停留。东边是华山派的铸剑池。据说紫霞宫花重金请了
一个疯疯颠颠的人在这里铸剑，不过据说他的剑倒是很好卖。
LONG
        );

        set("exits", ([ /* sizeof() == 4 */
  "westdown" : __DIR__"xiaolu9",
  "eastdown" : __DIR__"zhujian",
]));

	set("outdoors", "huashan");
	set("objects", ([
	__DIR__"npc/yetu":2,
]));

        setup();
        replace_program(ROOM);
}

