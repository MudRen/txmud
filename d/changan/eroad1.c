// /d/changan/eroad1  连德街

inherit ROOM;

void create()
{
        set("short", "连德街");
        set("long", @LONG
这里是东大街的南边，路两边的生意人和行人不算很多，东
面不远是一座土地庙，总有一些上香还愿的善男信女从这里路过，
当然其中不乏达官贵人和他们的子女。也有一些行脚的和尚在这
附近化斋，三三两两的乞丐常出现在这里，倒也成了这里的一种
景观。
LONG
        );
       set("exits", ([
                "west"           : __DIR__"badroom",
                "south"           : __DIR__"sroad8",
                "north"           : __DIR__"eroad2", ]) );
       set("outdoors","changan");

        set("objects",([
        __DIR__"npc/cleaner" : 1,
]));

        setup();
	replace_program(ROOM);
}
