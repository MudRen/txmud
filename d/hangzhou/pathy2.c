
/*�˶δ����� PLAYERHOME_D �Զ�����,����ı������κ�����!!*/
#include <room.h>
/*�����Զ��������.*/
// Room: /d/hangzhou/pathy2.c

inherit ROOM;

void create()
{
	set("short", "С��");
	set("long", @LONG
����һ����·С����������·�����������Զ���㵽������
���ϣ�����������ȥ����������������һ�����࣬����ֻС����
�����ĵ�����������˼��ɾ���
LONG
	);
	set("outdoors", "hangzhou");
	set("no_clean_up", 0);
	set("exits", ([
/*�˶δ����� PLAYERHOME_D �Զ�����,����ı������κ�����!!*/
	"north" : "/d/phome/hangzhou/aba_home",
/*�����Զ��������.*/
 /* sizeof() == 1 */
  "west" : __DIR__"pathy1",
]));

	setup();
/*�˶δ����� PLAYERHOME_D �Զ�����,����ı������κ�����!!*/
	create_door("north", "�������", "south", DOOR_CLOSED,LOCKED,"/d/phome/hangzhou/aba_key");
/*�����Զ��������.*/

	replace_program(ROOM);
}
