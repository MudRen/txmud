
/*�˶δ����� PLAYERHOME_D �Զ�����,����ı������κ�����!!*/
#include <room.h>
/*�����Զ��������.*/
// Room: /d/path2/ch_t2.c

inherit ROOM;

void create()
{
	set("short", "��ʯ�ٵ�");
	set("long", @LONG
���ǳ�����������Ĵ�������Ը��ⷱ����·�ϸ��ָ�����
�������������ﲻ�����ǳ����֡���ʱ�������������߷ɳ۶�
��������һ·������·��������һƬƬ�����֡�
LONG
	);
	set("exits", ([
/*�˶δ����� PLAYERHOME_D �Զ�����,����ı������κ�����!!*/
	"south" : "/d/phome/path2/syncmaster_home",
/*�����Զ��������.*/
 /* sizeof() == 2 */
  "east" : __DIR__"ch_t1",
  "west" : __DIR__"ch_t3",
]));
	set("no_clean_up", 0);
	set("outdoors", "path2");
	setup();
/*�˶δ����� PLAYERHOME_D �Զ�����,����ı������κ�����!!*/
	create_door("south", "ľ��", "north", DOOR_CLOSED,LOCKED,"/d/phome/path2/syncmaster_key");
/*�����Զ��������.*/

	replace_program(ROOM);
}
