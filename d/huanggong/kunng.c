// Room: /d/huanggong/kunng.c

inherit ROOM;

void create()
{
        set("short", "坤宁宫");
        set("long", @LONG
这里就是皇帝大婚时和皇后洞房的地方里面布置的富丽堂皇
。地下铺的是由波斯古国进贡而来的地毯，西面是皇上的御榻，
清一色的黄色，体现出帝王家的尊严。榻前摆放着一张八仙桌，
桌上一套纯金的茶具，闪闪发光。从这里向北走就来到了御花园。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"jiaotd",
  "north" : __DIR__"yuhy",
]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}