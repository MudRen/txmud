
/*�˶δ����� PLAYERHOME_D �Զ�����,����ı������κ�����!!*/
#include <room.h>
/*�����Զ��������.*/
// Room: /d/zuojiacun/jing.c

inherit ROOM;

void create()
{
	set("short", "�ݾ�");
	set("long", @LONG
����һ�ڿݾ������������Ѿ������ˡ����ܶ������ż�ֻ
��ȸ���������߹����������ų�����������
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([
/*�˶δ����� PLAYERHOME_D �Զ�����,����ı������κ�����!!*/
	"north" : "/d/phome/zuojiacun/wandy_home",
/*�����Զ��������.*/
 /* sizeof() == 1 */
  "south" : __DIR__"lu11",
]));
	set("outdoors", "zuojiacun");
	setup();
/*�˶δ����� PLAYERHOME_D �Զ�����,����ı������κ�����!!*/
	create_door("north", "����", "south", DOOR_CLOSED,LOCKED,"/d/phome/zuojiacun/wandy_key");
/*�����Զ��������.*/

	replace_program(ROOM);
}
