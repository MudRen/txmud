
/*�˶δ����� PLAYERHOME_D �Զ�����,����ı������κ�����!!*/
#include <room.h>
/*�����Զ��������.*/
// Room: /d/path2/ch_t1.c

inherit ROOM;

void create()
{
	set("short", "��ʯ�ٵ�");
	set("long", @LONG
����һ���ٵ������Ը��ⷱ����·�ϸ��ָ���������������
���ﲻ�����ǳ����֡���ʱ�������������߷ɳ۶���������һ
·������������Զ���ǳ����ǵ������ˡ�
LONG
	);
	set("exits", ([
/*�˶δ����� PLAYERHOME_D �Զ�����,����ı������κ�����!!*/
	"north" : "/d/phome/path2/bbjj_home",
/*�����Զ��������.*/

	"west" : __DIR__"ch_t2",
	"east" : "/d/changan/out_changan_w",
]));
	set("outdoors", "path2");
	setup();
/*�˶δ����� PLAYERHOME_D �Զ�����,����ı������κ�����!!*/
	create_door("north", "ľ��", "south", DOOR_CLOSED,LOCKED,"/d/phome/path2/bbjj_key");
/*�����Զ��������.*/


	replace_program(ROOM);
}
