
/*�˶δ����� PLAYERHOME_D �Զ�����,����ı������κ�����!!*/
#include <room.h>
/*�����Զ��������.*/
// Room: /d/fengtian/guanlu4.c

inherit ROOM;

void create()
{
	set("short", "�ٵ�");
	set("long", @LONG
���������ź���һ�������Ĺٵ��������ٵ�ͨ������»�
·�������Ƿ��챱�ǵķ������ڡ�
LONG
	);

	set("exits", ([
/*�˶δ����� PLAYERHOME_D �Զ�����,����ı������κ�����!!*/
	"west" : "/d/phome/fengtian/tilian_home",
/*�����Զ��������.*/
 /* sizeof() == 2 */
  "south" : __DIR__"xh3",
  "north" : __DIR__"n_gate",
]));
        set("outdoors", "fengtian");

	set("objects",([
	NPC_DIR"stdnpc/stdnpc_3" : 4,
]));

	setup();
/*�˶δ����� PLAYERHOME_D �Զ�����,����ı������κ�����!!*/
	create_door("west", "��ľ��", "east", DOOR_CLOSED,LOCKED,"/d/phome/fengtian/tilian_key");
/*�����Զ��������.*/

	replace_program(ROOM);
}
