
/*�˶δ����� PLAYERHOME_D �Զ�����,����ı������κ�����!!*/
#include <room.h>
/*�����Զ��������.*/
// Room: /d/path2/ch_t10.c

inherit ROOM;

void create()
{
	set("short", "����·");
	set("long", @LONG
����һ�������������·������һƬƬ���֣�����������
Ҷɳɳ���졣����Զ����ȥ��һƬƬ�������������ߣ���������
һ�������ꡣ
LONG
	);
	set("exits", ([
/*�˶δ����� PLAYERHOME_D �Զ�����,����ı������κ�����!!*/
	"west" : "/d/phome/path2/yuppie_home",
/*�����Զ��������.*/

/*�˶δ����� PLAYERHOME_D �Զ�����,����ı������κ�����!!*/
	"east" : "/d/phome/path2/loveryou_home",
/*�����Զ��������.*/
 /* sizeof() == 2 */
  "north" : __DIR__"ch_t8",
  "south" : __DIR__"ch_t11",
]));
	set("no_clean_up", 0);
	set("outdoors", "path2");
	setup();
/*�˶δ����� PLAYERHOME_D �Զ�����,����ı������κ�����!!*/
	create_door("west", "ľ��", "east", DOOR_CLOSED,LOCKED,"/d/phome/path2/yuppie_key");
/*�����Զ��������.*/

/*�˶δ����� PLAYERHOME_D �Զ�����,����ı������κ�����!!*/
	create_door("east", "ľ��", "west", DOOR_CLOSED,LOCKED,"/d/phome/path2/loveryou_key");
/*�����Զ��������.*/

	replace_program(ROOM);
}
