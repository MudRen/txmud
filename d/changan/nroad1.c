// /d/changan/nroad1  麒祥街

inherit ROOM;

void create()
{
        set("short", "麒祥街");
        set("long", @LONG
这里是长安城的北大街的最东面，这里好像并不太热闹，给
人一种肃杀的感觉。街上偶尔匆匆走过几个带兵器的武者，一般
的老百姓从来不到这个地方来。麒祥街由这里向西延伸，东面是
连德路，北面是一家兵器铺。
LONG
        );

	set("exits", ([
		"north"		  : __DIR__"weapony",
                "west"            : __DIR__"nroad2",
                "east"            : __DIR__"eroad8",
]) );

	set("outdoors","changan");

        setup();
	replace_program(ROOM);
}
