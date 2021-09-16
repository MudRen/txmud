// Room: /d/huanggong/qinad.c

inherit ROOM;

void create()
{
        set("short", "钦安殿");
        set("long", @LONG
这里就是皇上平时休闲娱乐的地方。闲暇的时候找来一两名
王公大臣在这里下棋聊天，因为这里不必太拘君臣之礼，所以，
可以询问一些百姓的问题，这也是当今皇上建造这个宫殿的意图
，看起来当今皇上还是一位好皇帝。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"yuhy",
  "north" : __DIR__"shenwm",
]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

