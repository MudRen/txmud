
/*�˶δ����� PLAYERHOME_D �Զ�����,����ı������κ�����!!*/
#include <room.h>
/*�����Զ��������.*/
// Room: /u/w/wangs/b/kai1.c

inherit ROOM;

void create()
{
	set("short", "����������");
	set("long", @LONG
������һ��ͨ����ǣ��˿��ڶ࣬��ҵ�������Թ���������
���ұ���֮�ء���ʵ�ĳ�¥�����ɶ�ߡ�����һ�������Զ����
�졣
LONG
	);
	set("exits", ([
/*�˶δ����� PLAYERHOME_D �Զ�����,����ı������κ�����!!*/
	"south" : "/d/phome/kaifeng/tigertu_home",
/*�����Զ��������.*/
 /* sizeof() == 1 */
  "east" : __DIR__"wdoor",
  "west" : "/d/shaolin/k_s01",
]));
/*
        set( "GATE_ROOM",1 );
        set( "gate_dir",(["east" : __DIR__"wdoor"]) );
        set( "close_look",@LONG
������һ��ͨ����ǣ��˿��ڶ࣬��ҵ�������Թ���������
���ұ���֮�ء�������ǿ���������ˣ�������ɫ����������
�������ˡ�
LONG
);
        set( "gate_name","��������" );
*/
        set("outdoors","kaifeng");
	setup();
/*�˶δ����� PLAYERHOME_D �Զ�����,����ı������κ�����!!*/
	create_door("south", "�������", "north", DOOR_CLOSED,LOCKED,"/d/phome/kaifeng/tigertu_key");
/*�����Զ��������.*/

}
