// /d/changan/nroad5  麒祥街

inherit ROOM;

void create()
{
        set("short", "麒祥街");
        set("long", @LONG
这里是长安城的北大街，大街的两旁人群熙熙攘攘，这里是
长安最繁华的地段了。老的长安城的百姓总是说：“生意要想旺
兴，北街斗金日进”。南面是一家赌馆，不时传来吆五喝六的叫
喊声。
LONG
        );

	set("exits", ([
                "west"            : __DIR__"nroad6",
                "south"           : __DIR__"duchang",
                "east"            : __DIR__"nroad4",
]) );

	set("outdoors","changan");

	set("objects",([
	__DIR__"npc/dutu" : 1,
]));

        setup();
	replace_program(ROOM);
}
