// Room: /d/huanggong/ningsg.c

inherit ROOM;

void create()
{
        set("short", "宁寿宫");
        set("long", @LONG
这里是贵妃娘娘为皇上祈求长寿的地方。宽敞明亮的大殿。
一对黄金打造的长明灯，静静的放在那里，灯火通明。案几上
一尘不染，说明这里经常有人打扫。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"huangjd",
]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

