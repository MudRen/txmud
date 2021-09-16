// Room: /d/huanggong/daolu3.c

inherit ROOM;

void create()
{
        set("short", "道路");
        set("long", @LONG
你走在长长的过道中，往西是英武殿，向北走就到了南薰殿
，长长的过道中，纯金铸成的长灯架挂着一排饰丽的宫灯！入夜
之后灯火辉煌！十分美丽。
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"daolu2",
  "west" : __DIR__"wuyd",
  "north" : __DIR__"nanxd",
]));

	set("no_clean_up", 0);
	set("outdoors", "huanggong");

        setup();
        replace_program(ROOM);
}