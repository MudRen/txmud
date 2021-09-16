// /d/changan/whroad3  西环路

inherit ROOM;

void create()
{
        set("short", "西环路");
        set("long", @LONG
这里的长安城的西环路，是长安城四条主街道之一。这里由
于紧邻皇宫，所以时时都戒备森严，一般老百姓都不愿来这里。
西面就是京师衙门的所在地，身着各式官服的人出出进进，旁边
靠墙停着一排官轿，轿夫们在一起说笑聊天。
LONG
        );

	set("exits", ([
		"west"		   : __DIR__"yamen",
                "north"            : __DIR__"whroad2",
                "south"            : __DIR__"whroad4",
]) );

	set("outdoors","changan");
        setup();
	replace_program(ROOM);
}