// Room: /d/tangmen/gd1.c

inherit ROOM;

string go_enter(object me)
{
	if( me && (me->query("class") == "tangmen") )
		return __DIR__"dmq";

	else
		return __DIR__"shulin/entry";
}

void create()
{
	set("short", "石子小路");
	set("long", @LONG
这是一条石子小路蜿蜒在青青的绿草地中，可能是经常有人
走动，路上的石子被磨得非常光亮，仔细看上面还有用彩色的石
子拼出的一个“唐”字。路边竖着一块小石碑(bei)。
LONG
	);

	set("item_desc", ([
	"bei" : "\n唐家城堡\n闲人莫入\n\n",
	"石碑" : "\n唐家城堡\n闲人莫入\n\n",
]));

	set("exits", ([
  "north" : (: go_enter :),
  "south" : __DIR__"xiaoyuan",
]));

	set("outdoors", "tangmen");
	setup();
}

int valid_leave(object ob,string dir)
{
	object *inv;

	if(!ob || !stringp(dir))
		return 1;

	if( userp(ob) && (dir == "north") )
	{
		inv = filter_array(all_inventory(ob), (: $1->is_character() :));

		if(sizeof(inv))
			foreach(object n in inv)
				if(!n->move(this_object()))
					return notify_fail("突然一声呼哨，前面打过来一只飞镖，你赶紧停住身行闪在了一旁。\n");
	}

	return ::valid_leave(ob,dir);
}
