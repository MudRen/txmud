
/*�˶δ����� PLAYERHOME_D �Զ�����,����ı������κ�����!!*/
#include <room.h>
/*�����Զ��������.*/
// Room: /d/path2/ch_t5.c

inherit ROOM;

void create()
{
	set("short", "��·");
	set("long", @LONG
����һ������·��·�����������ˮ�����Ծ��ܹ������˳�
���٣���ûʲô����Ʈ��������ȥ����һƬ���֣���������һ
����ʯ�ٵ���
LONG
	);
	set("exits", ([
/*�˶δ����� PLAYERHOME_D �Զ�����,����ı������κ�����!!*/
	"north" : "/d/phome/path2/jiagou_home",
/*�����Զ��������.*/

/*�˶δ����� PLAYERHOME_D �Զ�����,����ı������κ�����!!*/
	"south" : "/d/phome/path2/windbell_home",
/*�����Զ��������.*/
 /* sizeof() == 2 */
  "east" : __DIR__"ch_t4",
  "west" : __DIR__"ch_t6",
]));
	set("no_clean_up", 0);
	set("outdoors", "path2");
	setup();
/*�˶δ����� PLAYERHOME_D �Զ�����,����ı������κ�����!!*/
	create_door("north", "ľ��", "south", DOOR_CLOSED,LOCKED,"/d/phome/path2/jiagou_key");
/*�����Զ��������.*/

/*�˶δ����� PLAYERHOME_D �Զ�����,����ı������κ�����!!*/
	create_door("south", "ľ��", "north", DOOR_CLOSED,LOCKED,"/d/phome/path2/windbell_key");
/*�����Զ��������.*/

	replace_program(ROOM);
}
