// Room: /d/huanggong/xig5.c

inherit ROOM;

void create()
{
        set("short", "冷宫");
        set("long", @LONG
这里就是皇帝惩罚妃子的地方，一旦有妃子被打入冷宫，就
代表她再难有重见龙颜之日。在这里的妃子们天天都以泪洗面..
你一走进这里，一种莫名的悲凉袭上心头。眼前的一切使你想起
了伤心的往事，你几乎哭(cry)了出来。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"xig6",
]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}