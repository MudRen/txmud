
/*�˶δ����� PLAYERHOME_D �Զ�����,����ı������κ�����!!*/
#include <room.h>
/*�����Զ��������.*/
// Room: /u/w/wangs/b/kai11.c

inherit ROOM;

void create()
{
	set("short", "С����");
	set("long", @LONG
����һ�����������ĺ���ʯС�ţ��߸ߵؼ������к��ϣ�һ
Ҷ�����ڰ������д����´�����ԶԶ��ȥ�����ϵ��������ں�ˮ
�����ᵴ����վ�����������ʯ���⣬��������ƾ����������
��Ȼ����һ�ֹ¶������ĸо���
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([
/*�˶δ����� PLAYERHOME_D �Զ�����,����ı������κ�����!!*/
	"north" : "/d/phome/kaifeng/qingyuwawa_home",
/*�����Զ��������.*/
 /* sizeof() == 2 */
  "southeast" : __DIR__"kai12",
  "west" : __DIR__"kai9",
]));

	set("outdoors","kaifeng");
	setup();
/*�˶δ����� PLAYERHOME_D �Զ�����,����ı������κ�����!!*/
	create_door("north", "��ľ��", "south", DOOR_CLOSED,LOCKED,"/d/phome/kaifeng/qingyuwawa_key");
/*�����Զ��������.*/

	replace_program(ROOM);
}
