//uptower_e.c 头人府哨塔。
inherit ROOM;
void create()
{
        set("short","哨塔上");
        set("long", @LONG
这里是头人府的哨塔。哨塔完全是头人威严的体现，当然也
有防卫的功效，登高一望，如果有敌人来犯，绝对逃不过这里的
观察。
LONG
        );
        set("exits", ([
        "down":__DIR__"tower_e",
]));
        setup();
}
