
/*�˶δ����� PLAYERHOME_D �Զ�����,����ı������κ�����!!*/
#include <room.h>
/*�����Զ��������.*/
// Room: /d/path2/ch_k2.c

inherit ROOM;

void create()
{
	set("short", "��ʯ�ٵ�");
	set("long", @LONG
����һ���ٵ������Ը��ⷱ����·�ϸ��ָ���������������
���ﲻ�����ǳ����֡���ʱ�������������߷ɳ۶���������һ
·������·��������һƬƬ�����֡�
LONG
	);
	set("exits", ([
/*�˶δ����� PLAYERHOME_D �Զ�����,����ı������κ�����!!*/
	"west" : "/d/phome/path2/gggkkk_home",
/*�����Զ��������.*/
 /* sizeof() == 2 */
  "north" : __DIR__"ch_k1",
  "south" : __DIR__"ch_k3",
]));
	set("no_clean_up", 0);
	set("outdoors", "path2");
	setup();
/*�˶δ����� PLAYERHOME_D �Զ�����,����ı������κ�����!!*/
	create_door("west", "ľ��", "east", DOOR_CLOSED,LOCKED,"/d/phome/path2/gggkkk_key");
/*�����Զ��������.*/

	replace_program(ROOM);
}
