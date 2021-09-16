// chengxf  丞相府

inherit ROOM;

void create()
{
        set("short", "丞相府大门");
        set("long", @LONG
这里是当朝丞相的府院，你抬头黑底金漆的大匾“丞相府”
三个大字，映入你的眼帘。两边两只威猛的石狮至少比一般的要
大出一倍，两边立着两个肃穆的武士，如果你稍有什么不轨，他
们可能就会出手。这里向南是北环路。
LONG
        );
       set("exits", ([
                "north"             : __DIR__"chengxf1",
                "south"             : __DIR__"nhroad3",
]) );

	set("outdoors","chengxf");
	set("cannot_build_home",1);
	set(SAFE_ENV,1);

	set("objects",([
	__DIR__"npc/jiading" : 2,
]));

	setup();
}

int valid_leave(object me,string dir)
{
	if(dir == "south" || dir == "s")
	{
		if(::valid_leave(me,dir))
		{
			me->delete_temp("chengxf_killer");
			return 1;
		}
		else
			return 0;
	}

	return ::valid_leave(me,dir);
}