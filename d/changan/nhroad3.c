
/*�˶δ����� PLAYERHOME_D �Զ�����,����ı������κ�����!!*/
#include <room.h>
/*�����Զ��������.*/
// /d/changan/nhroad3  ����·

inherit ROOM;

void create()
{
        set("short", "����·");
        set("long", @LONG
�����ǳ������ڻ�·���棬�ڻ�·���ڽ��ڻʹ��ڳǼ�֮��
�Ǹ����ŵ����ڵ����Խ���ɭ�ϣ���ʱ��Ѳ�Ǿ��Ӵ������߹���
������ة�ฮ��������ű�վ���������������������Ը�����һ
���ߴ����ϵ�ʯʨ�ӡ�
LONG
        );
       set("exits", ([
/*�˶δ����� PLAYERHOME_D �Զ�����,����ı������κ�����!!*/
	"south" : "/d/phome/changan/qingyuwawa_home",
/*�����Զ��������.*/

		"north"		   : __DIR__"chengxf",
                "west"             : __DIR__"nhroad4",
                "east"             : __DIR__"nhroad2", ]) );

	set("outdoors","changan");
        setup();
/*�˶δ����� PLAYERHOME_D �Զ�����,����ı������κ�����!!*/
	create_door("south", "�������", "north", DOOR_CLOSED,LOCKED,"/d/phome/changan/qingyuwawa_key");
/*�����Զ��������.*/

	replace_program(ROOM);
}
