
/*�˶δ����� PLAYERHOME_D �Զ�����,����ı������κ�����!!*/
#include <room.h>
/*�����Զ��������.*/
// Room: /d/path1/tch_ft7.c

inherit ROOM;

void create()
{
	set("short", "ɽ·");
	set("long", @LONG
����һ��ɽ�Դ�·��·�ı�����һ������ɽ����������ƬƬ
�����֡�����������㲻���е��������⡣
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([
/*�˶δ����� PLAYERHOME_D �Զ�����,����ı������κ�����!!*/
	"north" : "/d/phome/path1/yezi_home",
/*�����Զ��������.*/
 /* sizeof() == 2 */
  "west" : __DIR__"tch_ft6",
  "east" : __DIR__"tch_ft8",
]));
	set("outdoors", "path1");
	setup();
/*�˶δ����� PLAYERHOME_D �Զ�����,����ı������κ�����!!*/
	create_door("north", "����", "south", DOOR_CLOSED,LOCKED,"/d/phome/path1/yezi_key");
/*�����Զ��������.*/

	replace_program(ROOM);
}
