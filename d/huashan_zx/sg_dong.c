// Room: /d/huashan/sg_dong.c

inherit ROOM;

void create()
{
        set("short", "思过洞");
        set("long", @LONG
这是一个天然的山洞，洞里倒也干爽。洞的深处放有一些干
草，像是有人在这里休息过。
LONG
        );
        set("no_clean_up", 0);
        set("exits", ([ /* sizeof() == 1 */
  "out" : __DIR__"siguoya",
]));

        setup();
        replace_program(ROOM);
}
