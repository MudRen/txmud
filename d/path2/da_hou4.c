
/*�˶δ����� PLAYERHOME_D �Զ�����,����ı������κ�����!!*/
#include <room.h>
/*�����Զ��������.*/
// Room: /d/path2/da_hou4.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
����һ����᫲�ƽ��С·��·�������Ǹ����ء�����ĸ���
����������׳���ߴ����Ҷ��ס��������ߣ���ֻ��һƬ��ãã
����ǰ������ȥ��
LONG
	);
	set("exits", ([
/*�˶δ����� PLAYERHOME_D �Զ�����,����ı������κ�����!!*/
	"west" : "/d/phome/path2/buck_home",
/*�����Զ��������.*/

  "north" : __DIR__"da_hou3",
  "east" : __DIR__"da_hou5",
]));
	set("outdoors", "path2");
	setup();
/*�˶δ����� PLAYERHOME_D �Զ�����,����ı������κ�����!!*/
	create_door("west", "����", "east", DOOR_CLOSED,LOCKED,"/d/phome/path2/buck_key");
/*�����Զ��������.*/


	replace_program(ROOM);
}
