// /d/changan/nroad4  北安大道

inherit ROOM;

void create()
{
        set("short", "北安大道");
        set("long", @LONG
这是长安城北大街的正中，这条纵向的大街，象其它几条大
街一样，也有它专门的用途，这个门，很早以前叫做得胜门，是
出征打仗归来的将士们所走门。在这里做生意的人很多，好不热
闹。从这里向东和向西是长安的麒祥街，向北是长安城的北门，
向南一直走就是北环路了。
LONG
        );

	set("exits", ([
                "west"            : __DIR__"nroad5",
                "north"           : __DIR__"ndoor",
                "south"           : __DIR__"nroad9",
                "east"            : __DIR__"nroad3",
]) );

	set("outdoors","changan");
        setup();
	replace_program(ROOM);
}
