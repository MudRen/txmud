
/*�˶δ����� PLAYERHOME_D �Զ�����,����ı������κ�����!!*/
#include <room.h>
/*�����Զ��������.*/
// Room: /d/datong/out_datong_s.c

inherit ROOM;

void create()
{
	set("short", "��ͬ��������");
	set("long", @LONG
������Ǵ�ͬ�����������ˣ��ߴ����ϵ�����¥���������
��ǰ��һ�ӹٱ���������Ĳ�����������߹���������������ס
һ������������ʲô��
LONG
	);

	set("exits", ([
/*�˶δ����� PLAYERHOME_D �Զ�����,����ı������κ�����!!*/
	"west" : "/d/phome/datong/beta_home",
/*�����Զ��������.*/
 /* sizeof() == 1 */
  "north" : __DIR__"nanmen",
  "south" : "/d/path2/da_hou1",
]));
/*
// gate settings
// �˲���Ϊ gate room �����������.

	// ���� gate room ���.ע�� GATE_ROOM Ҫ��д.
	set( "GATE_ROOM",1 );

	// ���� gate �ķ���,ע�ⷽ����һ�� mapping.
	set( "gate_dir",(["north" : __DIR__"nanmen"]) );

	// �����Ź����Ժ󿴵��ķ�������.
	// ����ͬ����ĳ�������.
	set( "close_look",@LONG
������Ǵ�ͬ�����������ˣ��ߴ����ϵ�����¥���������
��ǰ��������ɫ���������Ѿ������ˡ�
LONG
);

	// ���� gate ������,������ʱ�˷�������ҿ�������ʾҪ�õ�.
	set( "gate_name","��ͬ������" );

// end.
*/
	set("outdoors","datong");

	setup();
/*�˶δ����� PLAYERHOME_D �Զ�����,����ı������κ�����!!*/
	create_door("west", "��ľ��", "east", DOOR_CLOSED,LOCKED,"/d/phome/datong/beta_key");
/*�����Զ��������.*/

	replace_program(ROOM);
}
