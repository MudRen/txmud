// Room: /d/huanggong/baohd.c

inherit ROOM;

void create()
{
        set("short", "保和殿");
        set("long", @LONG
您现在来到的地方就是保和殿了．这里是皇上殿试的地方，
每个读书的人都梦想能在这里检验一下自己的学识，可是能有这
样机会人太少了．大殿的两边整齐的摆放着两行桌子，做为考试
之用，虽说没有隔断但是殿试的时候也没有作弊的。

　　大殿的墙上挂着一幅御笔亲题的字：

	江山之固 在德不在险

LONG
        );
        set("exits", ([ /* sizeof() == 3 */
  "northwest" : __DIR__"longzm",
  "south" : __DIR__"zhonghd",
  "north" : __DIR__"qianqg",
]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}