
/*�˶δ����� PLAYERHOME_D �Զ�����,����ı������κ�����!!*/
#include <room.h>
/*�����Զ��������.*/
// Room: /d/path1/tch_ft21.c

inherit ROOM;

void create()
{
	set("short", "�ٵ�");
	set("long", @LONG
���Ƿ����������Ĺٵ������������ó��������������
·�ߵ�С�������ؽ����ţ����ֳ�һƬ��æ�ľ��󡣶�����Ƿ�
��ǵ������ˡ�
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([
/*�˶δ����� PLAYERHOME_D �Զ�����,����ı������κ�����!!*/
	"north" : "/d/phome/path1/conne_home",
/*�����Զ��������.*/
 /* sizeof() == 1 */
  "west" : __DIR__"tch_ft20",
  "east" : "/d/fengtian/out_fengtian_w",
]));
	set("outdoors", "path1");
	setup();
/*�˶δ����� PLAYERHOME_D �Զ�����,����ı������κ�����!!*/
	create_door("north", "ľ��", "south", DOOR_CLOSED,LOCKED,"/d/phome/path1/conne_key");
/*�����Զ��������.*/

	replace_program(ROOM);
}
