// Room: /d/xiaozhen/biaoju3.c

#include <room.h>

inherit ROOM;
inherit __DIR__"obj/valid";

void setup();

void create()
{
	set("short", "����");
	set("long", @LONG
�������ھֵ����ң������ڻ�û���ü����ߵĻ��ﶼ�ȴ��
�����������һ�����š�
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
	"west" : __DIR__"biaoju2",
]));

	setup();

	create_door("west", "����", "east", DOOR_CLOSED,LOCKED,__DIR__"npc/obj/key1");
}

void setup()
{
	object obj,qiao,let;

	::setup();

	obj = new(__DIR__"obj/tie_xiang");
	obj->move(this_object());

	if(valid())
	{
		qiao = new(__DIR__"obj/sword_and_qiao");
		qiao->move(obj);
		let = new(__DIR__"obj/letter");
		let->move(obj);
	}
}
