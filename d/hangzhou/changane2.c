
/*�˶δ����� PLAYERHOME_D �Զ�����,����ı������κ�����!!*/
#include <room.h>
/*�����Զ��������.*/
// /d/hangzhou/changane2.c

inherit ROOM;

void create()
{
        set("short", "��������");
        set("long", @LONG
�������ڳǱ��ĳ������ϣ������򱱲�Զ���Ǻ��ݸ��ı���
���ˣ��������Կ������ٵ��������̴ҴҶ�����������ûʲô
�ر𷱻��ĵط�������һЩ���ֺš�
LONG
        );
        set("exits", ([
/*�˶δ����� PLAYERHOME_D �Զ�����,����ı������κ�����!!*/
	"north" : "/d/phome/hangzhou/bsjordan_home",
/*�����Զ��������.*/
 
            "south"  : __DIR__"eatroom",
            "east"   : __DIR__"changane3",
            "west"   : __DIR__"changane1",
]));
        set("outdoors", "hangzhou");

	set("objects",([
	__DIR__"npc/hseng.c" : 2,
]));

        setup();
/*�˶δ����� PLAYERHOME_D �Զ�����,����ı������κ�����!!*/
	create_door("north", "�������", "south", DOOR_CLOSED,LOCKED,"/d/phome/hangzhou/bsjordan_key");
/*�����Զ��������.*/

        replace_program(ROOM);
}

