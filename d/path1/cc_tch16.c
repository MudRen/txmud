
/*�˶δ����� PLAYERHOME_D �Զ�����,����ı������κ�����!!*/
#include <room.h>
/*�����Զ��������.*/
// Room: /d/path1/cc_tch16.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
������ǡ������¡���·����һЩС���ڽ�����������һ��
����·�ڣ�����ȥͨס��Į���򶫵ķ�����Ե�ɽ���أ�������
��ͨ�򳤰��ǡ�һ������������˶�Ҫ�������
LONG
	);
	set("exits", ([
/*�˶δ����� PLAYERHOME_D �Զ�����,����ı������κ�����!!*/
	"north" : "/d/phome/path1/lzz_home",
/*�����Զ��������.*/

  "west" : __DIR__"cc_tch17",
  "south" : __DIR__"cc_tch15",
  "east" : __DIR__"tch_ft1",
]));

	set("objects",([
	__DIR__"npc/seller" : 1,
]));

	set("outdoors", "path1");
	setup();
/*�˶δ����� PLAYERHOME_D �Զ�����,����ı������κ�����!!*/
	create_door("north", "ľ��", "south", DOOR_CLOSED,LOCKED,"/d/phome/path1/lzz_key");
/*�����Զ��������.*/


	replace_program(ROOM);
}
