// /d/changan/whroad1  西环路

inherit ROOM;

void create()
{
        set("short", "西环路");
        set("long", @LONG
这里的长安城的西环路，是长安城四条主街道之一，这里由
于紧邻皇宫，又是各衙门的所在地所以时时都戒备森严，一般老
百姓都不愿来这里。西面是狱神庙，是关押犯官的地方，门前冷
冷清清。西环路由此向南延伸，北面是北环路。
LONG
        );

	set("exits", ([
		"west"		   : __DIR__"yushen",
                "north"            : __DIR__"nhroad4",
                "south"            : __DIR__"whroad2",
]) );

	set("outdoors","changan");
	setup();
	replace_program(ROOM);
}
