// /d/changan/whroad4  西环路

inherit ROOM;

void create()
{
        set("short", "西环路");
        set("long", @LONG
这里是长安城的西环路的最南端，向东望去是南环路，由于
近临紫禁城徘徊在附近的锦衣卫很多，两边红墙碧瓦，却静悄悄
的听不到一点声音。
LONG
        );

       set("exits", ([
                "north"            : __DIR__"whroad3",
                "east"             : __DIR__"shroad1",
 ]) );

	set("outdoors","changan");
        setup();
	replace_program(ROOM);
}
