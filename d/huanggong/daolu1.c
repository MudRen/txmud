// Room: /d/huanggong/daolu1.c

inherit ROOM;

void create()
{
        set("short", "道路");
        set("long", @LONG
你走在长长的过道中，往南是南门，北走就到了午门，长长
的过道中，纯金铸成的长灯架挂着一排饰丽的宫灯！入夜之后灯
火辉煌！十分美丽。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"nanm",
  "north" : __DIR__"wumen",
]));
        set("no_clean_up", 0);
        set("outdoors", "huanggong");
        setup();
        replace_program(ROOM);
}