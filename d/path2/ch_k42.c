
/*�˶δ����� PLAYERHOME_D �Զ�����,����ı������κ�����!!*/
#include <room.h>
/*�����Զ��������.*/
// Room: /d/path2/ch_k42.c

inherit ROOM;

void create()
{
	set("short", "�������");
	set("long", @LONG
����һ����������ϣ�·�Ϲ��������˺ܶ࣬����С����·
��ٽ�������������������ؽ����š�������ǿ��⸮�ı��ţ���
���˿������ӿ��˽Ų���
LONG
	);
	set("exits", ([
/*�˶δ����� PLAYERHOME_D �Զ�����,����ı������κ�����!!*/
	"east" : "/d/phome/path2/zhm_home",
/*�����Զ��������.*/

/*�˶δ����� PLAYERHOME_D �Զ�����,����ı������κ�����!!*/
	"west" : "/d/phome/path2/seng_home",
/*�����Զ��������.*/
 /* sizeof() == 2 */
  "north" : __DIR__"ch_k41",
        "south" : "/d/kaifeng/out_kaifeng_n",
]));
	set("no_clean_up", 0);
	set("outdoors", "path2");
	setup();
/*�˶δ����� PLAYERHOME_D �Զ�����,����ı������κ�����!!*/
	create_door("east", "ľ��", "west", DOOR_CLOSED,LOCKED,"/d/phome/path2/zhm_key");
/*�����Զ��������.*/

/*�˶δ����� PLAYERHOME_D �Զ�����,����ı������κ�����!!*/
	create_door("west", "����", "east", DOOR_CLOSED,LOCKED,"/d/phome/path2/seng_key");
/*�����Զ��������.*/

	replace_program(ROOM);
}
