
/*�˶δ����� PLAYERHOME_D �Զ�����,����ı������κ�����!!*/
#include <room.h>
/*�����Զ��������.*/
// Room: /d/changan/wroad7.c

inherit ROOM;

void create()
{
	set("short", "��̩·");
	set("long", @LONG
�����ǳ����ǵ�����֣�·������һЩ�����ˣ����������⡣
һЩ����Ҳ�������������ϣ�������һЩ���࿪���Ĺٽδ�����
���������ϲ���������������̩·���������ϱ����졣·����һ
�ҼҾߵ꣬���������Ⲣ���Ǻܺá�
LONG
	);
	set("outdoors", "changan");
	set("no_clean_up", 0);
	set("exits", ([
/*�˶δ����� PLAYERHOME_D �Զ�����,����ı������κ�����!!*/
	"east" : "/d/phome/changan/aguitwo_home",
/*�����Զ��������.*/
 /* sizeof() == 3 */
  "south" : __DIR__"wroad8",
  "west" : __DIR__"furniture",
  "north" : __DIR__"wroad6",
]));

	setup();
/*�˶δ����� PLAYERHOME_D �Զ�����,����ı������κ�����!!*/
	create_door("east", "�������", "west", DOOR_CLOSED,LOCKED,"/d/phome/changan/aguitwo_key");
/*�����Զ��������.*/

	replace_program(ROOM);
}
