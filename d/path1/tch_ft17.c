
/*�˶δ����� PLAYERHOME_D �Զ�����,����ı������κ�����!!*/
#include <room.h>
/*�����Զ��������.*/
// Room: /d/path1/tch_ft17.c

inherit ROOM;

void create()
{
	set("short", "��θ�");
	set("long", @LONG
������ǳ�θڡ���˵������һ���ճ�ĲοͿ��������黨
�Ρ����ұ�����ҧ�ˣ��ӵ��˵���������������һЩ�ο�����
����ɽ������Ѱ��ȴһֱδ�������ڶ��յı��꣬������ɽС·
����ʯ�����ˡ��򶫲�Զ�����Ƿ�����ˡ�
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([
/*�˶δ����� PLAYERHOME_D �Զ�����,����ı������κ�����!!*/
	"north" : "/d/phome/path1/seve_home",
/*�����Զ��������.*/
 /* sizeof() == 2 */
  "west" : __DIR__"tch_ft16",
  "east" : __DIR__"tch_ft18",
]));
	set("outdoors", "path1");
	setup();
/*�˶δ����� PLAYERHOME_D �Զ�����,����ı������κ�����!!*/
	create_door("north", "����", "south", DOOR_CLOSED,LOCKED,"/d/phome/path1/seve_key");
/*�����Զ��������.*/

	replace_program(ROOM);
}
