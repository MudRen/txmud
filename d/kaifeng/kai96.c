
/*�˶δ����� PLAYERHOME_D �Զ�����,����ı������κ�����!!*/
#include <room.h>
/*�����Զ��������.*/
// Room: /u/w/wangs/b/kai96.c

inherit ROOM;

void create()
{
	set("short", "���Ľ�");
	set("long", @LONG
���Ľ��ǿ��⸮����ĵ��򣬽ֵ�һ�����������Ĺ㳡��
��һ�������������ӿ�볱�����ǵ�����䣬��������������
������磬����С�ԡ�̯����������ڴˣ�ʵΪ����һ���쾰��
���Ե������ְ��������Ľֽ��������Χ������
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([
/*�˶δ����� PLAYERHOME_D �Զ�����,����ı������κ�����!!*/
	"south" : "/d/phome/kaifeng/think_home",
/*�����Զ��������.*/
 /* sizeof() == 3 */
  "north" : __DIR__"kai137",
  "west" : __DIR__"kai95",
]));

	set("objects",([
	NPC_DIR"stdnpc/stdnpc_2" : 5,
]));

	set("outdoors","kaifeng");
	setup();
/*�˶δ����� PLAYERHOME_D �Զ�����,����ı������κ�����!!*/
	create_door("south", "�������", "north", DOOR_CLOSED,LOCKED,"/d/phome/kaifeng/think_key");
/*�����Զ��������.*/

	replace_program(ROOM);
}
