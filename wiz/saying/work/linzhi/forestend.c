//forestend.c 青藏高原通向中原的原始森林迷宫尽头。
inherit ROOM;
void create()
{
        set("short","森林尽头");
        set("long", @LONG
在森林里走了许久，又转过几个小弯，忽然之间豁然开朗，
你已经来到了林芝镇的前方，回头望望身后绵延不绝的原始大森
林，你舒了一口气：总算又见到人烟了。
LONG
        );
        set("exits", ([
        "north":__DIR__"forest9",
        "south":__DIR__"lz_eroad5",
]));
        setup();
}
