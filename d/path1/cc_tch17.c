
/*�˶δ����� PLAYERHOME_D �Զ�����,����ı������κ�����!!*/
#include <room.h>
/*�����Զ��������.*/
// Room: /d/path1/cc_tch17.c

inherit ROOM;

void create()
{
	set("short", "��·");
	set("long", @LONG
����һ������С·������ȥ���ǡ������¡��ˡ������Ѿ�
�ӽ��˹��⣬����������������ϸϸ��ɳ�����㲻����������
����
LONG
	);

	set("exits", ([
/*�˶δ����� PLAYERHOME_D �Զ�����,����ı������κ�����!!*/
	"south" : "/d/phome/path1/blackedge_home",
/*�����Զ��������.*/

  "west" : __DIR__"cc_tch18",
  "east" : __DIR__"cc_tch16",
]));
	set("outdoors", "path1");
	setup();
/*�˶δ����� PLAYERHOME_D �Զ�����,����ı������κ�����!!*/
	create_door("south", "����", "north", DOOR_CLOSED,LOCKED,"/d/phome/path1/blackedge_key");
/*�����Զ��������.*/


	replace_program(ROOM);
}
