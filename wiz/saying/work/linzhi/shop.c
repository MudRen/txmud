//shop.c 林芝村的杂货铺
inherit ROOM;
void create()
{
        set("short", "杂货铺");
        set("long", @LONG
这是一间小小的店铺，里面的陈设相当的简单，对面是一个
柜台，柜台边放着一把椅子。柜台后面对这各式各样的小商品，
看来是一间卖杂货的店铺。
LONG
        );
        set("exits", ([
        "south" : __DIR__"lz_eroad3",
]));
        set("objects",([
        __DIR__"npc/shopper" : 1,
]));
        setup();
}
