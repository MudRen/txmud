// Room: /d/shaolin/cangjing2.c

#include <room.h>

inherit ROOM;

void create()
{
	set("short", "藏经阁二层");
	set("long", @LONG
这里就是藏经阁二楼了，由于此地收藏的是佛门的经典及各
种武功的秘籍，所以历来是少林寺的禁地。不是少林寺的出家弟
子决不能进入此地修习佛法及武功。靠墙一排巨大的书架(shujia)
摆满了经书(jing shu)。
LONG
	);

 
	set("exits", ([ /* sizeof() == 2 */
  "down" : __DIR__"cangjing1",
  "east" : __DIR__"cangjing3",
  "west" : __DIR__"readroom",
]));

	set("NORIDE", 1);
	set(SAFE_ENV,1);
	set("objects", ([
	__DIR__"npc/huichi" : 1,
]));

	setup();
	create_door("east", "木门", "west", DOOR_CLOSED,LOCKED,__DIR__"npc/obj/cangjing_key");
}

void init()
{
	add_action("do_get","get");
}

int do_get(string arg)
{
	string what,where;
	object shu;

	if(!arg || sscanf(arg,"%s from %s",what,where) != 2)
		return 0;

	if((what == "jing shu" || what == "js") && where != "shujia")
	{
		write("你要从什么里面拿经书？\n");
		return 1;
	}
	if( where == "shujia" && (what != "jing shu" && what != "js"))
	{
		write("你要从书架上拿什么？\n");
		return 1;
	}
	if( where != "shujia" || (what != "jing shu" && what != "js"))
		return 0;
	
	shu = new(__DIR__"npc/obj/jingshu");

	if(!shu->move(this_player()))
		shu->move(this_object());

	message_vision(sprintf("$N从书架上拿起一本%s。\n",shu->name()),this_player());
	return 1;
}

int valid_leave(object me,string dir)
{
	object *obs;

	if(!me)
		return 0;

	if(dir == "down")
	{
		if(sizeof(filter_array(deep_inventory(me),(: $1->is_shaolin_book() :))))
			return notify_fail("晦痴伸手拦住你说道：“奉方丈法谕，武学典籍不可携出藏经阁。”\n");
	}

	if( (dir == "east")
	&& ( me->query("class") != "shaolin"
	|| !me->query("family/can_study_yijin")) )
		return notify_fail("晦痴伸手拦住你说道：“未得方丈许可不可进入此屋！”\n");

	if(dir == "west")
	{
		obs = filter_array(all_inventory(me),(: $1->is_character() :));
		if(sizeof(obs))
			return notify_fail("晦痴伸手拦住你说道：“背着个大活人去诵经室作什么！”\n");
	}
	return ::valid_leave(me,dir);
}
