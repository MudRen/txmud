
/*�˶δ����� PLAYERHOME_D �Զ�����,����ı������κ�����!!*/
#include <room.h>
/*�����Զ��������.*/
// Room: /d/path2/ch_t7.c

inherit ROOM;

void create()
{
	set("short", "��·");
	set("long", @LONG
����һ�������������·������һ���������γɵķ���ǽ��
����������Ҷɳɳ���졣����Զ����ȥ��һƬƬ������������
�ߣ�ɢ���������ķҷ���
LONG
	);
	set("exits", ([
/*�˶δ����� PLAYERHOME_D �Զ�����,����ı������κ�����!!*/
	"north" : "/d/phome/path2/wuhao_home",
/*�����Զ��������.*/
 /* sizeof() == 2 */
  "east" : __DIR__"ch_t6",
  "southwest" : __DIR__"ch_t8",
]));
	set("no_clean_up", 0);
	set("outdoors", "path2");
	setup();
/*�˶δ����� PLAYERHOME_D �Զ�����,����ı������κ�����!!*/
	create_door("north", "ľ��", "south", DOOR_CLOSED,LOCKED,"/d/phome/path2/wuhao_key");
/*�����Զ��������.*/

	replace_program(ROOM);
}