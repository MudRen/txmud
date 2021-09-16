
/*�˶δ����� PLAYERHOME_D �Զ�����,����ı������κ�����!!*/
#include <room.h>
/*�����Զ��������.*/
// Room: /d/fengtian/out_fengtian_w.c

inherit ROOM;

void create()
{
	set("short", "���츮������");
	set("long", @LONG
�ߵ�����͵��˷����ˡ������Ƿ��츮�����ţ������پ���
�̲��Ź��������ˡ�������ȥ��һ����ֱ����ʯ�ٵ���
LONG
	);

	set("exits", ([
/*�˶δ����� PLAYERHOME_D �Զ�����,����ı������κ�����!!*/
	"south" : "/d/phome/fengtian/jgz_home",
/*�����Զ��������.*/
 /* sizeof() == 2 */
	"east" : __DIR__"w_gate",
        "west" : "/d/path1/tch_ft21",
]));
/*
	set( "GATE_ROOM",1 );
	set( "gate_dir",(["east" : __DIR__"w_gate"]) );
	set( "close_look",@LONG
�����Ƿ��츮�⡣������һ����ʯ�ٵ������ĵ���Զ�����죬
�򶫿��Ƿ�������ţ�������ɫ���������Ѿ������ˡ�
LONG
);
	set( "gate_name","���츮����" );
*/
	set("outdoors","fengtian");
	setup();
/*�˶δ����� PLAYERHOME_D �Զ�����,����ı������κ�����!!*/
	create_door("south", "ľ��", "north", DOOR_CLOSED,LOCKED,"/d/phome/fengtian/jgz_key");
/*�����Զ��������.*/

}

int valid_leave(object ob,string dir)
{
	object *inv;

	if(!ob || !stringp(dir))
		return 1;

	if( userp(ob)
	&& !wizardp(ob)
	&& (dir == "east") )
	{
		inv = filter_array(deep_inventory(ob),
			(: $1->is_character()
			&& ( $1->query("attitude") == "killer"
			|| $1->query("attitude") == "aggressive" ) :));

		if(sizeof(inv))
			return notify_fail(sprintf("ͻȻ�ӱ�������������ʿ˵�����Ҵ�%s���Ǻ��ˣ���Ĳ��ͷ�����\n",
				inv[0]->query("name")));
	}
	return ::valid_leave(ob,dir);
}
