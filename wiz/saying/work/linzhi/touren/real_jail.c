//real_jail.c 牢房深处。
inherit ROOM;
void create()
{
        set("short","牢房");
        set("long", @LONG
这里是一间小小的牢房，墙壁上挂着点点水珠，非常的潮
湿，这里简直不是人住的地方，如果有谁被关在这里可真是倒
霉之极了。
LONG
        );
        set("exits", ([
        "west":__DIR__"jail/exit",
]));
        setup();
}
