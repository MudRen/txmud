// Room: /d/changan/compare2.c 比武场

inherit ROOM;

void create()
{
        set("short", "长安比武场");
        set("long", @LONG
这里长安城的比武场，一进来，你会看到四个斗大的金字“
强身健体”。由此可见，武术的精华并不在于杀戳，而是强健身
体的武德。当中一个很大擂台，四周竖着许多旗帜，虽然没有风，
可是这里仍然可是听到旗子的“哗哗”声，四下的武士们威严肃
穆，使你感觉热血沸腾，不由也想上台比试比试。由此向南就是
南大街。
LONG);
        set("exits", ([
                "south" : __DIR__"sroad1",
        ]));
	set("user_compare",1);
        setup();
}

