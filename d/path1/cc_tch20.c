
/*�˶δ����� PLAYERHOME_D �Զ�����,����ı������κ�����!!*/
#include <room.h>
/*�����Զ��������.*/
// Room: /d/path1/cc_tch20.c

inherit ROOM;

void create()
{
	set("short", "ɳ·");
	set("long", @LONG
�ߵ�������Ѿ���������ˣ����˷�ɳ�;�ʯ����ʲôҲ
����������Զ�ĵ��ϣ�ɢ����һЩʬ�ǣ���֪������ʲô����ɫ
������������ż�ֻͺӥ��
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([
/*�˶δ����� PLAYERHOME_D �Զ�����,����ı������κ�����!!*/
	"north" : "/d/phome/path1/bsjordan_home",
/*�����Զ��������.*/

/*�˶δ����� PLAYERHOME_D �Զ�����,����ı������κ�����!!*/
	"south" : "/d/phome/path1/feig_home",
/*�����Զ��������.*/
 /* sizeof() == 1 */
  "east" : __DIR__"cc_tch19",
]));
	set("outdoors", "path1");
	setup();
/*�˶δ����� PLAYERHOME_D �Զ�����,����ı������κ�����!!*/
	create_door("north", "ľ��", "south", DOOR_CLOSED,LOCKED,"/d/phome/path1/bsjordan_key");
/*�����Զ��������.*/

/*�˶δ����� PLAYERHOME_D �Զ�����,����ı������κ�����!!*/
	create_door("south", "ľ��", "north", DOOR_CLOSED,LOCKED,"/d/phome/path1/feig_key");
/*�����Զ��������.*/

	replace_program(ROOM);
}
