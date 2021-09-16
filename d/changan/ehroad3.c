// ehroad3  东环路

inherit ROOM;

void create()
{
        set("short", "东环路");
        set("long", @LONG
这里是长安城的东环路，是长安四条主街道之一，由于是紧
邻皇城的内环路，所以戒备森严，巡捕、御林军来往不断。东面
是户部衙门，也许由于部务和百姓生活息息相关，这里到是经常
有一些平民百姓出入。
LONG
        );
	set("exits", ([
		"east" : __DIR__"hubu",
		"south" : __DIR__"ehroad2",
		"north" : __DIR__"ehroad4",
]) );

	set("outdoors","changan");
	setup();
}
