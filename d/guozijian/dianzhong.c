// Room: /d/guozijian/dianzhong.c 
 
inherit ROOM; 
 
void create() 
{ 
	set("short", "辟雍殿内");
	set("long", @LONG
在辟雍殿的中心，有一个圆形高台，上面放着一张龙纹椅和
一张龙头案，圆台的四周，铺着红色的地毯，每隔一段距离就摆
一个园垫。殿内横匾上写着“雅涵于乐”，两旁竖额“金元明宅
于兹，天邑万年今大备，虞夏殷阙有间，周京四学古堪循”。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
		"east"  : __DIR__"by_east",
		"south" : __DIR__"biyong",
		"west"  : __DIR__"by_west",
		"north" : __DIR__"by_north",
]));

	setup();
}

void init()
{
	add_action("do_walk", "walk");
}

void check_trigger()
{
	if( (int)query("x_trigger")==3
	&&	(int)query("y_trigger")==-2)
	{
		message_vision("地板忽然发出轧轧的声音，$N一不留神掉了下去。\n",
			this_player() );
		this_player()->move(__DIR__"mishi");
		delete("x_trigger");
		delete("y_trigger");
	}
}

int do_walk(string arg)
{
	string dir;
	int num;
	string cdir;
	if( !arg || arg=="" ) {
		message_vision("$N走上圆形高台，向四周看了看，好象在计算着什么。\n",this_player());
		set("x_trigger",0);
		set("y_trigger",0);
		return 1;
	}
	if( sscanf(arg, "%s %d", dir,num)==2 ) {
		switch(dir) {
		    case "east" :
			cdir = "东";
			add("x_trigger", num);
			break;
		    case "south" :
			cdir = "南";
			add("y_trigger", num);
			break;
		    case "west" :
			cdir = "西";
			add("x_trigger", -1*num);
			break;
		    case "north" :
			cdir = "北";
			add("y_trigger", -1*num);
			break;
		    default :
			return notify_fail("你要往那里走啊。");
		}
		
		message_vision("$N往"+cdir+"走了"+chinese_number(num)+"步。\n", this_player());
		check_trigger();
		return 1;
	}
}


void reset()
{
	::reset();
	delete("x_trigger");
	delete("y_trigger");
}
