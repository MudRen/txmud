
/*�˶δ����� PLAYERHOME_D �Զ�����,����ı������κ�����!!*/
#include <room.h>
/*�����Զ��������.*/
// Room: /d/path2/da_hou7.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
������С·�ϣ�·�������Ÿߴ����������һ���ŵ���ʿ
վ����·�����ԡ�ż�������������ŵ��Ӿ��������������ͻ���
��ơ�
LONG
	);
	set("exits", ([
/*�˶δ����� PLAYERHOME_D �Զ�����,����ı������κ�����!!*/
	"north" : "/d/phome/path2/shady_home",
/*�����Զ��������.*/
 /* sizeof() == 2 */
  "south" : __DIR__"da_hou8",
  "northwest" : "/d/path2/da_hou6",
        "northeast" : "/d/huayin/tl4",
]));
	set("outdoors", "path2");
	setup();
/*�˶δ����� PLAYERHOME_D �Զ�����,����ı������κ�����!!*/
	create_door("north", "����", "south", DOOR_CLOSED,LOCKED,"/d/phome/path2/shady_key");
/*�����Զ��������.*/

	replace_program(ROOM);
}
