// Room: /d/huanggong/daolu2.c

inherit ROOM;

void create()
{
        set("short", "道路");
        set("long", @LONG
你走在长长的过道中，往西是武英殿和南薰殿，长长的走道
中, 纯金铸成的长灯架上挂了一排饰丽的宫灯! 入夜之後灯火辉
煌! 十分美丽．向北就是大内的御膳房。
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"taihm",
  "west" : __DIR__"daolu3",
  "north" : __DIR__"yusf",
]));
        set("no_clean_up", 0);

	set("outdoors", "huanggong");

        setup();
        replace_program(ROOM);
}