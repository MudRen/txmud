// /d/changan/nhroad4  北环路

inherit ROOM;

void create()
{
        set("short", "北环路");
        set("long", @LONG
这里是长安城的玄武大街，是长安四条主街道之一，两边的
店铺很少，丞相府就离这里不远了，所以这里的锦衣侍卫也有不
少。从这里路过总得战战兢兢的，随时可能有人盘问你。北环路
由这里沿着皇宫城墙向东延伸。
LONG
        );

       set("exits", ([
                "south"            : __DIR__"whroad1",
                "east"             : __DIR__"nhroad3",
]) );

	set("outdoors","changan");
        setup();
	replace_program(ROOM);
}
