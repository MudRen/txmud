
/*�˶δ����� PLAYERHOME_D �Զ�����,����ı������κ�����!!*/
#include <room.h>
/*�����Զ��������.*/
// nroad8  �����

inherit ROOM;
void create()
{
        set("short", "�����");
        set("long", @LONG
�����ǳ���������ֱ��ߣ��ǳ���������ĵض�֮һ����
�������̺��ܵ궼�ڸ�����ƽ������������������������ϣ���
��ҲҪ�ƻ�ͨ��ֱ����ҹ���ݡ���ʱ���гֵ������־���������
���������ػص�Ѳ�ߡ�����������������죬��������̩·��
LONG
        );

	set("exits", ([
/*�˶δ����� PLAYERHOME_D �Զ�����,����ı������κ�����!!*/
	"west" : "/d/phome/changan/king_home",
/*�����Զ��������.*/

                "south"           : __DIR__"wroad1",
                "east"            : __DIR__"nroad7", ]) );

	set("objects",([
	__DIR__"npc/beggar" : 1,
	NPC_DIR"xunpu" : 1,
]));

	set("outdoors","changan");
	setup();
/*�˶δ����� PLAYERHOME_D �Զ�����,����ı������κ�����!!*/
	create_door("west", "�������", "east", DOOR_CLOSED,LOCKED,"/d/phome/changan/king_key");
/*�����Զ��������.*/

}