// Room: /d/huashan/zhujian.c

inherit ROOM;

void create()
{
        set("short", "铸剑池");
        set("long", @LONG
这里就是华山派的铸剑池。四周整齐地码着几人高的柴碳，
中央一个火炉冒着几尺高的火苗。几个华山派的弟子在这里忙着
填柴加碳。几把通红的剑坯插在火中。炉边还有一只一人多高的
大水缸，里面装着黑糊糊的液体。东边是一间小木屋，是铸剑师
的住所。
LONG
        );

	set("exits", ([
		"north" : __DIR__"tieku",
		"westup" : __DIR__"luoyanpo",
		"enter" : __DIR__"muwu",
]));

	set("NONPC",1);

        set("outdoors", "huashan");
        set("objects", ([
	__DIR__"npc/zhujianshi":1,
]));
        setup();
        replace_program(ROOM);
}

