
/*�˶δ����� PLAYERHOME_D �Զ�����,����ı������κ�����!!*/
#include <room.h>
/*�����Զ��������.*/
// Room: /u/w/wangs/b/kai134.c

inherit ROOM;

void create()
{
	set("short", "С��԰");
	set("long", @LONG
����ǿ���ǵ�С��԰�ˡ���԰��������Ǻܴ󣬵�̨ͤ¥
�󣬼�ɽ����ȴҲ���еġ����������ؼ򵥣������ݻ���һ����
����СϪͨ��С��԰������⣬Ϫˮ�������ˣ����˵ķ�������
���ƺ�����ʧ�ˡ�Ϧ������ʱ���е��������ǵ�����ɢ��������
С��
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([
/*�˶δ����� PLAYERHOME_D �Զ�����,����ı������κ�����!!*/
	"north" : "/d/phome/kaifeng/fatcatd_home",
/*�����Զ��������.*/
 /* sizeof() == 1 */
  "east" : __DIR__"kai133",
]));

	set("outdoors","kaifeng");
	setup();
/*�˶δ����� PLAYERHOME_D �Զ�����,����ı������κ�����!!*/
	create_door("north", "�������", "south", DOOR_CLOSED,LOCKED,"/d/phome/kaifeng/fatcatd_key");
/*�����Զ��������.*/

	replace_program(ROOM);
}
