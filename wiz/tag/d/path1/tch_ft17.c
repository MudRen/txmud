// /d/path1/tch_ft17.c

inherit ROOM;
void create()
{
        set("short", "仇参岗");
        set("long", @LONG
这里就是仇参岗。据说当年有一个姓仇的参客看到“七珠花
参”后不幸被毒蛇咬伤，逃到此地终于身亡。后来一些参客曾由
此上山继续找寻，却一直未果。西北边有一片树林，里面到处都
是蛇。向东不远，就是奉天城了。
LONG
        );

        set("exits", ([
                "west" : __DIR__"tch_ft16",
                "east" : __DIR__"tch_ft18",
                "northwest" : "/wiz/tag/d/gaibang/path1_maze/entry",
        ]));

        set("outdoors","path1");

        set("objects",([
        "/wiz/tag/d/gaibang/npc/snake_dan_dealer" : 1,
        ]));

        setup();

        replace_program(ROOM);
}
