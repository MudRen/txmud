// Room: /d/huanggong/daolu4.c

inherit ROOM;

void create()
{
        set("short", "道路");
        set("long", @LONG
你走在长长的过道中，往东是文华殿，向北走就到了文渊殿
，长长的过道中，纯金铸成的长灯架挂着一排饰丽的宫灯！入夜
之后灯火辉煌！十分美丽。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"taihm",
  "east" : __DIR__"daolu5",
  ]));
        set("no_clean_up", 0);
        set("outdoors", "huanggong");

        setup();
        replace_program(ROOM);
}