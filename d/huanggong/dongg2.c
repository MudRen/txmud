// Room: /d/huanggong/dongg2.c

inherit ROOM;

void create()
{
        set("short", "九曲回廊");
        set("long", @LONG
进入大门后，接著你走进九曲回廊。曲曲折折的回廊中，纯
金制成的长灯架上挂了一排饰丽的宫灯！在一柱柱雕饰华丽的长
柱上雕刻画着许多彩绘的图形，美不胜收。走道两旁摆设了许多
奇花异草，空气中弥漫一种淡淡的香 气。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "southwest" : __DIR__"donggdm",
  "north" : __DIR__"dongg5",
]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

