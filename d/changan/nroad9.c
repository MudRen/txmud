
/*�˶δ����� PLAYERHOME_D �Զ�����,����ı������κ�����!!*/
#include <room.h>
/*�����Զ��������.*/
// /d/changan/nroad9  �������

inherit ROOM;

void create()
{
        set("short", "�������");
        set("long", @LONG
���Ǿ����ϱ�ֱͨ�ʹ��ı��������Ҳ�ǳ�����ͨ����˵��
�����ٵ�֮һ����ʱ���г�͢�еĿ����˾�����Ҫ�����ǳ���
�����ǵĹ�Ա��������Ѳ�������־���������������ɭ�ϡ���
һֱ���ǳ����ǵı��ţ�����ֱͨ�ʹ���������һ��Ǯׯ��
LONG
        );
       set("exits", ([
/*�˶δ����� PLAYERHOME_D �Զ�����,����ı������κ�����!!*/
	"east" : "/d/phome/changan/yiki_home",
/*�����Զ��������.*/

                "west"            : __DIR__"bank",
                "south"           : __DIR__"nhroad2",
                "north"           : __DIR__"nroad4", ]) );
       set("outdoors","changan");
        setup();
/*�˶δ����� PLAYERHOME_D �Զ�����,����ı������κ�����!!*/
	create_door("east", "�������", "west", DOOR_CLOSED,LOCKED,"/d/phome/changan/yiki_key");
/*�����Զ��������.*/

	replace_program(ROOM);
}