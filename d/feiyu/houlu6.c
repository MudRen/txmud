// Room: /wiz/louth/a/houlu6.c

inherit ROOM;

void create()
{
	set("short", "松徽亭");
	set("long", @LONG
这里是绯雨楼中最不为人知的角落，也是吴若尘的清修之地。
他经常在这里独自一人吹奏“清懿幽”，好象现在也可以听到那
美妙的萧音在耳边回响。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "southeast" : __DIR__"houlu5",
]));
        set("objects", ([
                __DIR__"npc/huanerjj": 1,
        ]) );

	set("outdoors","feiyu");
	setup();
}

int valid_leave(object me,string dir)
{
	if( (dir == "southeast") && me->query_temp("mark/huaner_pu") )
		me->delete_temp("mark/huaner_pu");
	return ::valid_leave(me,dir);
}
