
/*�˶δ����� PLAYERHOME_D �Զ�����,����ı������κ�����!!*/
#include <room.h>
/*�����Զ��������.*/
// Room: /d/path1/tch_ft8.c

inherit ROOM;

void create()
{
	set("short", "ɽ·");
	set("long", @LONG
����һ��ɽ�Դ�·��·�ı�����һ������ɽ����������ƬƬ
�����֡�����������㲻���е��������⡣����ȥ���͵�ɽ��
���ˣ�·�ϵ�����Ҳ����һЩ��
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([
/*�˶δ����� PLAYERHOME_D �Զ�����,����ı������κ�����!!*/
	"south" : "/d/phome/path1/feels_home",
/*�����Զ��������.*/
 /* sizeof() == 2 */
  "west" : __DIR__"tch_ft7",
  "east" : __DIR__"tch_ft9",
]));
	set("outdoors", "path1");
	setup();
/*�˶δ����� PLAYERHOME_D �Զ�����,����ı������κ�����!!*/
	create_door("south", "ľ��", "north", DOOR_CLOSED,LOCKED,"/d/phome/path1/feels_key");
/*�����Զ��������.*/

	replace_program(ROOM);
}
