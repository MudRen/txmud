//temple2.c 德木寺大殿。
inherit ROOM;
void create()
{
        set("short", "大殿");
        set("long", @LONG
这里是德木寺的大殿，梵唱阵阵，香烟缭绕，不过却找不到
十分出众的僧侣，似乎众生一体一般。你想起有人说德木寺的嘉
措大师是一位有道高僧，现在毫无端倪，心里不禁有点失落。大
殿正中的巨大香炉似乎也有几百年的历史了。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
        "east":__DIR__"t_right2",
        "west":__DIR__"t_left2",
        "north":__DIR__"temple3",
        "south":__DIR__"temple1",
]));
        set("item_desc",([ /* 降杀气*/
        "香炉":"一个巨大的香炉，里面插(cha)了不少高香。\n",
]));
        set("objects",([ /* 招徕生意*/
        __DIR__"npc/kid_lama":1,
]));
        setup();
}
