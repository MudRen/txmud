
/*�˶δ����� PLAYERHOME_D �Զ�����,����ı������κ�����!!*/
#include <room.h>
/*�����Զ��������.*/
// Room: /open/dt/jinyangjie1.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
��������ͬ�ϱ����ǳ����������һ���֡��ֵ�֮������
�ҷ紵�������궼Ʈ����һ���ɳ�����ֵ����Ե��̼����ƺ���
��ϰ�������ֶ��ӵ���������������ķ�ɳ��û�з������Ǿ�Ӫ
�Ÿ��Ե����⣬·���洦�ɼ�������װ������������ˡ�·����
�Ǵ�ͬ��������Ӫ������פ���Ķ��Ǵ󽫾���������µľ�����
LONG
	);
	set("exits", ([
/*�˶δ����� PLAYERHOME_D �Զ�����,����ı������κ�����!!*/
	"east" : "/d/phome/datong/redtea_home",
/*�����Զ��������.*/
 /* sizeof() == 3 */
  "west" : __DIR__"shouweiying",
  "south" : __DIR__"jinyangjie2",
  "north" : __DIR__"beimen",
]));

	set("outdoors","datong");

	setup();
/*�˶δ����� PLAYERHOME_D �Զ�����,����ı������κ�����!!*/
	create_door("east", "ľ��", "west", DOOR_CLOSED,LOCKED,"/d/phome/datong/redtea_key");
/*�����Զ��������.*/

	replace_program(ROOM);
}
