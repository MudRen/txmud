
/*�˶δ����� PLAYERHOME_D �Զ�����,����ı������κ�����!!*/
#include <room.h>
/*�����Զ��������.*/
// Room: /d/tianshui/ekou.c

inherit ROOM;

void create()
{
	set("short", "��ˮ�򶫿�");
	set("long", @LONG
��������ˮ��Ķ��ڡ���ˮ����˵ֻ��һ�����ż�ʮ���˼�
��С���ӣ������ڵش�Ҫ�壬��������������������һ�����ѵ�
С·��Զ����չ��
LONG
	);
	set("exits", ([
/*�˶δ����� PLAYERHOME_D �Զ�����,����ı������κ�����!!*/
	"north" : "/d/phome/tianshui/feitian_home",
/*�����Զ��������.*/
 /* sizeof() == 2 */
  "west" : __DIR__"eroad3",
  "east" : __DIR__"xiaolu1",
]));
	set("no_clean_up", 0);
	set("outdoors","tianshui");
	setup();
/*�˶δ����� PLAYERHOME_D �Զ�����,����ı������κ�����!!*/
	create_door("north", "��ľ��", "south", DOOR_CLOSED,LOCKED,"/d/phome/tianshui/feitian_key");
/*�����Զ��������.*/

	replace_program(ROOM);
}
