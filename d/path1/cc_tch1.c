
/*�˶δ����� PLAYERHOME_D �Զ�����,����ı������κ�����!!*/
#include <room.h>
/*�����Զ��������.*/
// Room: /d/path1/cc_tch1.c

inherit ROOM;

void create()
{
	set("short", "�ٵ�");
	set("long", @LONG
����һ�����ž�ʦ�뱱������Ĺٵ������Ը��ⷱ����·��
���������������ӵġ����̵ġ����Ŵ󳵵�������ﲻ����·
�߻���һЩС�̷��ڽ������ǳ����֡���ʱ�������������߷�
�۶���������һ·���������ϲ�Զ���ǳ����ǵı����ˡ�
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([
/*�˶δ����� PLAYERHOME_D �Զ�����,����ı������κ�����!!*/
	"east" : "/d/phome/path1/leaf_home",
/*�����Զ��������.*/

/*�˶δ����� PLAYERHOME_D �Զ�����,����ı������κ�����!!*/
	"west" : "/d/phome/path1/olive_home",
/*�����Զ��������.*/
 /* sizeof() == 2 */
  "south" : "/d/changan/ch-ft1",
  "north" : __DIR__"cc_tch2",
]));
	set("outdoors", "path1");

	set("objects",([
	__DIR__"npc/tiaofu" : 1,
]));

	setup();
/*�˶δ����� PLAYERHOME_D �Զ�����,����ı������κ�����!!*/
	create_door("east", "ľ��", "west", DOOR_CLOSED,LOCKED,"/d/phome/path1/leaf_key");
/*�����Զ��������.*/

/*�˶δ����� PLAYERHOME_D �Զ�����,����ı������κ�����!!*/
	create_door("west", "ľ��", "east", DOOR_CLOSED,LOCKED,"/d/phome/path1/olive_key");
/*�����Զ��������.*/

	replace_program(ROOM);
}
