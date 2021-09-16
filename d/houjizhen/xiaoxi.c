// xiaoxi.c
// by dicky

inherit ROOM;

void create()
{
        set("short", "山中小溪");
        set("long", @LONG
在山路的旁边出现了一条小溪。周围安静极了，只有小河流水在孱孱作
响。一些口渴的动物在溪边喝水，远处好象有一些看不清模样的动物也在溪
里玩闹。南面是一条上山的路，正北面依稀有一片竹林通向深处。
LONG
        );
        
	set("outdoors", "houjizhen");
	set("resource/water", 1);

        set("exits", ([           
		"northup" : __DIR__"zhulin1",
                "southup" : __DIR__"shanlu4",
		"westup" : __DIR__"xiaoxi1",
        ]));


        setup();
	replace_program(ROOM);
}
