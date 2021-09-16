// Room: /d/huanggong/jiaotd.c

inherit ROOM;

void create()
{
        set("short", "交泰殿");
        set("long", @LONG
这里是皇家保存玉玺的地方。在西面的墙角放着一个木制的
柜子，远远望去，你可以看到柜子上存放了二十几个金制的盒子
，里面存放的大概就是历代帝王用过的玉玺。表面看起来没有什
么戒备。实际上大殿内机关重重，一不小心就有生命的危险，劝
你还是赶快离开这里。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"qianqg",
  "north" : __DIR__"kunng",
]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}