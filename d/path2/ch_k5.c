
/*�˶δ����� PLAYERHOME_D �Զ�����,����ı������κ�����!!*/
#include <room.h>
/*�����Զ��������.*/
// Room: /d/path2/ch_k5.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
��������������ˣ�·���ϲ���С���ڽ���������һ����·
����ʱ�����ˣ���֪��ʲôԭ�ʡ���������볤�����Ѿ���Զ
�ˡ�
LONG
	);
	set("exits", ([
/*�˶δ����� PLAYERHOME_D �Զ�����,����ı������κ�����!!*/
	"east" : "/d/phome/path2/jef_home",
/*�����Զ��������.*/
 /* sizeof() == 3 */
  "north" : __DIR__"ch_k4",
  "southwest" : __DIR__"ch_k6",
]));
	set("outdoors", "path2");
	setup();
/*�˶δ����� PLAYERHOME_D �Զ�����,����ı������κ�����!!*/
	create_door("east", "ľ��", "west", DOOR_CLOSED,LOCKED,"/d/phome/path2/jef_key");
/*�����Զ��������.*/

	replace_program(ROOM);
}
