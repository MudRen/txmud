// Room: /d/huanggong/zhonghd.c

inherit ROOM;

void create()
{
        set("short", "中和殿");
        set("long", @LONG
这里是天子接受朝拜的地方，每当临国前来使节觐见，都要
在这里等候皇上的接见这里布置的富丽堂皇，充分体现了皇家的
雍容华贵与尊严。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"taihd",
  "north" : __DIR__"baohd",
]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

