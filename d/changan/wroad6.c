
/*�˶δ����� PLAYERHOME_D �Զ�����,����ı������κ�����!!*/
#include <room.h>
/*�����Զ��������.*/
// Room: /d/changan/wroad6.c

inherit ROOM;

void create()
{
	set("short", "��̩·");
	set("long", @LONG
�����ǳ����ǵ�����֣�����ǳ��徻��·��û��һ���̷���
�����ߵ�����Ҳ�ǹ��ؾصĿ첽��ȥ��û��һ��������������
������·������ǳ�͢�Ĺ������ţ�����ͣ�ż��˹ٽΣ��ſ�ս
��һ���Źٺͼ���������������
LONG
	);
	set("outdoors", "changan");
	set("no_clean_up", 0);
	set("exits", ([
/*�˶δ����� PLAYERHOME_D �Զ�����,����ı������κ�����!!*/
	"west" : "/d/phome/changan/jiangyue_home",
/*�����Զ��������.*/
 /* sizeof() == 3 */
  "east" : __DIR__"gongbu",
  "south" : __DIR__"wroad7",
  "north" : __DIR__"wroad5",
]));

	set("objects",([
	NPC_DIR"xunpu" : 1,
]));

	setup();
/*�˶δ����� PLAYERHOME_D �Զ�����,����ı������κ�����!!*/
	create_door("west", "�������", "east", DOOR_CLOSED,LOCKED,"/d/phome/changan/jiangyue_key");
/*�����Զ��������.*/

	replace_program(ROOM);
}
