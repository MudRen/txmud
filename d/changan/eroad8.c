// /d/changan/eroad8  连德街

inherit ROOM;

void create()
{
        set("short", "连德街");
        set("long", @LONG
这里是长安城的最东北角，人们说这里是黑道交易最红火的
地方，一点儿也不为过，买小道消息、雇佣杀手的人们不约而同，
聚集在这里。人们在这里说着暗语，打着道上的手势，如果你不
是他们其中的一员，你来到这里，会跟本不知所云。从这里向南
是长安城的东大街，而从这里向西就属于长安城的北大街了。
LONG
        );

	set("exits", ([
                "west"            : __DIR__"nroad1",
                "south"           : __DIR__"eroad7",
]) );

	set("outdoors","changan");
        setup();
	replace_program(ROOM);
}
