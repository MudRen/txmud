// /d/hangzhou/eatroom.c

inherit ROOM;

void create()
{
        set("short", "小吃店");
        set("long", @LONG
这是长安街边的一个小铺子，卖的无非是一些糖果，点心之
类的东西，不过听说这里的老板娘自酿的豆浆颇有特色。
LONG
        );
        set("exits", ([ 
            "north"   : __DIR__"changane2",
]));

	set("objects",([
	__DIR__"npc/xiaochi_boss" : 1,
]));

        setup();
        replace_program(ROOM);
}

