
/*�˶δ����� PLAYERHOME_D �Զ�����,����ı������κ�����!!*/
#include <room.h>
/*�����Զ��������.*/
// Room: /open/dt/jinyangjie6.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
��������ͬ�ϱ����ǳ����������һ���֡��ֵ�֮������
�ҷ紵�������궼Ʈ����һ���ɳ�����ֵ����Ե��̼����ƺ���
��ϰ�������ֶ��ӵ���������������ķ�ɳ��û�з������Ǿ�Ӫ
�Ÿ��Ե����⣬·���洦�ɼ�������װ������������ˡ�·�ϱ�
������̳��������ǻ���·��
LONG
	);
	set("exits", ([
/*�˶δ����� PLAYERHOME_D �Զ�����,����ı������κ�����!!*/
	"west" : "/d/phome/datong/fengjs_home",
/*�����Զ��������.*/
 /* sizeof() == 3 */
  "east" : __DIR__"huayanlu1",
  "south" : __DIR__"xftrain",
  "north" : __DIR__"jinyangjie5",
]));

	set("outdoors","datong");

	set("objects",([
	NPC_DIR"stdnpc/stdnpc_3" : 2,
__DIR__"npc/bian_laoren" : 1,]));

	setup();
/*�˶δ����� PLAYERHOME_D �Զ�����,����ı������κ�����!!*/
	create_door("west", "�������", "east", DOOR_CLOSED,LOCKED,"/d/phome/datong/fengjs_key");
/*�����Զ��������.*/

	replace_program(ROOM);
}
