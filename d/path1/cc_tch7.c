
/*�˶δ����� PLAYERHOME_D �Զ�����,����ı������κ�����!!*/
#include <room.h>
/*�����Զ��������.*/
// Room: /d/path1/cc_tch7.c

inherit ROOM;

void create()
{
	set("short", "����·");
	set("long", @LONG
����һ��������·�������ĳ������������������ڵ��ϣ�
��ʱ�ز�Ĩ�����Ϻ��顣·��������һƬƬ���
LONG
	);
	set("exits", ([
/*�˶δ����� PLAYERHOME_D �Զ�����,����ı������κ�����!!*/
	"west" : "/d/phome/path1/beender_home",
/*�����Զ��������.*/

  "south" : __DIR__"cc_tch6",
  "northwest" : __DIR__"cc_tch8",
]));
	set("outdoors", "path1");
        set("objects", ([
        NPC_DIR"stdnpc/stdnpc_4" : 3,
]));

	setup();
/*�˶δ����� PLAYERHOME_D �Զ�����,����ı������κ�����!!*/
	create_door("west", "����", "east", DOOR_CLOSED,LOCKED,"/d/phome/path1/beender_key");
/*�����Զ��������.*/


	replace_program(ROOM);
}
