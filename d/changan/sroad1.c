// /d/changan/sroad1  华瑞街

inherit ROOM;

void create()
{
        set("short", "华瑞街");
        set("long", @LONG
这是长安城的南大街，随着南大街离城门越来越远，人也渐
渐的少多了。气氛已远不如刚才热闹，偶而传来一两声，走街串
巷的小贩的吆喝声。这里可以说是南大街西面的尽头了，东边是
南大街，往西却属于西大街了。北边有一个比武场。
LONG
        );
       set("exits", ([
                "west"           : __DIR__"wroad8",
                "north"          : __DIR__"compare2",
                "east"           : __DIR__"sroad2", ]) );
       set("outdoors","changan");
        setup();
	replace_program(ROOM);
}
