
/*�˶δ����� PLAYERHOME_D �Զ�����,����ı������κ�����!!*/
#include <room.h>
/*�����Զ��������.*/
// Room: /d/lumaji/lu13.c

inherit ROOM;

void create()
{
	set("short", "��·");
	set("long", @LONG
����һ�����С·��·�����׾��Ǳ�������Ի��ң�����
ȥ��һƬ���֡�
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([
/*�˶δ����� PLAYERHOME_D �Զ�����,����ı������κ�����!!*/
	"east" : "/d/phome/lumaji/kendy_home",
/*�����Զ��������.*/
 /* sizeof() == 2 */
  "west" : __DIR__"liehu",
  "south" : __DIR__"lu12",
]));
	set("outdoors", "lumaji");
	setup();
/*�˶δ����� PLAYERHOME_D �Զ�����,����ı������κ�����!!*/
	create_door("east", "ľ��", "west", DOOR_CLOSED,LOCKED,"/d/phome/lumaji/kendy_key");
/*�����Զ��������.*/

	replace_program(ROOM);
}
