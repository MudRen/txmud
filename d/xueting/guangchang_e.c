// Room: /d/snow/square_e.c
inherit ROOM;
void create()
{
        set("short", "广场东侧");
        set("long", @LONG
这里是雪亭镇广场东边，再往东是一条僻静的巷子，西边有一
株高大的榕树，南边是一家打铁铺子，不过店门不在这一边。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
                "east" : __DIR__"epath",
                "west" : __DIR__"guangchang",
]));
        set("outdoors", "xueting");
        setup();
        replace_program(ROOM);
}
