
/*�˶δ����� PLAYERHOME_D �Զ�����,����ı������κ�����!!*/
#include <room.h>
/*�����Զ��������.*/
// Room: /d/path2/ch_t12.c

inherit ROOM;

void create()
{
	set("short", "ʯ��·");
	set("long", @LONG
����һ�������������·������һƬƬ���֣�����������
Ҷɳɳ���졣���治Զ�͵���ͬ���ˡ�
LONG
	);
	set("exits", ([
/*�˶δ����� PLAYERHOME_D �Զ�����,����ı������κ�����!!*/
	"west" : "/d/phome/path2/sunnight_home",
/*�����Զ��������.*/
 /* sizeof() == 1 */
  "north" : __DIR__"ch_t11",
  "south" : "/d/datong/out_datong_n",
]));

	set("outdoors", "path2");
	setup();
/*�˶δ����� PLAYERHOME_D �Զ�����,����ı������κ�����!!*/
	create_door("west", "ľ��", "east", DOOR_CLOSED,LOCKED,"/d/phome/path2/sunnight_key");
/*�����Զ��������.*/

	replace_program(ROOM);
}
