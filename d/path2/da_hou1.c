
/*�˶δ����� PLAYERHOME_D �Զ�����,����ı������κ�����!!*/
#include <room.h>
/*�����Զ��������.*/
// Room: /d/path2/da_hou1.c

inherit ROOM;

void create()
{
	set("short", "��·");
	set("long", @LONG
����һ�������Ļ���·��������һ���޼ʵ���ɴ�ʣ������
ͬ���������Ѿ�ңң�����ˡ�
LONG
	);
	set("exits", ([
/*�˶δ����� PLAYERHOME_D �Զ�����,����ı������κ�����!!*/
	"east" : "/d/phome/path2/kdk_home",
/*�����Զ��������.*/
 /* sizeof() == 1 */
  "south" : __DIR__"da_hou2",
  "north" : "/d/datong/out_datong_s",
]));
	set("no_clean_up", 0);
	set("outdoors", "path2");
	setup();
/*�˶δ����� PLAYERHOME_D �Զ�����,����ı������κ�����!!*/
	create_door("east", "ľ��", "west", DOOR_CLOSED,LOCKED,"/d/phome/path2/kdk_key");
/*�����Զ��������.*/

	replace_program(ROOM);
}
