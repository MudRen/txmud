
/*�˶δ����� PLAYERHOME_D �Զ�����,����ı������κ�����!!*/
#include <room.h>
/*�����Զ��������.*/
// Room: /d/path1/tch_ft6.c

inherit ROOM;

void create()
{
	set("short", "ɽ·");
	set("long", @LONG
����һ��ɽ�Դ�·��·�ı�����һ������ɽ����������ƬƬ
�����֡�����������㲻���е��������⡣
LONG
	);

	set("exits", ([
/*�˶δ����� PLAYERHOME_D �Զ�����,����ı������κ�����!!*/
	"south" : "/d/phome/path1/wind_home",
/*�����Զ��������.*/

	"east" : __DIR__"tch_ft7",
	"southwest" : __DIR__"tch_ft5",
	"northup" : "/d/feiyu/shanlu1",
]));
	set("outdoors", "path1");
	setup();
/*�˶δ����� PLAYERHOME_D �Զ�����,����ı������κ�����!!*/
	create_door("south", "ľ��", "north", DOOR_CLOSED,LOCKED,"/d/phome/path1/wind_key");
/*�����Զ��������.*/


	replace_program(ROOM);
}
