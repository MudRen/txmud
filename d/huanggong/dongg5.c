// Room: /d/huanggong/dongg5.c

inherit ROOM;

void create()
{
        set("short", "沁芳亭");
        set("long", @LONG
通过走道你来到了沁芳亭。亭子的两旁摆设了许多奇花异草。
各具特色，空气中弥漫着淡淡的幽香。亭柱上写的有字，字体龙
飞凤舞，一看就知道出自名家之手。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"dongg2",
  "west" : __DIR__"dongg4",
]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}