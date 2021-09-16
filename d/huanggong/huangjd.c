// Room: /d/huanggong/huangjd.c

inherit ROOM;

void create()
{
        set("short", "皇极殿");
        set("long", @LONG
这里就是皇极殿，是皇子们读书学习的地方，差不多每月皇
上都要来这里督促皇子们好好读书，以便将来能更好的治理国家
。从这里向北就到了宁寿宫。
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"zhaig",
  "south" : __DIR__"jiulb",
  "north" : __DIR__"ningsg",
]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}