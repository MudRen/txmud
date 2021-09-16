// whroad2  西环路

inherit ROOM;

void create()
{
        set("short", "西环路");
        set("long", @LONG
这里的长安城的西环路，是长安城四条主街道之一。这里由
于紧邻皇宫，又是各衙门的所在地所以时时都戒备森严，一般老
百姓都不愿来这里。西面是西安大道直通长安城的西门。
LONG
        );

	set("exits", ([
                "west"             : __DIR__"wroad9",
                "north"            : __DIR__"whroad1",
                "south"            : __DIR__"whroad3",
]) );

	set("outdoors","changan");

	set("objects",([
	NPC_DIR"xunpu" : 2,
]));

        setup();
	replace_program(ROOM);
}
