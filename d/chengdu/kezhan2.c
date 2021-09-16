// Room: /d/chengdu/kezhan2.c

#include <room.h>
inherit ROOM;

protected int have_person(object room)
{
	if(!room)
		return 0;
        return sizeof(filter_array(all_inventory(room),(: userp($1) && !wizardp($1) :)));
}

void create()
{
	set("short", "客栈二楼");
	set("long", @LONG
你正走在客店二楼的走廊上，可以听到从客房里不时地呼呼
的打酣声，一阵高过一阵。不时有睡意朦胧的旅客进进出出，到
楼下的伙计处付了钱再上来睡觉。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"kezhan5",
  "north" : __DIR__"kezhan3",
  "east" : __DIR__"kezhan4",
  "west" : __DIR__"kezhan6",
  "down" : __DIR__"yuelaikezhan",
]));

	setup();
	create_door("east", "房门", "west", DOOR_CLOSED);
	create_door("north", "房门", "south", DOOR_CLOSED);
	create_door("south", "房门", "north", DOOR_CLOSED);
	create_door("west", "房门", "east", DOOR_CLOSED);
}

int valid_leave(object me,string arg)
{
	object room;

	switch (arg)
	{
		case "east":
		case "west":
		case "north":
		case "south":
			if(query("exits/"+arg))
				room = find_object(query("exits/"+arg));
			break;
	}

	if( room && have_person(room) )
		return notify_fail("那间客房里有人了。\n");
	else
		return 1;
}
