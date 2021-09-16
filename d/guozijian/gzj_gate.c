// Room: /d/guozijian/gzj_gate.c 

inherit ROOM;

void create() 
{ 
	set("short", "国子监");
	set("long", @LONG
这里是国子监的正门，门的上方用蓝底金字写者“集贤门”，
字的旁边刻有精美的图案，门的右方，在墙上贴了一块汉白玉，
上面刻着“国子监”三个大字，据说是皇帝的御笔。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"north" : __DIR__"yongdao1",
		"south" : "/d/changan/nhroad1",
]));
	set("objects", ([
		__DIR__"npc/soldier"	: 2,
	]));

	setup();
}

int valid_leave(object me, string dir)
{
	object *objs;
	int i,n;

	if ( (dir != "north" && dir != "n") || wizardp(me) )
		return ::valid_leave(me,dir);

	objs = deep_inventory(me);
	n = sizeof(objs);

	if(n)
	for(i=0;i<n;i++)
	{
		if( objs[i]->is_weapon())
		{
			message("vision", "士兵喝道：慢著，进入国子监不许带兵刃！\n", this_object());
			return notify_fail("士兵挡住了你的去路。\n");
		}
	}

	
	return ::valid_leave(me,dir);
}
