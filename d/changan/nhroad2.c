// /d/changan/nhroad2  北环路

inherit ROOM;

void create()
{
        set("short", "北环路");
        set("long", @LONG
这里是长安城内环路北面，内环路由于紧邻皇宫内城加之又
是各衙门的所在地所以禁卫森严，不时有巡城军队从这里走过。
从这里你可以看到南边的金水桥，过个桥就是皇宫大内的门口
了，向北走一段，你可以从北门出长安。
LONG
        );
       set("exits", ([
                "west"             : __DIR__"nhroad3",
                "north"            : __DIR__"nroad9",
                "south"            : __DIR__"jingsq2",
                "east"             : __DIR__"nhroad1",
]) );
       set("outdoors","changan");
        setup();
	replace_program(ROOM);
}