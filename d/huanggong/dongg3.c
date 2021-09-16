// Room: /d/huanggong/dongg3.c

inherit ROOM;

void create()
{
        set("short", "回廊");
        set("long", @LONG
你走在一条长廊上，两旁都是庭台堂院，廊上弥漫著一股香
郁的气息，长廊向东南方延伸而去。北边是一间偏厅，东边是东
宫花园，淡淡的香气从那个方向飘过来。
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
  "southeast" : __DIR__"donggdm",
  "east" : __DIR__"dongg4",
  "north" : __DIR__"dongg1",
]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}