
/*�˶δ����� PLAYERHOME_D �Զ�����,����ı������κ�����!!*/
#include <room.h>
/*�����Զ��������.*/

inherit ROOM;

void create()
{
        set("short", "��̩·");
        set("long", @LONG
�����ǳ����ǵ�����֣�Ҳ�ǳ����ǵ����Ͻǣ����������
��Ȼ�Ѿ������ˣ����������ȴ���Ǻ��ࡣ����Ĵ���ʯ��ש��
�����߲���ݼ̦�����ߵ�ͩ����ס�˵�·�Ͽգ���ʹ�ǰ��죬��
��Ҳ�Ե��������ġ�������������̩·�����ǻ���֡�
LONG
        );

	set("exits", ([
/*�˶δ����� PLAYERHOME_D �Զ�����,����ı������κ�����!!*/
	"south" : "/d/phome/changan/konami_home",
/*�����Զ��������.*/

                "north"            : __DIR__"wroad7",
                "east"             : __DIR__"sroad1",
]) );

	set("outdoors","changan");

	set("objects",([
	NPC_DIR"stdnpc/stdnpc_1" : 4,
]));

        setup();
/*�˶δ����� PLAYERHOME_D �Զ�����,����ı������κ�����!!*/
	create_door("south", "�������", "north", DOOR_CLOSED,LOCKED,"/d/phome/changan/konami_key");
/*�����Զ��������.*/


	replace_program(ROOM);
}
